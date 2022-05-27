#include "Error.h"

appError::appError(const std::string &arg) : runtime_error(arg) {}
confirmationError::confirmationError(const std::string &arg) : appError(arg) {}
subscriptionError:: subscriptionError(const std::string &arg) : appError(arg) {}
credentialsError::credentialsError(const std::string &arg) : appError(arg) {}
findError:: findError(const std::string &arg) : appError(arg) {}
passwordError:: passwordError(const std::string &arg) : appError(arg) {}
securityError:: securityError(const std::string &arg) : appError(arg) {}
