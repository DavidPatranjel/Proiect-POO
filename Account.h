#ifndef PROIECT1_POO_ACCOUNT_H
#define PROIECT1_POO_ACCOUNT_H
#include <string>
#include <ostream>
#include <memory>
#include "Credentials.h"

class Account {
protected:
    Credentials creds;
    std::string first_name;
    std::string last_name;
    std::string bank_account;
    float bank_balance = 0;
    bool confirmed = false;

    ///Clonarea
    Account(const Account&) = default;
    Account & operator=(const Account& ac) = default;
public:
    ///Constructor de initializare - account
    Account(const Credentials &creds_, const std::string &first_name_, const std::string &last_name_, const std::string &bank_account_);

    ///virtual-conf. account
    virtual void confirmAccount() = 0;

    ///Getter - creds
    [[nodiscard]] const Credentials &getCreds() const;

    ///Getter - confirmed
    [[nodiscard]] bool isConfirmed() const;

    ///Setter - bankBalance
    void setBankBalance(float bankBalance);

    ///Change password
    void callChangePasswordAccount(const std::string &new_password_);

    ///Op<< + afisare
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
    virtual void afisare(std::ostream &os) const;

    ///Clonarea
    [[nodiscard]] virtual std::shared_ptr<Account> clone() const = 0;

    ///Destructor virtual pur
    virtual ~Account() = 0;
};

#endif