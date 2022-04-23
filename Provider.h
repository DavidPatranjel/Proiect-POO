#ifndef PROIECT1_POO_PROVIDER_H
#define PROIECT1_POO_PROVIDER_H


#include <string>
#include <vector>
#include <ostream>
#include "Credentials.h"
#include "Account.h"

class Provider:public Account{
    std::string cui;
    std::string description;
    std::vector<std::string> content;
    std::vector<std::string> subscribers;
public:
    ///Constructor de initializare - provider
    Provider(const Credentials& creds_, const std::string& first_name_, const std::string& last_name_, const std::string& description_, const std::string& bank_account_, float bank_balance_, const std::string& cui_);

    ///Operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Provider &provider);

    ///virtual-conf. account
    void confirmAccount() override;

    ///CLONARE
    Account *clone() const override;

    ///Getter CUI
    const std::string &getCui() const;

    ///Adaugare subscriber
    void addSubscribers(const std::string& username_);

    ///Stergere subscriber
    int delSubscribers(const std::string& username_);
};


#endif
