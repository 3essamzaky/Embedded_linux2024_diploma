#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// HttpRequest class
class HttpRequest {
public:
    HttpRequest(const std::string &method, const std::string &url, const std::string &headers, const std::string &body)
        : method(method), url(url), headers(headers), body(body) {}

    void Send() const {
        // Create a socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            std::cerr << "Could not create socket\n";
            return;
        }

        // Resolve the server address and port
        struct sockaddr_in server;
        server.sin_addr.s_addr = inet_addr("93.184.216.34"); // example.com IP
        server.sin_family = AF_INET;
        server.sin_port = htons(80); // HTTP port

        // Connect to the server
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            std::cerr << "Connection failed\n";
            close(sock);
            return;
        }

        // Prepare the HTTP request message
        std::stringstream requestStream;
        requestStream << method << " " << url << " HTTP/1.1\r\n";
        requestStream << "Host: example.com\r\n";
        requestStream << headers << "\r\n";
        requestStream << "Content-Length: " << body.length() << "\r\n";
        requestStream << "\r\n";
        requestStream << body;

        std::string request = requestStream.str();

        // Send the request
        if (send(sock, request.c_str(), request.size(), 0) < 0) {
            std::cerr << "Send failed\n";
            close(sock);
            return;
        }

        // Receive the response
        char buffer[4096];
        std::string response;
        while (true) {
            int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
            if (bytesReceived <= 0) break;
            response.append(buffer, bytesReceived);
        }

        // Print the response
        std::cout << "Response:\n" << response << "\n";

        // Close the socket
        close(sock);
    }

private:
    std::string method;
    std::string url;
    std::string headers;
    std::string body;

    friend class HttpRequestBuilder; // Allow the builder to access private members
};

// Builder class
class HttpRequestBuilder {
public:
    HttpRequestBuilder &setMethod(const std::string &method) {
        this->method = method;
        return *this;
    }

    HttpRequestBuilder &setUrl(const std::string &url) {
        this->url = url;
        return *this;
    }

    HttpRequestBuilder &setHeaders(const std::string &headers) {
        this->headers = headers;
        return *this;
    }

    HttpRequestBuilder &setBody(const std::string &body) {
        this->body = body;
        return *this;
    }

    HttpRequest build() const {
        return HttpRequest(method, url, headers, body);
    }

private:
    std::string method = "GET"; // Default method
    std::string url = "/";
    std::string headers = "";
    std::string body = "";
};

int main() {
    // Constructing an HTTP request using the builder
    HttpRequest request = HttpRequestBuilder()
        .setMethod("POST")
        .setUrl("/api/data")
        .setHeaders("Content-Type: application/json")
        .setBody(R"({"key": "value"})")
        .build();

    // Send the HTTP request
    request.Send();

    return 0;
}