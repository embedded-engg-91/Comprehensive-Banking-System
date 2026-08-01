#pragma once

#include <stdexcept>
#include <iostream>

using namespace std;

class BankingException : public exception {
    string message;
public:
    BankingException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
