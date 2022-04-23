#include "Date_users.h"
#include "User.h"

///Swap
void swap(Date_users &c1, Date_users &c2) {
    std::swap(c1.users, c2.users);
}

///Constructor de copiere
Date_users::Date_users(const Date_users &other) {
    for(const auto& a:other.users){
        users.push_back(static_cast<const std::shared_ptr<Account>>(a->clone()));
    }
}

///Operatorul =
Date_users &Date_users::operator=(const Date_users &other) {
    auto copie{other};
    swap(*this, copie);
    return *this;
}

///Constructor de init
Date_users::Date_users(std::vector<std::shared_ptr<Account>> users) : users(std::move(users)) {}

///Operatorul <<
std::ostream &operator<<(std::ostream &os, const Date_users &data_user_) {
    int k = 0;
    for(auto& i:data_user_.users) {
        os << "User: " <<++k<<"\n" << dynamic_cast<const User &>(*i);
    }
    return os;
}

///Gasirea userului
int Date_users::findUserConfirmation(const std::string& phone_number_) {
    int k = 0;
    for(auto& i:users){
        if(dynamic_cast<const User &>(*i).getPhoneNumber() == phone_number_){
            return k;
        }
        k++;
    }
    return -1;
}

int Date_users::findUser(const std::string& username_) {
    int k = 0;
    for(auto& i:users){
        if(i->getCreds().getUsername() == username_){
            return k;
        }
        k++;
    }
    return -1;
}

///Operatorul []
std::shared_ptr<Account> Date_users::operator[](int i) {
    return users[i];
}
