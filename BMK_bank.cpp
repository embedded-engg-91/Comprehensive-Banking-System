#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>

#include "banker.h"
#include "customer.h"
#include "bankerUi.h"
#include "customerUi.h"
#include "savingsaccount.h"
#include "bankingException.h"

using namespace std;



void loadFiles(map<string, shared_ptr<Banker>> &bankers,
               map<string, shared_ptr<Customer>> &customers)
{
    string line;

    
    ifstream bankerFile("bankers.csv");
    while (getline(bankerFile, line))
    {
        stringstream ss(line);

        string id, name, pwd;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, pwd, ',');

        bankers[id] = make_shared<Banker>(id, name, pwd);
    }
    bankerFile.close();

    
    ifstream customerFile("customers.csv");
    while (getline(customerFile, line))
    {
        stringstream ss(line);

        string id, name, pwd;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, pwd, ',');

        customers[id] = make_shared<Customer>(id, name, pwd);
    }
    customerFile.close();

    
    ifstream accountFile("accounts.csv");

    while (getline(accountFile, line))
    {
        stringstream ss(line);

        string customerID;
        string accountNo;
        string balanceStr;
        string rateStr;

        getline(ss, customerID, ',');
        getline(ss, accountNo, ',');
        getline(ss, balanceStr, ',');
        getline(ss, rateStr, ',');

        if (customers.count(customerID))
        {
            double balance = stod(balanceStr);
            double rate = stod(rateStr);

            shared_ptr<Account> acc =
                make_shared<SavingsAccount>(
                    accountNo,
                    balance,
                    rate);

            customers[customerID]->addAccount(acc);
        }
    }

    accountFile.close();
}



void saveFiles(map<string, shared_ptr<Banker>> &bankers,
               map<string, shared_ptr<Customer>> &customers)
{
    ofstream bankerFile("bankers.csv");
    ofstream customerFile("customers.csv");
    ofstream accountFile("accounts.csv");

    for (auto &b : bankers)
        b.second->saveToFile(bankerFile);

    for (auto &c : customers)
    {
        c.second->saveToFile(customerFile);

        auto &accounts = c.second->getAccounts();

        for (auto &acc : accounts)
        {
            accountFile
                << c.first << ","                  
                << acc->getAccountNumber() << ","
                << acc->getBalance() << ","
                << 3.5
                << endl;
        }
    }

    bankerFile.close();
    customerFile.close();
    accountFile.close();
}



int main()
{
    map<string, shared_ptr<Banker>> bankers;
    map<string, shared_ptr<Customer>> customers;

    loadFiles(bankers, customers);

    if (bankers.empty())
    {
        bankers["B001"] =
            make_shared<Banker>("B001", "Admin", "1234");
    }

    try
    {
        while (true)
        {
            cout << "\n========== Global Bank ==========\n";
            cout << "1. Banker Login\n";
            cout << "2. Customer Login\n";
            cout << "3. Exit\n";
            cout << "Enter Choice : ";

            int choice;
            cin >> choice;

            if (choice == 3)
                break;

            switch (choice)
            {
            case 1:
            {
                string id, pwd;

                cout << "Banker ID : ";
                cin >> id;

                cout << "Password : ";
                cin >> pwd;

                if (!bankers.count(id))
                {
                    cout << "Banker does not exist.\n";
                    break;
                }

                auto banker = bankers[id];

                if (!banker->authenticate(pwd))
                {
                    cout << "Authentication Failed.\n";
                    break;
                }

                BankerUI ui(banker, customers);
                ui.handleOperations();
                saveFiles(bankers, customers);
                cout << "\nAll Data Saved Successfully.\n";
                break;
            }

            case 2:
            {
                string id, pwd;

                cout << "Customer ID : ";
                cin >> id;

                cout << "Password : ";
                cin >> pwd;

                if (!customers.count(id))
                {
                    cout << "Customer does not exist.\n";
                    break;
                }

                auto customer = customers[id];

                if (!customer->authenticate(pwd))
                {
                    cout << "Authentication Failed.\n";
                    break;
                }

                CustomerUI ui(customer);
                ui.handleOperations();
                saveFiles(bankers, customers);
                
                break;
            }

            default:
                cout << "Invalid Choice.\n";
            }
        }

        saveFiles(bankers, customers);
        cout << "\nAll Data Saved Successfully.\n";
    }
    catch (const BankingException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
