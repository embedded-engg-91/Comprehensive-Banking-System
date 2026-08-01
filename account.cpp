#include "account.h"

Account::Account(string accNum, double bal, string accType)
    : accountNumber(accNum), balance(bal), accountType(accType)
{
} //simialr to the banker 


void Account::addTransaction(const string &type,
                             double amount,
                             const string &date)
{
    transactions.push_back(Transaction(type, amount, date));
}


string Account:: getAccountNumber() const
{
    return accountNumber; //function means we are already inside the object na
}
double Account::getBalance() const
{
    return balance;
}
string Account::getAccountType() const
{
    return accountType;
}

void Account::displayTransactionHistory() const
{
for (auto it = transactions.begin(); it != transactions .end(); it++) //mistake it should iterate over transaction vextor not account vectos 
        {
            (*it).displayTransaction();
        }
}
