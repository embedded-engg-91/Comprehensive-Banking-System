#include <stdexcept>
#include <iostream>
#include "bankingException.h"

using namespace std;
class InsufficientFundsException : public BankingException
{
public:
   
   InsufficientFundsException(): BankingException("Insufficient funds to complete this transaction."){}
};
