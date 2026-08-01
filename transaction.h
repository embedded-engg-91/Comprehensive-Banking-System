#pragma once
#include <iostream>
using namespace std;

class Transaction {
    string type;
    double amount;
    string date;

public:
Transaction(const string& t, double amt, const string& dt);
    void displayTransaction() const;
};