#include <iostream>
#include <vector>
#include "User.h"
#include "Provider.h"
#include "Credentials.h"
#include "Subscription.h"
#include "Date_users.h"
#include "Date_providers.h"

int main(){
    Credentials c3{"ionpopescu22", "parola123"},c4{"danvoiculescu33","password111"};
    Credentials c1{"dave", "parola"},c2{"ana123","parolaparola"};
    std::shared_ptr<Account> ac = std::make_shared<User>(c3, "Ion", "Popescu", "Garanti", 2000, "0785284130");
    std::shared_ptr<Account> ac1 ( new User(c1, "Ioan", "Popescu", "Garantii", 2000, "0785284220"));
    std::shared_ptr<Account> ac10 ( new User(c4, "Ionica", "Popica", "BT", 1100, "0785284221"));
    std::vector<std::shared_ptr<Account>> accounts1;
    std::vector<std::shared_ptr<Account>> accounts11;
    accounts1.push_back(ac);
    accounts1.push_back(ac1);
    accounts11.push_back(ac10);
    Date_users datauser1{accounts1};
    Date_users datauser2{accounts11};
    std::cout<<datauser1;
    std::cout<<std::endl;
    std::cout<<datauser2<<"\nSWAPPING\n";
    swap(datauser1, datauser2);
    std::cout<<datauser1;
    std::cout<<std::endl;
    std::cout<<datauser2<<"\n";
    std::shared_ptr<Account> ac2 = std::make_shared<Provider>(c1, "David", "Patranjel", "the best yt videos", "IBAN1324", 2040, "RO123");
    std::shared_ptr<Account> ac8 = std::make_shared<Provider>(c2, "David", "Patrddanjel", "the bddest yt videos", "IBANd1324", 2040, "RO1423");
    std::vector<std::shared_ptr<Account>> accounts2;
    accounts2.push_back(ac2);
    accounts2.push_back(ac8);
    Date_providers dataprovider1{accounts2};
    std::cout<<dataprovider1;
    std::cout<<"\n\nCONFIRMATION USER\n";
    int k = datauser1.findUserConfirmation("0785284220");
    if(k==-1) std::cout<<"ERROR! Cant find phone number\n";
    else {
        std::cout<<dynamic_cast<const User &>(*datauser1[k]);
        datauser1[k]->confirmAccount();
        std::cout<<dynamic_cast<const User &>(*datauser1[k]);
    }
    std::cout<<"\n\nCONFIRMATION PROVIDER\n";
    k = dataprovider1.findProviderConfirmation("RO1423");
    if(k==-1) std::cout<<"ERROR! Cant find phone number\n";
    else {
        std::cout<<dynamic_cast<const Provider &>(*dataprovider1[k]);
        dataprovider1[k]->confirmAccount();
        std::cout<<dynamic_cast<const Provider &>(*dataprovider1[k]);
    }
    ///Test schimbare parola
    std::cout<<std::endl<<"CHANGE PASSWORD TEST"<<std::endl<<std::endl;
    k = datauser1.findUser("danvoiculescu33");
    if(k==-1) std::cout<<"ERROR! Cant find user\n";
    else {
        std::cout<<dynamic_cast<const User &>(*datauser1[k]);
        datauser1[k]->callChangePasswordAccount("parola123");
        std::cout<<dynamic_cast<const User &>(*datauser1[k]);
    }
    k = dataprovider1.findProvider("ana123");
    if(k==-1) std::cout<<"ERROR! Cant find provider\n";
    else {
        std::cout<<dynamic_cast<const Provider &>(*dataprovider1[k]);
        dataprovider1[k]->callChangePasswordAccount("parolaparola");
        std::cout<<dynamic_cast<const Provider &>(*dataprovider1[k]);
    }
    ///Test subscription
    std::cout<<std::endl<<"SUBSCRIPTION TEST"<<std::endl<<std::endl;
    Subscription s1{dataprovider1[0], "20.01.2020", "20.01.2021", "anual", 50};
    Subscription s2{dataprovider1[1], "30.03.2003", "30.04.2003", "lunar", 10},s3 = s1;
    std::cout<<s1<<s2<<s3;
    s3 = s2;
    s2 = s1;
    std::cout<<s2<<s3;
    ///Test abonament nou
    std::cout<<std::endl<<"NEW SUBS"<<std::endl<<std::endl;
    dynamic_cast<User&>(*datauser1[0]).addSubscription(dataprovider1[0], "01.01.2005", "01.01.2006", "anual", 50);
    dynamic_cast<User&>(*datauser2[0]).addSubscription(dataprovider1[1], "01.01.2006", "01.02.2008", "lunar", 20);
    dynamic_cast<User&>(*datauser1[0]).addSubscription(dataprovider1[1], "03.05.2011", "03.06.2011", "lunar", 25);
    std::cout<<dynamic_cast<User&>(*datauser1[0])<<"\n";
    std::cout<<dynamic_cast<User&>(*datauser2[0])<<"\n";
    std::cout<<dynamic_cast<Provider&>(*dataprovider1[1])<<"\n";
    ///Test cancel subs
    std::cout<<std::endl<<"CANCEL TEST"<<std::endl<<std::endl;
    k = dataprovider1.findSubscriptionAndDelete(datauser1[0]->getCreds().getUsername(), "dave");
    if(k==1)
        dynamic_cast<User&>(*datauser1[0]).cancelSubscription("dave");
    std::cout<<dynamic_cast<User&>(*datauser1[0])<<"\n";
    std::cout<<dynamic_cast<Provider&>(*dataprovider1[0])<<"\n";
    return 0;
}