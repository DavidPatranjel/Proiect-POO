#include "Credentials.h"
#include "Error.h"

///Constructor de initializare - credentiale
Credentials::Credentials(const std::string &username_, const std::string &password_) :
        username{username_}, password{password_}{
    std::ifstream fin("usernames.txt");
    std::string s;
    while(fin>>s){
        if(s == username_){
            fin.close();
            throw(credentialsError{"Error: username " + username + " exists!"});
        }
    }
    fin.close();
    std::ofstream fout("usernames.txt", std::ios_base::app);
    fout<<username_<<"\n";
    fout.close();
    std::cout << "Constr de initializare Credentiale\n";
}

///Operatorul << - credentiale
std::ostream &operator<<(std::ostream &os, const Credentials &cr) {
    os << "Username: " << cr.username << ", password: " << cr.password << "\n";
    return os;
}

///Schimbare parola
void Credentials::changePassword(const std::string &new_password_) {
    std::cout << "Password changed successfully\n";
    password = new_password_;
}

///Getter-username
const std::string &Credentials::getUsername() const {return username;}

