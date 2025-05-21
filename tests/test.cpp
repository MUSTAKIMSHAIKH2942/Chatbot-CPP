
#include "../include/Factory.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto user = Factory::createUser("TestUser");
    assert(user->getNickname() == "TestUser");
    std::cout << "Test Passed: User nickname is " << user->getNickname() << std::endl;
}
