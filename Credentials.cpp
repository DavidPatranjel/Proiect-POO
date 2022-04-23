#include "Credentials.h"

///Constructor de initializare - credentiale
Credentials::Credentials(const std::string &username_, const std::string &password_) :
        username{username_}, password{password_}{
    std::cout << "Constr de initializare Credentiale\n";
}

///Operatorul << - credentiale
std::ostream &operator<<(std::ostream &os, const Credentials &cr) {
    os << "Username: " << cr.username << ", password: " << cr.password << "\n";
    return os;
}

///Schimbare parola
void Credentials::changePassword(const std::string &new_password_) {
    if (new_password_ == password)
        std::cout << "Error: old password is the same as the new password.\n";
    else {
        std::cout << "Password changed successfully\n";
        password = new_password_;
    }
}

///Getter
const std::string &Credentials::getUsername() const {return username;}
