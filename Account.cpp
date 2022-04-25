#include "Account.h"
#include "Error.h"

///Constructor de initializare - account
Account::Account(const Credentials &creds_, const std::string &first_name_, const std::string &last_name_,
                 const std::string &bank_account_) :
        creds{creds_}, first_name{first_name_},  last_name{last_name_}, bank_account{bank_account_} {
    std::cout << "Constr de init Account\n";
}

///getter creds
const Credentials &Account::getCreds() const {
    return creds;
}

///getter confirmed
bool Account::isConfirmed() const {
    return confirmed;
}

///Setter - bankBalance
void Account::setBankBalance(float bankBalance) {
    bank_balance = bankBalance;
}

///operatorul <<
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << account.creds << "first_name: " << account.first_name << " last_name: " << account.last_name
       << " bank_account: " << account.bank_account << " bank_balance: " << account.bank_balance << " confirmed: "
       << account.confirmed;
    return os;
}
///apeleaza schimbarea de parola
void Account::callChangePasswordAccount(const std::string &new_password_) {
    try{
        if(!this->isConfirmed())
            throw(confirmedError{"Error: user is not confirmed!\n"});
        creds.changePassword(new_password_);
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
}

///Destructor virtual pur
Account::~Account(){
    std::cout<<"Destr virt pur account\n";
}
