#ifndef   SERVER_HPP
#define   SERVER_HPP

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string>
#include <array>
#include <algorithm>


class ServerHandler
{   
    private:
        int server_fd; 
        int client_socket_fd;
        std::array<char,5000> buffer;


    public:
        ServerHandler();
        ~ServerHandler();
        bool server_init();
        bool server_listen();
        bool server_accept();
        bool server_send(const std::string &message);
        std::string server_read();
        void close_listening();
        void close_listening_client();
        void server_close();

};

















#endif 

