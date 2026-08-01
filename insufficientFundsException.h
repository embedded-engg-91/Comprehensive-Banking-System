#include <stdexcept>
#include <iostream>
#include "bankingException.h"

using namespace std;
class InsufficientFundsException : public BankingException
{
public:
   // TODO: Write execetion function
   InsufficientFundsException(): BankingException("Insufficient funds to complete this transaction."){}
};
//This constructor passes the error message to BankingException, so later e.what() will print it.