
#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "User.hpp"
#include <memory>

class Factory {
public:
    static std::shared_ptr<User> createUser(const std::string& nickname);
};

#endif
