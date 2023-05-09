#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

class AppErr:public std::runtime_error{
public:
    explicit AppErr(const std::string& arg);;
};
AppErr::AppErr(const std::string &arg) : runtime_error(arg){}

class TicketTypeError:public AppErr{
public:
    explicit TicketTypeError(const std::string& arg);
};
TicketTypeError::TicketTypeError(const std::string &arg) : AppErr(arg){}

class MissingDataError:public AppErr{
public:
    explicit MissingDataError(const std::string& arg);
};
MissingDataError::MissingDataError(const std::string &arg) : AppErr(arg){}

class LookupError:public AppErr{
public:
    explicit LookupError(const std::string& arg);
};
LookupError::LookupError(const std::string &arg) : AppErr(arg){}

class Timp{
    int ora;
    int minut;
public:
    Timp() = default;
    Timp(int ora_, int minut_);
    friend int operator-(Timp t1, Timp t2);

};

Timp::Timp(int ora_, int minut_) : ora{ora_}, minut{minut_} {}
int operator-(Timp t1, Timp t2) {
    return t1.ora*60 - t2.ora*60 + t1.minut - t2.minut;
}

class Bilet{
protected:
    double pret;
    bool utilizat;
    Bilet(const Bilet&) = default;
    Bilet &operator=(const Bilet&) = default;
public:
    Bilet(double pret_): pret{pret_}, utilizat(false){};
    virtual ~Bilet() = default;
    virtual std::shared_ptr<Bilet> clone() = 0;
    virtual std::string veriftip() = 0;
};

class BiletSuprafata:public virtual Bilet{
public:
    BiletSuprafata(): Bilet{2}{};
    BiletSuprafata(double pret_): Bilet{pret_}{};
    ~BiletSuprafata() override = default;
    std::shared_ptr<Bilet> clone() override;
    std::string veriftip() override;
};
std::shared_ptr<Bilet> BiletSuprafata::clone() {
    return std::make_shared<BiletSuprafata>(*this);
}
std::string BiletSuprafata::veriftip() {
    return "suprafata";
}

class BiletMetrou:public virtual Bilet{
protected:
public:
    BiletMetrou(): Bilet{2.5}{};
    BiletMetrou(double pret_): Bilet(pret_){};
    ~BiletMetrou() override = default;
    std::shared_ptr<Bilet> clone() override;
    std::string veriftip() override;
};
std::shared_ptr<Bilet> BiletMetrou::clone() {
    return std::make_shared<BiletMetrou>(*this);
}
std::string BiletMetrou::veriftip() {
    return "metrou";
}

class BiletTranzit:public BiletSuprafata, public BiletMetrou{
    Timp timp;
public:
    BiletTranzit(int ora_, int minut_): Bilet(3), BiletMetrou(3), BiletSuprafata(3), timp{ora_ ,minut_}{};
    ~BiletTranzit() override = default;
    std::shared_ptr<Bilet> clone() override;
    std::string veriftip() override;

};
std::shared_ptr<Bilet> BiletTranzit::clone() {
    return std::make_shared<BiletTranzit>(*this);
}
std::string BiletTranzit::veriftip() {
    return "tranzit";
}

class Card{
protected:
    const int id;
    static int contor;
    std::string nume_titular;
    bool validat;
    std::vector<std::shared_ptr<Bilet>> bilete;
public:
    Card() = default;
    Card(const std::string &numeTitular_);
    virtual void addBilet(std::shared_ptr<Bilet> bilet) = 0;
    void setValidare(bool validat_);
    virtual ~Card() = default;
    friend std::ostream &operator<<(std::ostream &os, const Card &card);
    const int getId() const;
    bool isValidat() const;
};
int Card::contor = 0;
Card::Card(const std::string &numeTitular_)
: id{++contor}, nume_titular(numeTitular_), validat(false){}
void Card::setValidare(bool validat_) {
    validat = validat_;
}
std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << "Nr card: " << card.id << " nume_titular: " << card.nume_titular << " validat: " << card.validat;
    return os;
}
const int Card::getId() const {
    return id;
}
bool Card::isValidat() const {
    return validat;
}

class CardSS:public Card{
public:
    CardSS() = default;
    CardSS(const std::string &numeTitular_);
    void addBilet(std::shared_ptr<Bilet> bilet) override;
    ~CardSS() override = default;
};
CardSS::CardSS(const std::string &numeTitular_) :
Card{numeTitular_} {}
void CardSS::addBilet(std::shared_ptr<Bilet> bilet) {
    if(bilet->veriftip() != "suprafata" && bilet->veriftip() != "metrou") throw (TicketTypeError{"Error! Wrong ticket type!\n"});
    bilete.push_back(bilet);
    if (bilete.size() % 8 == 0) {
        bilete.push_back((bilet->clone()));
    }
}

