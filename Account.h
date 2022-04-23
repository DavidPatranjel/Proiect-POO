#ifndef PROIECT1_POO_ACCOUNT_H
#define PROIECT1_POO_ACCOUNT_H
#include <string>
#include <ostream>
#include "Credentials.h"

class Account {
protected:
    Credentials creds;
    std::string first_name;
    std::string last_name;
    std::string bank_account;
    float bank_balance;
    bool confirmed = false;

    ///Clonarea
    Account(const Account&) = default;
    Account & operator=(const Account& ac) = default;
public:
    ///Constructor de initializare - account
    Account(const Credentials &creds_, const std::string &first_name_, const std::string &last_name_, const std::string &bank_account_, float bank_balance_);

    ///virtual-conf. account
    virtual void confirmAccount() = 0;

    ///Getter - creds
    [[nodiscard]] const Credentials &getCreds() const;

    ///Change password
    void callChangePasswordAccount(const std::string &new_password_);

    ///Op<<
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

    ///Clonarea
    [[nodiscard]] virtual Account* clone() const = 0;
};

#endif