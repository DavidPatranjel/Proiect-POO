#ifndef PROIECT1_POO_CREDENTIALS_H
#define PROIECT1_POO_CREDENTIALS_H


#include <string>
#include <iostream>
#include <vector>

class Credentials{
    std::string username;
    std::string password;
public:

    Credentials();
    ///Constructor de initializare - credentiale
    Credentials(const std::string& username_, const std::string& password_);
    ///Operatorul << - credentiale
    friend std::ostream& operator<<(std::ostream& os, const Credentials& cr);
    ///Schimbare parola
    void changePassword(const std::string& new_password_);
    ///Getter
    const std::string &getUsername() const;
};

#endif
