#pragma once
#include <stdexcept>
#include <iostream>
#include "bankingException.h"

using namespace std;
class AuthenticationFailedException : public BankingException
{
    public:
    //Todo: Write the exception function
    AuthenticationFailedException():BankingException("This username/password is incorrect!!!"){}
};