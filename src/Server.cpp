
#include "Server.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

void handleClient(int clientSocket) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytes <= 0) break;
        std::cout << "Client: " << buffer;
        send(clientSocket, buffer, bytes, 0);  // Echo back
    }
    close(clientSocket);
}

void runServer(int port) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr = {AF_INET, htons(port), INADDR_ANY};

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
    std::cout << "Server listening on port " << port << std::endl;

    while (true) {
        sockaddr_in clientAddr;
        socklen_t len = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &len);
        std::thread(handleClient, clientSocket).detach();
    }
}
