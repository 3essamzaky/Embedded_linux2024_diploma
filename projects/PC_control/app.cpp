#include "command.hpp"  // Includes the Command class for executing various system commands
#include "server.hpp"   // Includes the ServerHandler class for handling server operations
#include <iostream>     // For input and output operations

int main() {

    ServerHandler server;  // Create an instance of the ServerHandler class to manage server operations
    Command cmd;           // Create an instance of the Command class to execute system commands
    std::string buffer;    // Buffer to store messages received from the client

    // Initialize the server and check if it was successful
    if(server.server_init() == false){
        return -1;  // Exit the program if the server initialization fails
    }

    // Put the server in listening mode and check if successful
    if(server.server_listen() == false){
        return -1;  // Exit if the server fails to start listening for connections
    }

    // Main loop to keep the server running and accepting new clients
    while(true){
        std::cout << "waiting for client" << std::endl;

        // Accept incoming client connections
        if(server.server_accept()){
            std::cout <<"client connecting " << std::endl;

            // Send a message to the client to prompt for a command
            server.server_send("Enter command to Execute : \n");

            // Inner loop to handle client commands
            while(true){
                // Read the client's command from the socket
                buffer = server.server_read();

                // Exit the inner loop if the client sends "exit"
                if(buffer == "exit"){
                    server.server_send("exit");
                    server.server_close();  // Close the client connection
                    break;
                }

                // Execute the corresponding command based on the client's input
                if(buffer == "terminal"){
                    buffer = cmd.openTerminal();  // Open a terminal
                    server.server_send(buffer);   // Send the result back to the client
                }
                if(buffer == "calculator"){
                    buffer = cmd.openCalculator();  // Open the calculator
                    server.server_send(buffer);
                }
                if(buffer == "vscode"){
                    buffer = cmd.openVScode();  // Open VSCode
                    server.server_send(buffer);
                }
                if(buffer == "folder"){
                    buffer = cmd.openFolder();  // Open the file explorer
                    server.server_send(buffer);
                }
                if(buffer == "shutdown"){
                    buffer = cmd.shutdown();  // Shutdown the system
                    server.server_send(buffer);
                }
                if(buffer == "reboot"){
                    buffer = cmd.reboot();  // Reboot the system
                    server.server_send(buffer);
                }
                if(buffer == "logout"){
                    buffer = cmd.logout();  // Logout the user
                    server.server_send(buffer);
                }
                if(buffer == "spotify"){
                    buffer = cmd.openspotify();  // Open Spotify
                    server.server_send(buffer);
                }
                if(buffer == "youtube"){
                    buffer = cmd.youtube();  // Open YouTube in the browser
                    server.server_send(buffer);
                }
                if(buffer == "linkedin"){
                    buffer = cmd.linkedin();  // Open LinkedIn in the browser
                    server.server_send(buffer);
                }
                if(buffer == "github"){
                    buffer = cmd.github();  // Open GitHub in the browser
                    server.server_send(buffer);
                }
                if(buffer == "chatgpt"){
                    buffer = cmd.chatgpt();  // Open ChatGPT in the browser
                    server.server_send(buffer);
                }
            }
        }
    }
}