class CardtR:public Card{
public:
    CardtR() = default;
    CardtR(const std::string &numeTitular_);
    void addBilet(std::shared_ptr<Bilet> bilet) override;
    ~CardtR() override = default;
};
CardtR::CardtR(const std::string &numeTitular_) : Card{numeTitular_} {}
void CardtR::addBilet(std::shared_ptr<Bilet> bilet) {
    if(bilet->veriftip() != "tranzit") throw (TicketTypeError{"Error! Wrong ticket type!\n"});
    bilete.push_back(bilet);
    if (bilete.size() % 8 == 0) {
        bilete.push_back((bilet->clone()));
    }
}

class Validator{
    std::string adresa;
public:
    Validator(const std::string &adresa_);
    Validator &operator=(const Validator& val);
    Validator(const Validator& val);
    void ValidareCard(std::shared_ptr<Card> card_);
    const std::string &getAdresa() const;
};

Validator::Validator(const std::string &adresa_) : adresa{adresa_} {}
Validator &Validator::operator=(const Validator &val) {
    adresa = val.adresa;
    return *this;
}
Validator::Validator(const Validator &val) :adresa{val.adresa}{}
void Validator::ValidareCard(std::shared_ptr<Card> card_) {
    card_->setValidare(true);
}
const std::string &Validator::getAdresa() const {
    return adresa;
}

class Aplicatie{
    Aplicatie() = default;
    std::vector<std::shared_ptr<Card>> carduri;
    std::vector<Validator> validatoare;
    Timp t1;
public:
    Aplicatie(const Aplicatie&) = delete;
    Aplicatie &operator=(const Aplicatie&) = delete;
    static Aplicatie& getapp(){
        static Aplicatie app;
        return app;
    }

    void creareCard(){
        std::shared_ptr<Card> c1 = std::make_shared<CardtR>("David");
        std::shared_ptr<Card> c2 = std::make_shared<CardSS>("Ion");
        carduri.push_back(c1); carduri.push_back(c2);
    }

    void creareAparat(){
        Validator v1("Iuliu Maniu");
        Validator v2("Titu Maiorescu");
        validatoare.push_back(v1);
        validatoare.push_back(v2);
    }

    void adaugareBilet(int id_card, std::shared_ptr<Bilet> bilet_){
        if(carduri.empty()) throw(MissingDataError{"Error! Nu exista carduri!\n"});
        for(auto& i:carduri){
            if(i->getId() == id_card){
                if(i->isValidat()) i->addBilet(bilet_);
                else throw(LookupError{"Error! Nu exista card confirmat cu acest id\n"});
                return;
            }
        }
        throw(LookupError{"Error! Nu exista card cu id =" + std::to_string(id_card) + "\n"});

    }

    void validareCard(int id_card, std::string adresa_){
        if(carduri.empty()) throw(MissingDataError{"Error! Nu exista carduri!\n"});
        for(auto& i:carduri){
            if(i->getId() == id_card){
                int ok = 1;
                for(auto j:validatoare){
                    if(j.getAdresa() == adresa_){
                        j.ValidareCard(i);
                        ok = 0;
                        return;
                    }
                }
                throw(LookupError{"Error! Nu exista validator cu adresa =" + adresa_ + "\n"});
            }
        }
        throw(LookupError{"Error! Nu exista card cu id =" + std::to_string(id_card) + "\n"});
    }

    void afisareCard(){
        if(carduri.empty()) throw(MissingDataError{"Error! Nu exista carduri\n!"});
        for(auto& i:carduri){
            std::cout<<*i<<std::endl;
        }
    }

    void ModificareTimp(int ora, int minut){
        Timp other_{ora, minut};
        t1 = other_;
    }

};

int main() {
    auto& app = Aplicatie::getapp();
    try{
        app.creareCard();
        app.creareAparat();
        app.afisareCard();
        app.validareCard(1, "Iuliu Maniu");
        app.afisareCard();
        std::shared_ptr<Bilet> t1 = std::make_shared<BiletTranzit>(20, 3);
        app.adaugareBilet(1,t1);
        app.ModificareTimp(23,25);
    }catch(std::exception &err){
        std::cout<<err.what();
    }
    return 0;
}

