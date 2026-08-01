#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "account.h"
#include "authenticationFailedException.h"

using namespace std;
class Customer {
    string customerID;
    string name;
    string password;
    vector<shared_ptr<Account>> accounts;

public:
    Customer(string id, string nm, string pwd)
        : customerID(id), name(nm), password(pwd) {}
    bool authenticate(const string& pwd);
    void addAccount(shared_ptr<Account> acc);
    void displayCustomerInfo() const;
    void displayTransactionHistory() const;
    void saveToFile(ofstream& out) const;
    vector<shared_ptr<Account>>& getAccounts();
};