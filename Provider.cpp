#include "Provider.h"
#include "Error.h"

///Constructor de initializare - provider
Provider::Provider(const Credentials &creds_, const std::string &first_name_, const std::string &last_name_,
                   const std::string &description_, const std::string &bank_account_, const std::string& cui_) :
        Account(creds_,first_name_,last_name_,bank_account_), description{description_}, cui{cui_}{
    std::cout << "Constr init provider\n";
}

///Operatorul <<
std::ostream &operator<<(std::ostream &os, const Provider &provider) {
    os << static_cast<const Account &>(provider) << "\ncui: " << provider.cui << " description: " << provider.description<< "\nContent: ";
    for (const std::string& post: provider.content) {
        os << post << " ";
    }
    os << ", subscribers: ";
    for (const std::string& sub: provider.subscribers) {
        os << sub << " ";
    }
    os << "\n";
    return os;
}

///virtual-conf. account
void Provider::confirmAccount(){
    std::cout<<"Would you like to confirm account for provider: "<<creds.getUsername()<<"? Y/N: ";
    std::string ans;
    std::cin>>ans;
    if(ans[0] == 'Y'){
        std::cout<<"Provider confirmation successful!\n";
        this->setBankBalance(0);
        confirmed = true;
    }
    else if(ans[0] == 'N') std::cout<<"Provider confirmation canceled\n";
    else std::cout<<"Provider input\n";
}

///Clonare
std::shared_ptr<Account> Provider::clone () const{
    std::cout<<"CLONAPROVIDER\n";
    return std::make_shared<Provider>(*this);
}

///Getter CUI
const std::string &Provider::getCui() const {
    return cui;
}

///Adaugare subscriber
void Provider::addSubscribers(const std::string &username_) {
    subscribers.push_back(username_);
}
///Stergere subscriber
int Provider::delSubscribers(const std::string &username_) {
    try {
        int k = 0;
        for (const std::string &sub: subscribers) {
            if (sub == username_) {
                subscribers.erase(subscribers.begin() + k);
                return 1;
            }
            k++;
        }
        throw(subscriptionError("Error: can't find subscription!\n"));
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
    return 0;
}

///Destr provider
Provider::~Provider() {
    std::cout<<"Destr provider\n";
}
