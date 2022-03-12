#include <iostream>
#include <vector>

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
    ///Schimbare parola
    void changePassword(const std::string& new_password_) {
        if (new_password_ == password)
            std::cout << "Error: old password is the same as the new password.\n";
        else {
            std::cout << "Password changed successfully\n";
            password = new_password_;
        }
    }
    ///Getter
    const std::string &getUsername() const {return username;}
};
class Provider{
    Credentials c;
    std::string first_name;
    std::string last_name;
    std::string description;
    std::string bank_account;
    float bank_balance;
    std::vector<std::string> content;
    std::vector<std::string> subscribers;
public:
    ///Constructor de initializare - provider
    /*Provider(const std::string& username_,const std::string& password_, const std::string& first_name_, const std::string& last_name_, const std::string& description_, const std::string& bank_account_, float bank_balance_):
            c{username_, password_}, first_name{first_name_}, last_name{last_name_}, description{description_}, bank_account{bank_account_}, bank_balance{bank_balance_}{
        std::cout << "Constr init provider\n";
    }*/
    Provider(const Credentials& c_, const std::string& first_name_, const std::string& last_name_, const std::string& description_, const std::string& bank_account_, float bank_balance_):
            c{c_}, first_name{first_name_}, last_name{last_name_}, description{description_}, bank_account{bank_account_}, bank_balance{bank_balance_}{
        std::cout << "Constr init provider\n";
    }
    ///Operatorul << - provider
    friend std::ostream& operator<<(std::ostream& os, const Provider& pr) {
        os << pr.c << "First name: " << pr.first_name << ", last name: " << pr.last_name << ", descriere: "
           << pr.description << ", bank account: " << pr.bank_account << ", bank balance: " << pr.bank_balance
           << "\nContent: ";
        for (const std::string& i: pr.content) {
            os << i << " ";
        }
        os << ", subscribers: ";
        for (const std::string& i: pr.subscribers) {
            os << i << " ";
        }
        os << "\n";
        return os;
    }
    ///Getter
    const Credentials &getCredentials() const {return c;}

    ///Apel la schimbare de parola
    void callChangePasswordProvider(const std::string& new_password_/*, std::vector<User>& us*/){
        c.changePassword(new_password_);
    }

    ///Adaugare subscriber
    void addSubscribers(const std::string& username_){
        subscribers.push_back(username_);
    }

    ///Stergere subscriber
    void delSubscribers(const std::string& username_){
        int k = 0;
        for(const std::string& i:subscribers){
            if(i == username_){
                subscribers.erase(subscribers.begin()+k);
                return;
            }
            k++;
        }
    }
};
class Subscription{
    Provider p;
    std::string start_date;
    std::string end_date;
    std::string type;
    int price;
public:
    ///Constructor initializare - subsscription
    Subscription(const Provider& p_, const std::string& start_date_ = "", const std::string& end_date_ = "", const std::string& type_ = "", int price_ = 0) :
            p{p_}, start_date{start_date_}, end_date{end_date_}, type{type_}, price{price_}{
        std::cout << "Constr de initializare Subscription\n";
    }
    ///Operatorul << - subsscription
    friend std::ostream& operator<<(std::ostream& os, const Subscription& sb) {
        os << sb.p;
        os << "Start date: " << sb.start_date << ", end date: " << sb.end_date << ", type subscription: " << sb.type << ", price: " << sb.price <<"\n";
        return os;
    }
    ///Operator= de copiere - subscription
    Subscription& operator=(const Subscription& other) {
        p = other.p;
        start_date = other.start_date;
        end_date = other.end_date;
        type = other.type;
        price = other.price;
        std::cout << "operator= copiere subcr\n";
        return *this;
    }
    ///Constructor de copiere - subscription
    Subscription(const Subscription& other) : p{other.p}, start_date{other.start_date}, end_date{other.end_date}, type{other.type}, price{other.price}{
        std::cout << "Constr de copiere subcr\n";
    }
    ///Destructor - subscription
    ~Subscription(){
        std::cout << "Destr Subscription\n";
    }
    ///Getter
    const Provider &getProvider() const {return p;}
};

