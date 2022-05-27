#ifndef PROIECT1_POO_OPTIUNI_H
#define PROIECT1_POO_OPTIUNI_H

#include "Date_users.h"
#include "Date_providers.h"
class Optiuni {
    Optiuni() = default;
public:
    Optiuni &operator=(const Optiuni&) = delete;
    Optiuni(const Optiuni&) = delete;
    static Optiuni& get_Op();
    static void appTestOpegal(const Date_users& datauser1_);
    static void appConfirmationUser(Date_users& us_, const std::string& phone_number);
    static void appConfirmationProvider(Date_providers& pr_, const std::string& cui);
    static void changePasswordUser(Date_users& us_, const std::string& un_, const std::string& new_password_);
    static void changePasswordProvider(Date_providers& pr_, const std::string& un_, const std::string& new_password_);
    static void appAddSub(const std::shared_ptr<Account>& us_, const std::shared_ptr<Account>& pr_, const std::string& data1, const std::string& data2, const std::string& tip, int pret);
    static void appCancelSub(Date_providers& pr_, const std::shared_ptr<Account>& us_, const std::string& nm_);
    static void appTestSecurity(const std::shared_ptr<Account>& ac_, const std::string& d1, const std::string& d2);
    static void appTestSecurity(const std::shared_ptr<Account>& ac_, int d1, int d2);

};


#endif
