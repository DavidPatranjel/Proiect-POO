#ifndef PROIECT1_POO_USER_H
#define PROIECT1_POO_USER_H


#include <string>
#include <vector>
#include <iostream>
#include "Provider.h"
#include "Credentials.h"
#include "Subscription.h"
#include "Account.h"
#include "Date_providers.h"
#include "Security.h"
#include "Error.h"

class User:public Account{
    Security<std::string> backup;
    std::string phoneNumber;
    std::vector<Subscription> subscriptions;
public:
    ///Constructor de initializare - users
    User(const Credentials& creds_, const std::string& first_name_, const std::string& last_name_, const std::string& bank_account_,const std::string& q1, const std::string& q2, const std::string& phoneNumber_);

    ///Afisare
    void afisare(std::ostream &os) const override;

    ///virtual-conf. account
    void confirmAccount() override;

    ///Clonare
    [[nodiscard]] std::shared_ptr<Account> clone() const override;

    ///Getter phonenumber
    [[nodiscard]] const std::string &getPhoneNumber() const;

    ///Adaugare subsciption
    void addSubscription(const std::shared_ptr<Account>& provider_, const std::string& start_date_,const  std::string& end_date_, const std::string& type_, int price_);

    ///Anulare subsciption
    void cancelSubscription(const std::string& provider_name_);

    ///Backup user
    void recoverCredentials(const std::string& q1, const std::string& q2);

    ///Destr user
    ~User() override;
};

#endif
