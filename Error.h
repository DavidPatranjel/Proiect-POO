#ifndef OOP_ERROR_H
#define OOP_ERROR_H

#include <stdexcept>
#include <iostream>

class appError : public std::runtime_error {
public:
    explicit appError(const std::string &arg);
};

class confirmationError : public appError {
public:
    explicit confirmationError(const std::string &arg);
};

class subscriptionError : public appError {
public:
    explicit subscriptionError(const std::string &arg);
};

class credentialsError : public appError {
public:
    explicit credentialsError(const std::string &arg);
};

class findError : public appError {
public:
    explicit findError(const std::string &arg);
};

class passwordError : public appError {
public:
    explicit passwordError(const std::string &arg);
};

class securityError : public appError {
public:
    explicit securityError(const std::string &arg);
};
#endif
