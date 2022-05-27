#ifndef PROIECT1_POO_PROVIDER_H
#define PROIECT1_POO_PROVIDER_H


#include <string>
#include <vector>
#include <ostream>
#include <memory>
#include "Credentials.h"
#include "Account.h"
#include "Security.h"

class Provider:public Account{
    Security<int> backup;
    std::string description;
    std::string cui;
    std::vector<std::string> content;
    std::vector<std::string> subscribers;
public:
    ///Constructor de initializare - provider
    Provider(const Credentials& creds_, const std::string& first_name_, const std::string& last_name_, int q1, int q2,
             const std::string& description_, const std::string& bank_account_, const std::string& cui_);

    ///Afisare
    void afisare(std::ostream &os) const override;
    ///virtual-conf. account
    void confirmAccount() override;

    ///CLONARE
    [[nodiscard]] std::shared_ptr<Account> clone() const override;

    ///Getter CUI
    [[nodiscard]] const std::string &getCui() const;

    ///Adaugare subscriber
    void addSubscribers(const std::string& username_);

    ///Stergere subscriber
    void delSubscribers(const std::string& username_);

    ///Backup provider
    void recoverCredentials(int q1, int q2);

    ///Destr provider
    ~Provider() override;
};


#endif
