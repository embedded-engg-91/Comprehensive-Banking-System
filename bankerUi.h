#pragma once

#include <iostream>
#include <memory>
#include <map>
#include "banker.h"
#include "customer.h"
#include "ui.h"

class BankerUI : public UI
{
    shared_ptr<Banker> banker; 
    map<string, shared_ptr<Customer>> &customers; 
public:
    BankerUI(shared_ptr<Banker> b, map<string, shared_ptr<Customer>> &custs);

    void displayMenu() override;
    void handleOperations() override;
};
