
#include "Client.hpp"
#include "Server.hpp"
#include "Factory.hpp"
#include <iostream>

int main() {
    std::cout << "Start as (1) Server or (2) Client: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        runServer(8080);
    } else {
        std::string ip, nickname;
        std::cout << "Enter server IP: ";
        std::cin >> ip;
        std::cin.ignore();
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
        auto user = Factory::createUser(nickname);
        std::cout << "Nickname set: " << user->getNickname() << std::endl;
        runClient(ip, 8080);
    }
}
