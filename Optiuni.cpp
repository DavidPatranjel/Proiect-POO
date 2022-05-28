#include "Optiuni.h"
#include "Date_users.h"
#include "Date_providers.h"

Optiuni &Optiuni::get_Op() {
    static Optiuni op;
    return op;
}
void Optiuni::appTestOpegal(const Date_users& datauser1_){
    Date_users datauseraux{std::vector<std::shared_ptr<Account>>{}};
    std::cout<<datauseraux;
    datauseraux = datauser1_;
    std::cout<<datauseraux;
}
void Optiuni::appConfirmationUser(Date_users& us_, const std::string& phone_number) {
    try{
        int k = us_.findUserConfirmation(phone_number);
        std::cout<<*us_[k];
        us_[k]->confirmAccount();
        std::cout<<*us_[k];
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
}
void Optiuni::appConfirmationProvider(Date_providers& pv_, const std::string& cui) {
    try {
        int k = pv_.findProviderConfirmation(cui);
        std::cout <<*pv_[k];
        pv_[k]->confirmAccount();
        std::cout <<*pv_[k];
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
}
void Optiuni::changePasswordUser(Date_users& us_, const std::string& un_, const std::string& new_password_){
    try {
        int k = us_.findUser(un_);
        std::cout << *us_[k];
        us_[k]->callChangePasswordAccount(new_password_);
        std::cout << *us_[k];
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
}
void Optiuni::changePasswordProvider(Date_providers& pr_, const std::string& un_,  const std::string& new_password_){
    try {
        int k = pr_.findProvider(un_);
        std::cout <<*pr_[k];
        pr_[k]->callChangePasswordAccount(new_password_);
        std::cout << *pr_[k];
    }catch (std::exception& err){
        std::cout << err.what() << "\n";
    }
}
void Optiuni::appAddSub(const std::shared_ptr<Account>& us_, const std::shared_ptr<Account>& pr_, const std::string& data1,
                        const std::string& data2, const std::string& tip, int pret){
    try{
        dynamic_cast<User&>(*us_).addSubscription(pr_, data1, data2, tip, pret);
    }catch(std::bad_cast& err){
        std::cout<<err.what();
    }catch (std::exception& err){
        std::cout<<err.what();
    }
}
void Optiuni::appCancelSub(Date_providers& pr_, const std::shared_ptr<Account>& us_, const std::string& nm_) {
    try {
        pr_.findSubscriptionAndDelete(us_->getCreds().getUsername(),nm_);
        dynamic_cast<User &>(*us_).cancelSubscription(nm_);
    }catch(std::bad_cast& err){
        std::cout<<err.what();
    }catch (std::exception& err){
        std::cout<<err.what();
    }
}

void Optiuni::appTestSecurity(const std::shared_ptr<Account>& ac_, const std::string& d1, const std::string& d2){
    try {
        dynamic_cast<User &>(*ac_).recoverCredentials(d1, d2);
        std::string ans;
        std::cout<<"Want to reset password? Y/N:";
        std::cin>>ans;
        if(ans[0] == 'Y') {
            std::cout<<"What is the new password?\n"; std::cin>>ans;
            ac_->callChangePasswordAccount(ans);
        }else{
            std::cout<<"Password not changed\n";
        }
    }catch(std::exception& err){
        std::cout<<err.what();
    }
}
void Optiuni::appTestSecurity(const std::shared_ptr<Account>& ac_, int d1, int d2){
    try {
        dynamic_cast<Provider &>(*ac_).recoverCredentials(d1, d2);
        std::string ans;
        std::cout<<"Want to reset password?";
        std::cin>>ans;
        if(ans[0] == 'Y') {
            std::cout<<"What is the new password?\n"; std::cin>>ans;
            ac_->callChangePasswordAccount(ans);
        }else{
            std::cout<<"Password not changed\n";
        }
    }catch(std::exception& err2){
        std::cout<<err2.what();
    }
}