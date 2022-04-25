#include <string>
#include <vector>
#include "Usernames.h"

///Getter-usernames
const std::vector<std::string> &Usernames::getUsernames() const {
    return usernames;
}

///Setter-usernames
void Usernames::setUsernames(const std::vector<std::string> &usernames_) {
    Usernames::usernames = usernames_;
}
