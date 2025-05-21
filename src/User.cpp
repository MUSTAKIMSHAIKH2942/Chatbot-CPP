
#include "User.hpp"

User::User(const std::string& nick) : nickname(nick) {}

std::string User::getNickname() const {
    return nickname;
}
