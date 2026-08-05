#pragma once

#include <iostream>
#include <vector>
#include "transaction.h"
#include <fstream>

using namespace std;

class Account
{
protected:
    string accountNumber;
    double balance;
    string accountType;
    vector<Transaction> transactions;

public:
    Account(string accNum, double bal, string accType);

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayAccount() const = 0;
    virtual void saveToFile(ofstream &out) const = 0;
    void addTransaction(const string &type, double amount, const string &date);
    void displayTransactionHistory() const;
    virtual ~Account() {}
    virtual string getAccountNumber() const;
    virtual double getBalance() const;
    virtual string getAccountType() const;
};
