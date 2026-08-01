#pragma once

#include <iostream>
#include <memory>
#include <map>
#include "banker.h"
#include "customer.h"
#include "ui.h"

class BankerUI : public UI
{
    shared_ptr<Banker> banker; //Inside every BankerUI object, there is a pointer to a Banker object.
    map<string, shared_ptr<Customer>> &customers; // & means refernce and means  us the original cuatomer database if no & wed get copy of customers like pass by val then cant modify  in main  
public:
    BankerUI(shared_ptr<Banker> b, map<string, shared_ptr<Customer>> &custs);
//     To create a BankerUI, I need

// one banker
// one customer database
    void displayMenu() override;
    void handleOperations() override;
};