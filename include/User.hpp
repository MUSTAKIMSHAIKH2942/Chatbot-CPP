
#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
    std::string nickname;
public:
    User(const std::string& nick);
    std::string getNickname() const;
};

#endif
