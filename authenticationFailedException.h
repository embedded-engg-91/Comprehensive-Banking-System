#pragma once
#include <stdexcept>
#include <iostream>
#include "bankingException.h"

using namespace std;
class AuthenticationFailedException : public BankingException
{
    public:
    AuthenticationFailedException():BankingException("This username/password is incorrect!!!"){}
};
