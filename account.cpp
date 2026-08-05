#include "account.h"

Account::Account(string accNum, double bal, string accType)
    : accountNumber(accNum), balance(bal), accountType(accType)
{
} 


void Account::addTransaction(const string &type,
                             double amount,
                             const string &date)
{
    transactions.push_back(Transaction(type, amount, date));
}


string Account:: getAccountNumber() const
{
    return accountNumber; 
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
for (auto it = transactions.begin(); it != transactions .end(); it++) 
        {
            (*it).displayTransaction();
        }
}
