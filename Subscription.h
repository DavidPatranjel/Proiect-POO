#ifndef PROIECT1_POO_SUBSCRIPTION_H
#define PROIECT1_POO_SUBSCRIPTION_H


#include <string>
#include <iostream>
#include <memory>
#include "Provider.h"

class Subscription{
    std::shared_ptr<Account> provider;
    std::string start_date;
    std::string end_date;
    std::string type;
    int price;
public:
    ///Constructor initializare - subsscription
    explicit Subscription(const std::shared_ptr<Account>& provider_, const std::string& start_date_ = "", const std::string& end_date_ = "", const std::string& type_ = "", int price_ = 0);
    ///Operatorul << - subsscription
    friend std::ostream& operator<<(std::ostream& os, const Subscription& sb);
    ///Operator= de copiere - subscription
    Subscription& operator=(const Subscription& other);
    ///Constructor de copiere - subscription
    Subscription(const Subscription& other);
    ///Destructor - subscription
    ~Subscription();
    ///Getter
    [[nodiscard]] const std::shared_ptr<Account> &getProvider() const;
};


#endif
