#include "Account.h"
#include "Error.h"
const std::string salt = "?/Mp.3";
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

///operatorul << + afisare
std::ostream &operator<<(std::ostream &os, const Account &account) {
    account.afisare(os);
    return os;
}
void Account::afisare(std::ostream &os) const{
    const auto& account = *this;
    os << account.creds << "first_name: " << account.first_name << " last_name: " << account.last_name
       << " bank_account: " << account.bank_account << " bank_balance: " << account.bank_balance << " confirmed: "
       << account.confirmed;
}

///apeleaza schimbarea de parola
void Account::callChangePasswordAccount(const std::string &new_password_) {
    if(!this->isConfirmed())
        throw(confirmationError{"Error: user is not confirmed!\n"});
    std::hash<std::string> z;
    std::string aux;
    aux = std::to_string(z(new_password_ + salt));
    if(this->creds.getPassword() == aux)
        throw(passwordError{"Error: old password is the same as the new password!\n"});
    creds.changePassword(aux);
}

///Destructor virtual pur
Account::~Account(){
    std::cout<<"Destr virt pur account\n";
}
