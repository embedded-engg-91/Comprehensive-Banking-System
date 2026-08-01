
#pragma once
#include <iostream>
#include <fstream>
#include "account.h"
using namespace std;

class SavingsAccount : public Account { //account is abstract class whise base definition we are using 
    double interestRate;

public:
    SavingsAccount(string accNum, double bal, double rate);

    void deposit(double amount) override ;

    void withdraw(double amount) override ;

    void displayAccount() const override ;

    void saveToFile(ofstream& out) const override;

};