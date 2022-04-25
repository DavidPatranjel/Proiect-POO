#include "Error.h"

appError::appError(const std::string &arg) : runtime_error(arg) {
    std::cout << "constr err\n";
}

confirmedError::confirmedError(const std::string &arg) : appError(arg) {}
subscriptionError:: subscriptionError(const std::string &arg) : appError(arg) {}
credentialsError::credentialsError(const std::string &arg) : appError(arg) {}
findError:: findError(const std::string &arg) : appError(arg) {}