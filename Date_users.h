#ifndef PROIECT1_POO_DATE_USERS_H
#define PROIECT1_POO_DATE_USERS_H
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include "Account.h"
#include "User.h"


class Date_users {
    std::vector<std::shared_ptr<Account>> users;
public:
    ///Swap
    friend void swap(Date_users & c1, Date_users &c2);

    ///Constructor de copiere
    Date_users(const Date_users& other);

    ///Operatorul =
    Date_users& operator=(const Date_users& other);

    ///Constructor de init
    explicit Date_users(std::vector<std::shared_ptr<Account>> users);

    ///Operatorul <<
    friend std::ostream &operator<<(std::ostream &os, const Date_users &data_user_);

    ///Gasirea unerului
    int findUserConfirmation(std::string const& phone_number_);
    int findUser(std::string const& username_);

    ///Operatorul []
    std::shared_ptr<Account> operator[](int i);
};


#endif
