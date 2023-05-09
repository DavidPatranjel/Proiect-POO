#include <iostream>
#include <vector>
#include <memory>

class Data{
    int an;
    int luna;
    int zi;
public:
    Data(int an, int luna, int zi) : an(an), luna(luna), zi(zi) {}
    friend std::ostream &operator<<(std::ostream &os, const Data &data) {
        os << "an: " << data.an << " luna: " << data.luna << " zi: " << data.zi;
        return os;
    }
};

class Ora{
    int ora;
    int minut;
public:
    Ora(int ora, int minut) : ora(ora), minut(minut) {}
    friend std::ostream &operator<<(std::ostream &os, const Ora &ora_) {
        os << "ora: " << ora_.ora << " minut: " << ora_.minut;
        return os;
    }
};

class Zbor{
    const int id;
    static int contor;
    std::string oras_destinatie;
    Data data_plecare;
    Ora ora_plecare;
    Ora durata_zbor;
    int pret_zbor;
public:
    Zbor(const std::string &orasDestinatie, const Data &dataPlecare, const Ora &oraPlecare,
         const Ora &durataZbor, int pretZbor) : id(contor++), oras_destinatie(orasDestinatie), data_plecare(dataPlecare),
                                                ora_plecare(oraPlecare), durata_zbor(durataZbor), pret_zbor(pretZbor) {}

    virtual void afisare(std::ostream &os) const {
        Zbor zbor = *this;
        os << "id: " << zbor.id << " oras_destinatie: " << zbor.oras_destinatie << " data_plecare: "
           << zbor.data_plecare << " ora_plecare: " << zbor.ora_plecare << " durata_zbor: " << zbor.durata_zbor
           << " pret_zbor: " << zbor.pret_zbor;
    }
    friend std::ostream &operator<<(std::ostream &os, const Zbor &zbor) {
        zbor.afisare(os);
        return os;
    }
};

class ZborLowcost:public Zbor{
    int greutate_bagaj;
    int pret_kg;
public:
    ZborLowcost(const std::string &orasDestinatie, const Data &dataPlecare, const Ora &oraPlecare,
                const Ora &durataZbor, int pretZbor, int greutateBagaj, int pretKg) : Zbor(orasDestinatie,
                                                                                           dataPlecare, oraPlecare,
                                                                                           durataZbor, pretZbor),
                                                                                      greutate_bagaj(greutateBagaj),
                                                                                      pret_kg(pretKg) {}

    void afisare(std::ostream &os) const override{
        Zbor::afisare(os);
        os << " greutate_bagaj: " << greutate_bagaj << " pret_kg: "
           << pret_kg;
    }

};

class ZborLinie:public Zbor{
    std::vector<std::string> escale;
public:
    ZborLinie(const std::string &orasDestinatie, const Data &dataPlecare, const Ora &oraPlecare,
              const Ora &durataZbor, int pretZbor, const std::vector<std::string> &escale = {}) : Zbor(orasDestinatie,
                                                                                                  dataPlecare,
                                                                                                  oraPlecare,
                                                                                                  durataZbor, pretZbor),
                                                                                             escale(escale) {}

    void afisare(std::ostream &os) const override{
        Zbor::afisare(os);
        std::cout<<"Escale: \n";
        for(auto& i:escale){
            std::cout<<i<<" ";
        }
    }
};

int Zbor::contor = 1;

class ZborCharter:public Zbor{
    std::string companie_turism;
    int diferenta_pret;
public:
    ZborCharter(const std::string &orasDestinatie, const Data &dataPlecare, const Ora &oraPlecare,
                const Ora &durataZbor, int pretZbor, const std::string &companieTurism, int diferentaPret) : Zbor(orasDestinatie,
                                                                                                                  dataPlecare,
                                                                                                                  oraPlecare,
                                                                                                                  durataZbor,
                                                                                                                  pretZbor),
                                                                                                             companie_turism(
                                                                                                                     companieTurism),
                                                                                                             diferenta_pret(
                                                                                                                     diferentaPret) {}

    void afisare(std::ostream &os) const override {
        Zbor::afisare(os);
        std::cout << "\nCompanie turism: " << companie_turism << "\nDiferenta de pret: " << diferenta_pret;
    }
};

class Companie{
protected:
    std::string denumire;
    int an;
    std::string cod;
    std::vector<std::string> conexiuni;
public:
    Companie(const std::string &denumire, int an, const std::string &cod, const std::vector<std::string> &conexiuni) : denumire(denumire), an(an), cod(cod), conexiuni(conexiuni) {}


    virtual void afisare(std::ostream &os) const {
        Companie companie = *this;
        os << "denumire: " << companie.denumire << " an: " << companie.an << " cod: " << companie.cod << " conexiuni: ";
        for(auto& i:companie.conexiuni) {
            os<<i<<" ";
        }
        os<<std::endl;
    }
    friend std::ostream &operator<<(std::ostream &os, const Companie &companie) {
        companie.afisare(os);
        return os;
    }

};

class CompanieLowcost:public Companie{
    std::vector<ZborLowcost> zboruri_lc;
    std::vector<ZborCharter> zboruri_ch;
public:
    CompanieLowcost(const std::string &denumire, int an, const std::string &cod,
                    const std::vector<std::string> &conexiuni, const std::vector<ZborLowcost> &zboruriLc, const std::vector<ZborCharter> &zboruriCh):
                    Companie(denumire, an, cod, conexiuni), zboruri_lc(zboruriLc), zboruri_ch(zboruriCh) {}
    void afisare(std::ostream &os) const override{
        std::cout<<"Zboruri Lowcost"<<std::endl;
        for(auto& i:zboruri_lc){
            std::cout<<i<<std::endl;
        }
        std::cout<<"\nZboruri Charter"<<std::endl;
        for(auto& i:zboruri_ch){
            std::cout<<i<<std::endl;
        }
    }
};

class CompanieLinie:public Companie{
    std::vector<ZborLinie> zboruri_lin;
    std::vector<ZborCharter> zboruri_ch;
public:
    CompanieLinie(const std::string &denumire, int an, const std::string &cod, const std::vector<std::string> &conexiuni,
                  const std::vector<ZborLinie> &zboruriLin  = {}, const std::vector<ZborCharter> &zboruriCh = {}) :
            Companie{denumire, an, cod, conexiuni}, zboruri_lin{zboruriLin}, zboruri_ch{zboruriCh} {}

    void afisare(std::ostream &os) const override{
        Companie::afisare(os);
        std::cout<<"Zboruri Linie"<<std::endl;
        for(auto& i:zboruri_lin){
            std::cout<<i<<std::endl;
        }
        std::cout<<"\nZboruri Charter"<<std::endl;
        for(auto& i:zboruri_ch){
            std::cout<<i<<std::endl;
        }
    }
};

int main() {
    Data d1{2020, 04, 23};
    Ora o1{20, 15}, o2{2, 30};
    ZborLinie z1{"Londra", d1, o1, o2, 50, {"Viena"}};
    ZborLinie z2{"Paris", d1, o1, o2, 50, {"Viena"}};
    CompanieLinie cl1{"KLM", 1919, "klm", {"Londra", "Paris", "Viena"}, {z1, z2}};

    std::cout<<cl1;
    return 0;
}