class User{
    Credentials c;
    std::vector<Subscription> s;
    std::string first_name;
    std::string last_name;
    std::string bank_account;
    float bank_balance;
public:
    ///Constructor de initializare - users
    User(const Credentials& c_, const std::string& first_name_, const std::string& last_name_, const std::string& bank_account_, float bank_balance_) :
        c{c_}, first_name{first_name_},  last_name{last_name_}, bank_account{bank_account_}, bank_balance{bank_balance_} {
        std::cout << "Constr de init User\n";
    }
    ///Operatorul << - user
    friend std::ostream& operator<<(std::ostream& os, const User& us) {
        os <<us.c<< "First name: " << us.first_name << ", last name: " << us.last_name << ", bank account: " << us.bank_account << ", bank balance: "<<us.bank_balance<<"\n";
        os << "Subscriptions: \n";
        int  k = 0;
        for(const Subscription& i:us.s){
            os << "Subscription no" << ++k << "\n";
            os << i;
        }
        return os;
    }

    ///Apel schimbare de parola
    void callChangePasswordUser(const std::string& new_password_){
        c.changePassword(new_password_);
    }

    ///Adaugare subsciption
    void addSubscription(Provider& p_, const std::string& start_date_,const  std::string& end_date_, const std::string& type_, int price_){
        p_.addSubscribers(c.getUsername());
        Subscription s_aux{p_, start_date_, end_date_, type_, price_};
        s.push_back(s_aux);
    }

    ///Anulare subsciption
    void cancelSubscription(const std::string& provider_name_, std::vector<Provider>& pr){
        int k = 0;
        for(const Subscription& i:s){
            if(i.getProvider().getCredentials().getUsername() == provider_name_){
                s.erase(s.begin()+k);
                std::cout<<"Canceled subscription for: "<<provider_name_<<"\n";
                k = 0;
                for(const Provider& j:pr){
                    if(j.getCredentials().getUsername() == provider_name_){
                        pr[k].delSubscribers(c.getUsername());
                        return;
                    }
                    k++;
                }
            }
            k++;
        }
        std::cout<<"Error: Subscription not found!\n";
    }
};

int main(){
    std::vector<User> users;
    std::vector<Provider> providers;
    ///Test provider + credentials
    std::cout<<std::endl<<"PROVIDERS TEST"<<std::endl<<std::endl;
    Credentials c1{"dave", "parola"},c2{"ana123","parolaparola"};
    Provider p1{c1, "David", "Patranjel", "the best yt videos", "IBAN1324", 2040};
    Provider p2{c2, "Ana", "Ionescu", "the worst yt videos", "IBAN5555", 1220};
    providers.push_back(p1);
    providers.push_back(p2);
    for(const Provider& i:providers){
        std::cout<<i;
    }
    ///Test user
    std::cout<<std::endl<<"USERS TEST"<<std::endl<<std::endl;
    Credentials c3{"ionpopescu22", "parola123"},c4{"danvoiculescu33","password111"};
    User u1{c3, "Ion", "Popescu", "Garanti", 2000};
    User u2{c4, "Dan", "Voiculescu", "Revolut", 3655.23};
    users.push_back(u1);
    users.push_back(u2);
    for(const User& i:users){
        std::cout<<i;
    }
    ///Test subscription
    std::cout<<std::endl<<"SUBSCRIPTION TEST"<<std::endl<<std::endl;
    Subscription s1{providers[0], "20.01.2020", "20.01.2021", "anual", 50};
    Subscription s2{providers[1], "30.03.2003", "30.04.2003", "lunar", 10},s3 = s1;
    std::cout<<s1<<s2<<s3;
    s3 = s2;
    s2 = s1;
    std::cout<<s2<<s3;
    ///Test schimbare parola
    std::cout<<std::endl<<"CHANGE PASSWORD TEST"<<std::endl<<std::endl;
    users[0].callChangePasswordUser("parola123");
    std::cout<<users[0];
    providers[0].callChangePasswordProvider("parolaparola");
    std::cout<<providers[0];
    ///Test abonament nou
    std::cout<<std::endl<<"NEW SUBS"<<std::endl<<std::endl;
    users[0].addSubscription(providers[0], "01.01.2005", "01.01.2006", "anual", 50);
    users[0].addSubscription(providers[1], "01.01.2006", "01.02.2008", "lunar", 20);
    users[1].addSubscription(providers[1], "03.05.2011", "03.06.2011", "lunar", 25);
    std::cout<<users[0]<<users[1]<<providers[1];
    ///Test cancel subs
    std::cout<<std::endl<<"CANCEL TEST"<<std::endl<<std::endl;
    users[0].cancelSubscription("ana123", providers);
    std::cout<<users[0]<<providers[1];
    return 0;
}