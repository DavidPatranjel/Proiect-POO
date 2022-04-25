#include "Subscription.h"

///Constructor initializare - subsscription
Subscription::Subscription(const std::shared_ptr<Account>& provider_, const std::string &start_date_, const std::string &end_date_,
                           const std::string &type_, int price_) :
        provider{provider_}, start_date{start_date_}, end_date{end_date_}, type{type_}, price{price_}{
    std::cout << "Constr de initializare Subscription\n";
}

///Operatorul << - subsscription
std::ostream &operator<<(std::ostream &os, const Subscription &sb) {
    os << "Provider: "<<sb.provider->getCreds().getUsername()<<"\n";
    os << "Start date: " << sb.start_date << ", end date: " << sb.end_date << ", type subscription: " << sb.type << ", price: " << sb.price <<"\n";
    return os;
}

///Operator= de copiere - subscription
Subscription &Subscription::operator=(const Subscription &other) {
    provider = other.provider;
    start_date = other.start_date;
    end_date = other.end_date;
    type = other.type;
    price = other.price;
    std::cout << "operator= copiere subcr\n";
    return *this;
}

///Constructor de copiere - subscription
Subscription::Subscription(const Subscription &other) : provider{other.provider}, start_date{other.start_date}, end_date{other.end_date}, type{other.type}, price{other.price}{
    std::cout << "Constr de copiere subcr\n";
}

///Destructor - subscription
Subscription::~Subscription() {
    std::cout << "Destr Subscription\n";
}

///Getter
const std::shared_ptr<Account> &Subscription::getProvider() const {
    return provider;
}