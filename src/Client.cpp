
#include "Client.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

void receiveMessages(int socket) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(socket, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;
        std::cout << "\rServer: " << buffer << "\n> ";
    }
}

void runClient(const std::string& ip, int port) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr = {AF_INET, htons(port), 0};
    inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr);

    connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    std::cout << "Connected to server.\n";

    std::thread(receiveMessages, clientSocket).detach();
    std::string msg;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, msg);
        send(clientSocket, msg.c_str(), msg.size(), 0);
    }
}
