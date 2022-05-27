#ifndef PROIECT1_POO_CREDENTIALS_H
#define PROIECT1_POO_CREDENTIALS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
class Credentials{
    std::string username;
    std::string password;
    friend class CredentialsBuilder;
public:
    Credentials() = default;
    ///Constructor de initializare - credentiale
    Credentials(const std::string& username_, const std::string& password_);
    ///Operatorul << - credentiale
    friend std::ostream& operator<<(std::ostream& os, const Credentials& cr);
    ///Schimbare parola
    void changePassword(const std::string& new_password_);
    ///Getter
    [[nodiscard]] const std::string &getUsername() const;
    [[nodiscard]] const std::string &getPassword() const;
};

class CredentialsBuilder{
private:
    bool hasUsername = false;
    Credentials cred;
public:
    CredentialsBuilder() = default;
    CredentialsBuilder& username(const std::string& u_);
    CredentialsBuilder& password(const std::string& p_);
    Credentials build();
};

class CredentialsFactory{
    static int contor;
public:
    static Credentials automat();
};

#endif
