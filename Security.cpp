
#include "Security.h"

template<typename T>
[[maybe_unused]] Security<T>::Security(const T backup_code1_, const T backup_code2_):
        backup_code1{backup_code1_}, backup_code2{backup_code2_}, backup_code_final{backup_code1_+backup_code2_}{}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Security<T> &security) {
    os << "backup_code_final: " << security.backup_code_final;
    return os;
}
template<typename T>
bool Security<T>::verificaSecuritate(const T& a,const T& b){
    return a+b == backup_code_final;
}

template class Security<std::string>;
template class Security<int>;

template
std::ostream& operator<< <>(std::ostream& o, const Security<int>& security);
template
std::ostream& operator<< <>(std::ostream& o, const Security<std::string>& security);

