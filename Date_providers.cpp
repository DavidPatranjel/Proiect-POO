#include "Date_providers.h"
#include "Provider.h"
#include "Error.h"

///Swap
void swap(Date_providers &c1, Date_providers &c2) {
    std::swap(c1.providers, c2.providers);
}

///Constructor de copiere
Date_providers::Date_providers(const Date_providers &other) {
    for(const auto& a:other.providers){
        providers.push_back(a->clone());
    }
}

///Operator =
Date_providers &Date_providers::operator=(const Date_providers &other) {
    Date_providers copie{other};
    swap(*this, copie);
    return *this;
}

///Constructor de init
Date_providers::Date_providers(std::vector<std::shared_ptr<Account>> providers) : providers(std::move(providers)) {}

///Operator <<
std::ostream &operator<<(std::ostream &os, const Date_providers &data_providers_) {
    int k = 0;
    for(auto& i:data_providers_.providers) {
        os << "\nProvider: " <<++k<<"\n"<< dynamic_cast<const Provider &>(*i);
    }
    return os;
}

///Gasirea providerului
int Date_providers::findProviderConfirmation(const std::string& cui_) {
    int k = 0;
    for(auto& i:providers){
        if(dynamic_cast<const Provider &>(*i).getCui() == cui_){
            return k;
        }
        k++;
    }
    return -1;
}

int Date_providers::findProvider(const std::string& username_) {
    int k = 0;
    for(auto& i:providers){
        if(i->getCreds().getUsername() == username_){
            return k;
        }
        k++;
    }
    return -1;
}

int Date_providers::findSubscriptionAndDelete(const std::string& username_user_, const std::string& username_provider_) {
    try {
        int k = (*this).findProvider(username_provider_);
        if(k == -1) throw(findError("Error: can't find this provider!\n"));
        if(dynamic_cast<Provider &>(*providers[k]).delSubscribers(username_user_))
            return 1;
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
    std::cout<<"Error: cant find provider!";
    return 0;
}

///Operator []
std::shared_ptr<Account> Date_providers::operator[](int i) {
    return providers[i];
}
