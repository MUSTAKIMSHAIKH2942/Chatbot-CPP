
#include "Factory.hpp"

std::shared_ptr<User> Factory::createUser(const std::string& nickname) {
    return std::make_shared<User>(nickname);
}
