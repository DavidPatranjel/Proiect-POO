#include <iostream>
#include <vector>
#include "User.h"
#include "Provider.h"
#include "Credentials.h"
#include "Date_users.h"
#include "Date_providers.h"
#include "Optiuni.h"

int main(){
    auto& app = Optiuni::get_Op();
    std::ofstream fout("usernames.txt");
    fout.close();
    CredentialsBuilder cb;
    Credentials c1 = cb.username("david1").password("password_david1").build();
    ///Credentials c2 = cb.username("david2").password("password_david2").build();
    Credentials c3{"david3", "password_david3"}, c4{"david4", "password_david4"};
    std::shared_ptr<Account> ac3 = std::make_shared<User>(c3, "Dave", "Trei", "RON123BT00059", "verde", "Aprilie", "0785284130");
    std::shared_ptr<Account> ac1 ( new User(c1, "Dave", "Unu", "RON123BGB00012", "albastru", "August", "0785284220"));
    std::shared_ptr<Account> ac4 ( new User(c4, "Dave", "Patru", "RON123BCR00033", "rosu", "Ianuarie",  "0785284221"));
    std::shared_ptr<Account> ac2 = std::make_shared<Provider>(CredentialsFactory::automat(), "Dave", "Prov1", 12313, 33,"The first provider!", "RON123BT00081", "RON7233");
    std::shared_ptr<Account> ac8 = std::make_shared<Provider>(CredentialsFactory::automat(), "Dave", "Prov2", 11111, 99,"The last provider!", "RON123ING00033", "UK777");
    Date_users datauser1{std::vector<std::shared_ptr<Account>>{ac3, ac1}};
    Date_users datauser2{std::vector<std::shared_ptr<Account>>{ac4}};
    Date_providers dataprovider1{std::vector<std::shared_ptr<Account>>{ac2, ac8}};
    std::cout<<datauser1<<datauser2<<dataprovider1;
    std::cout<<"\nSWAPPING, OP=\n";
    app.appTestOpegal(datauser1);
    std::cout<<"\nCONFIRMATION USER\n";
    app.appConfirmationUser(datauser1, "0785284220");
    app.appConfirmationUser(datauser2, "0785284221");
    app.appConfirmationUser(datauser1, "0785284227");
    std::cout<<"\nCONFIRMATION PROVIDER\n";
    app.appConfirmationProvider(dataprovider1, "UK777");
    std::cout<<std::endl<<"CHANGE PASSWORD TEST"<<std::endl<<std::endl;
    app.changePasswordUser(datauser1, "david1", "password_david1");
    app.changePasswordUser(datauser1, "david1", "new_password_david1");
    app.changePasswordUser(datauser1, "daviddavid", "new_password_david1");
    app.changePasswordProvider(dataprovider1, "username1", "parola1");
    std::cout<<std::endl<<"SUBSCRIPTION TEST"<<std::endl<<std::endl;
    app.appAddSub(datauser2[0], dataprovider1[0], "01.01.2005", "01.01.2006", "anual", 50);
    app.appAddSub(datauser2[0], dataprovider1[1], "01.01.2006", "01.02.2008", "lunar", 20);
    app.appAddSub(datauser1[0], dataprovider1[1], "03.05.2011", "03.06.2011", "lunar", 25);
    std::cout<<*datauser1[0]<<"\n";
    std::cout<<*datauser2[0]<<"\n";
    std::cout<<*dataprovider1[1]<<"\n";
    std::cout<<std::endl<<"CANCEL TEST"<<std::endl<<std::endl;
    app.appCancelSub(dataprovider1, datauser1[0], "username");
    app.appCancelSub(dataprovider1, datauser1[0], "username2");
    app.appCancelSub(dataprovider1, datauser2[0], "username2");
    std::cout<<*datauser1[0]<<"\n";
    std::cout<<*dataprovider1[0]<<"\n";
    std::cout<<std::endl<<"SECURITY TEST"<<std::endl<<std::endl;
    app.appTestSecurity(datauser2[0], "rosu", "Ianuarie");
    app.appTestSecurity(dataprovider1[1], 12313, 33);
    app.appTestSecurity(dataprovider1[1], 11111, 99);
    return 0;
}