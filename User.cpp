#include "User.h"
#include "Date_providers.h"
#include "Error.h"

///Constructor de initializare - users
User::User(const Credentials &creds_, const std::string &first_name_, const std::string &last_name_,
           const std::string &bank_account_, const std::string& phoneNumber_) : Account(creds_,first_name_,last_name_,bank_account_), phoneNumber(phoneNumber_){
    std::cout << "Constr de init User\n";
}

///Operatorul <<
std::ostream &operator<<(std::ostream &os, const User &user) {
    os << static_cast<const Account &>(user) << "\nphoneNumber: " << user.phoneNumber <<"\n";
    os << "\nSubscriptions: \n";
    int k = 0;
    for (const Subscription &sub: user.subscriptions) {
        os << "Subscription no" << ++k << "\n";
        os << sub;
    }
    return os;
}

///virtual-conf. account
void User::confirmAccount() {
    std::cout<<"Would you like to confirm account for user: "<<creds.getUsername()<<"? Y/N";
    std::string ans;
    std::cin>>ans;
    if(ans[0] == 'Y'){
        std::cout<<"User confirmation successful!\n";
        float money;
        std::cout<<"How much money would you like to add to your account?";
        std::cin>>money;
        this->setBankBalance(money);
        confirmed = true;
    }
    else if(ans[0] == 'N') std::cout<<"User confirmation canceled\n";
    else std::cout<<"Wrong input\n";
}

///Clonare
std::shared_ptr<Account> User::clone()const {
    std::cout<<"CLONAUSER\n";
    return std::make_shared<User>(*this);
}

///Getter phonenumber
const std::string &User::getPhoneNumber() const {
    return phoneNumber;
}

///Adaugare subsciption
void User::addSubscription(const std::shared_ptr<Account>& provider_, const std::string &start_date_, const std::string &end_date_,
                           const std::string &type_, int price_) {
    try {
        if(!dynamic_cast<Account &>(*this).isConfirmed())
            throw(confirmedError{"Error: user is not confirmed!\n"});
        if(!provider_->isConfirmed())
            throw(confirmedError("Error: provider is not confirmed!\n"));
        dynamic_cast<Provider &>(*provider_).addSubscribers(creds.getUsername());
        Subscription s_aux{provider_, start_date_, end_date_, type_, price_};
        subscriptions.push_back(s_aux);
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
}

///Anulare subsciption
void User::cancelSubscription(const std::string &provider_name_) {
    try {
        if(!dynamic_cast<Account &>(*this).isConfirmed())
            throw(confirmedError{"Error: user is not confirmed!\n"});
        int k = 0;
        for (const Subscription &sub: subscriptions) {
            if (sub.getProvider()->getCreds().getUsername() == provider_name_) {
                subscriptions.erase(subscriptions.begin() + k);
                std::cout << "Canceled subscription for: " << provider_name_ << "\n";
                break;
            }
            k++;
        }
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
}
///Destr user
User::~User() {
    std::cout<<"Destr user\n";
}
