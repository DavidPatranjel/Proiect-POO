#include <iostream>
#include <vector>

class Subscription{
    std::string start_date;
    std::string end_date;
    std::string type;
    int price;
public:
    ///Constructor initializare - subsscription
    Subscription(const std::string& start_date_, const std::string& end_date_, const std::string& type_, int price_) :
            start_date{start_date_}, end_date{end_date_}, type{type_}, price{price_}{
        std::cout << "Constr de initializare Subscription\n";
    }
    ///Operatorul << - subsscription
    friend std::ostream& operator<<(std::ostream& os, const Subscription& sb) {
        os << "Start date: " << sb.start_date << ", end date: " << sb.end_date << ", type subscription: " << sb.type << ", price: " << sb.price <<"\n";
        return os;
    }
    ///Geters - subscription
    const std::string& getStartDate() const{ return start_date;}
    const std::string& getEndDate() const{ return end_date;}
    const std::string& getType() const{ return type;}
    int getPrice() const{ return price;}

    ///Setters - subscription
    void setStartDate(const std::string& start_date_) {start_date = start_date_;}
    void setEndDate(const std::string& end_date_) {end_date = end_date_;}
    void setType(const std::string& type_) {type = type_;}
    void setPrice(int price_) {price = price_;}

    ///Operator= de copiere - subscription
    Subscription& operator=(const Subscription& other) {
        start_date = other.start_date;
        start_date = other.start_date;
        start_date = other.start_date;
        price = other.price;
        std::cout << "operator= copiere subcr\n";
        return *this;
    }

    ///Constructor de copiere - subscription
    Subscription(const Subscription& other) : start_date{other.start_date}, end_date{other.end_date}, type{other.type}, price{other.price} {
        std::cout << "Constr de copiere subcr\n";
    }
    ///Destructor - subscription
    ~Subscription(){
        std::cout << "Destr Subscription\n";
    }
};

class Credentials{
    std::string username;
    std::string password;
public:
    ///Constructor de initializare - credentiale
    Credentials(const std::string& username_, const std::string& password_) :
            username{username_}, password{password_}{
        std::cout << "Constr de initializare Credentiale\n";
    }
    ///Operatorul << - credentiale
    friend std::ostream& operator<<(std::ostream& os, const Credentials& cr) {
        os << "Username: " << cr.username << ", password: " << cr.password << "\n";
        return os;
    }
};

class User{
    Credentials c;
    Subscription s;
    std::string first_name;
    std::string last_name;
    std::string description;
    std::string bank_account;
public:
    ///Constructor de initializare - users
    User(const std::string& username,const std::string& password, const std::string& first_name_, const std::string& last_name_, const std::string& description_, const std::string& bank_account_) :
            c{username, password}, s{"", "", "", 0}, first_name{first_name_},  last_name{last_name_}, description{description_}, bank_account{bank_account_} {
        std::cout << "Constr de initializare User\n";
    }
    ///Operatorul << - user
    friend std::ostream& operator<<(std::ostream& os, const User& us) {
        os << "First name: " << us.first_name << ", last name: " << us.last_name << ", description: " << us.description << ", bank account: " << us.bank_account << "\n";
        os<<us.s;
        return os;
    }
    ///Setter - subscription of user
    void setSubscription(const std::string& start_date_, const std::string& end_date_, const std::string& type_, int price_){
        s.setStartDate(start_date_);
        s.setEndDate(end_date_);
        s.setType(type_);
        s.setPrice(price_);
    }
};

class Provider{
    User u;
    std::vector<std::string> content;
    std::vector<std::string> subscribers;
public:
    ///Constructor de initializare - provider
    Provider(const std::string& username,const std::string& password, const std::string& first_name_, const std::string& last_name_, const std::string& description_, const std::string& bank_account_) :
            u{username,password,first_name_,last_name_,description_,bank_account_} {
        std::cout<<"Constr de initializare Provider\n";
    }
    ///Operatorul << - provider
    friend std::ostream& operator<<(std::ostream& os, const Provider& pr) {
        os << pr.u << "Content: ";
        for (std::string co:pr.content) {
            os << co << " ";
        }
        os << ", subscribers: ";
        for (std::string co:pr.subscribers) {
            os << co << " ";
        }
        os<<"\n";
        return os;
    }
    ///Setter - subscription
    void setSubscription(const std::string& start_date_, const std::string& end_date_, const std::string& type_, int price_){
        u.setSubscription(start_date_, end_date_, type_, price_);
    }
};

int main(){
    Provider p1{"dave24", "parola", "David", "Patranjel", "Geniu", "Banca Transolvania"};
    std::cout<<p1;
    p1.setSubscription("24-aprilie-2022", "30-mai-2022", "lunar", 100);
    std::cout<<p1;
    return 0;
}