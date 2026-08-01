#include "savingsaccount.h"
#include "insufficientFundsException.h"
#include <ctime>
#include <iomanip>
#include <sstream>

#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

string getCurrentDate()
{
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d");

    return ss.str();
}

SavingsAccount::SavingsAccount(string accNum, double bal, double rate)
    : Account(accNum, bal, "Savings"), interestRate(rate) {}

void SavingsAccount::deposit(double amount)
{
    if(amount <= 0)
    return;

    

    balance += amount;
    addTransaction("Deposit", amount, getCurrentDate());
}

void SavingsAccount::withdraw(double amount)
{
    
    if (balance >= amount)
    {
        balance -= amount;
        addTransaction("Withdraw", amount,getCurrentDate());
    }
    else
    {
        throw InsufficientFundsException();
    }
}

void SavingsAccount::displayAccount() const 
{
    cout << "Account Number: " << accountNumber
         << ", Balance: " << balance
         << ", Interest Rate: " << interestRate << "%\n";
}

void SavingsAccount::saveToFile(ofstream &out) const 
{
    out << accountNumber << "," << balance << "," << interestRate << "\n";
}