#ifndef PROIECT1_POO_DATE_PROVIDERS_H
#define PROIECT1_POO_DATE_PROVIDERS_H

#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include "Account.h"

class Date_providers {
    std::vector<std::shared_ptr<Account>> providers;
public:
    ///Swap
    friend void swap(Date_providers & c1, Date_providers &c2);

    ///Constructor de copiere
    Date_providers(const Date_providers& other);

    ///Operator =
    Date_providers& operator=(const Date_providers& other);

    ///Operatorul de init
    explicit Date_providers(std::vector<std::shared_ptr<Account>> providers);

    ///Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Date_providers &data_providers_);

    ///Gasirea providerului
    int findProviderConfirmation(std::string const& cui_);
    int findProvider(std::string const& username_);
    int findSubscriptionAndDelete(const std::string& username_user_, const std::string& username_provider_);
    ///Operator []
    std::shared_ptr<Account> operator[](int i);

};


#endif
