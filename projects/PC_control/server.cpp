#include "server.hpp"

// Constructor for the ServerHandler class, initializes default values
ServerHandler::ServerHandler(){}

// Destructor for ServerHandler, ensures sockets are closed when the server is destroyed
ServerHandler::~ServerHandler(){
    if(server_fd != -1){
        // Close the server socket if it's open
        close(server_fd);
    }
    if(client_socket_fd != -1){
        // Close the client socket if it's open
        close(client_socket_fd);
    }
}

// Initializes the server by setting up the socket and binding it to an address
bool ServerHandler::server_init(){
    sockaddr_in sock_address;  // Structure to hold server address information

    // Create a socket with IPv4 (AF_INET) and TCP (SOCK_STREAM)
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd != -1){
        std::cout << "server socket : " << server_fd << std::endl;
    } else {
        // Error handling if socket creation fails
        std::cerr << "failed to create server socket" << std::endl;
        return -1;
    }

    // Configure the server address: IPv4, port 3000, listen on any available interface
    sock_address.sin_family = AF_INET;
    sock_address.sin_port = htons(3000);              // Convert port to network byte order
    sock_address.sin_addr.s_addr = htonl(INADDR_ANY);  // Bind to any available interface

    // Bind the socket to the address and port
    if(bind(server_fd, (sockaddr*)&sock_address, sizeof(sock_address)) != 0){
        std::cerr << "bind failed" << std::endl;
        close(server_fd);
        return -1;
    } else {
        std::cout << "binded" << std::endl;
    }
    return true;
}

// Puts the server in a state where it listens for incoming connections
bool ServerHandler::server_listen(){
    // Listen for incoming connections, with a backlog of 5
    if(listen(server_fd, 5) != 0){
        std::cerr << "listen failed" << std::endl;
        return -1;
    } else {
        std::cout << "listening" << std::endl;
    }
    return true;
}

// Accepts a client connection and returns a client socket
bool ServerHandler::server_accept(){
    sockaddr_in client;  // Structure to hold client address information
    socklen_t client_size = sizeof(client);

    // Accept an incoming connection from the client
    client_socket_fd = accept(server_fd, (sockaddr*)&client, &client_size);
    if(client_socket_fd != -1){
        std::cout << "client socket : " << client_socket_fd << std::endl;
    } else {
        std::cerr << "failed to accept client" << std::endl;
        return -1;
    }
    return true;
}

// Sends a message to the connected client
bool ServerHandler::server_send(const std::string &message){
    // Send the message to the client socket
    int bytes_sent = send(client_socket_fd, message.c_str(), message.size(), 0);
    std::cout << "sent message: " << message << std::endl;

    if(bytes_sent == -1){
        std::cerr << "failed to send" << std::endl;
        return -1;
    }
    return true;
}

// Reads a message from the client socket
std::string ServerHandler::server_read(){
    // Receive data from the client into the buffer
    ssize_t bytes_read = recv(client_socket_fd, static_cast<void*>(buffer.data()), buffer.size() - 1, 0);

    // Error handling for reading from the socket
    if(bytes_read == -1){
        return "ERROR READ";
    }
    // Connection closed by the client
    else if(bytes_read == 0){
        std::cerr << "connection closed" << std::endl;
        return "ERROR CLOSED";
    }
    // Data received successfully
    else {
        std::string str(buffer.data(), bytes_read);  // Create string from the buffer data
        std::cout << "receiving message: " << str << std::endl;
        return str;
    }
}

// Close the server listening socket
void ServerHandler::close_listening(){
    close(server_fd);
}

// Close the client connection socket
void ServerHandler::close_listening_client(){
    close(client_socket_fd);
}

// Close the client socket and reset its descriptor
void ServerHandler::server_close(){
    client_socket_fd = -1;  // Set the socket descriptor to an invalid state
    if(client_socket_fd != -1){
        close(client_socket_fd);
    }
}
