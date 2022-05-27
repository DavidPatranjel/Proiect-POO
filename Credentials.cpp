#include "Credentials.h"
#include "Error.h"
const std::string salt = "?/Mp.3";
///Constructor de initializare - credentiale
Credentials::Credentials(const std::string &username_, const std::string &password_) :
        username{username_}{
    std::hash<std::string> z;
    password = std::to_string(z(password_ +salt));
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
    os << "Username: " << cr.username <<"\n";
    return os;
}

///Schimbare parola
void Credentials::changePassword(const std::string &new_password_) {
    std::cout << "Password changed successfully\n";
    password = new_password_;
}

///Getter-username
const std::string &Credentials::getUsername() const {return username;}
///Getter-parola
const std::string &Credentials::getPassword() const {return password;}

///Builder
CredentialsBuilder &CredentialsBuilder::username(const std::string& u_) {
    std::ifstream fin("usernames.txt");
    std::string s;
    while(fin>>s){
        if(s == u_){
            fin.close();
            throw(credentialsError{"Error: username " + u_ + " exists!"});
        }
    }
    fin.close();
    cred.username = u_;
    hasUsername = true;
    return *this;
}

CredentialsBuilder &CredentialsBuilder::password(const std::string& p_) {
    std::hash<std::string> z;
    cred.password = std::to_string(z(p_+salt));
    return *this;
}
Credentials CredentialsBuilder::build() {
    Credentials other = cred;
    cred = Credentials();
    hasUsername = false;
    if(other.username.empty())
        throw(credentialsError{"Error: username missing!"});
    std::ofstream fout("usernames.txt", std::ios_base::app);
    fout<<other.username<<"\n";
    fout.close();
    return other;
}

int CredentialsFactory::contor = 0;
Credentials CredentialsFactory::automat() {
    contor++;
    return Credentials{"username"+ std::to_string(contor), "parola"+std::to_string(contor)+salt};
}
