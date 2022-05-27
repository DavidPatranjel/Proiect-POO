#ifndef PROIECT1_POO_SECURITY_H
#define PROIECT1_POO_SECURITY_H

#include <iostream>
template <typename T>
class Security;
template <typename T>
std::ostream& operator<<(std::ostream& o, const Security<T>& security);
template <typename T>
class Security {
    T backup_code1;
    T backup_code2;
    const T backup_code_final;
public:
    [[maybe_unused]] Security(T backup_code1_, T backup_code2_);
    friend std::ostream& operator<< <>(std::ostream&, const Security<T>&);
    bool verificaSecuritate(const T& a, const T& b);
};

#endif

