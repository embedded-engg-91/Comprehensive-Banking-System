#pragma once

#include <iostream>
#include <memory>
#include "customer.h"
#include "ui.h"
#include "savingsaccount.h"
#include "insufficientFundsException.h"


using namespace std;
class CustomerUI : public UI {
    shared_ptr<Customer> customer;

public:
    CustomerUI(shared_ptr<Customer> cust);
    void displayMenu() override;
    void handleOperations() override;
};