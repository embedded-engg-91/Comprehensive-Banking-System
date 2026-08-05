#include "bankerUi.h"
#include "savingsaccount.h"
BankerUI::BankerUI(shared_ptr<Banker> b,
                   map<string, shared_ptr<Customer>> &custs)
    : banker(b), customers(custs)
{ 
}



void BankerUI::  displayMenu() 
{
    std::cout<<"Banker's Menu"<<std::endl;
    std::cout<<"1. Create a Customer"<<std::endl;
    std::cout<<"2. Display All Customer Details"<<std::endl;
    cout << "3. Add Savings Account" << endl;

    std::cout<<"4. Logout"<<std::endl;
    
    
    
    
    
}
void BankerUI:: handleOperations() 
{
    int choice;
    
    do
    {
        displayMenu();
        
        std::cout<<"Enter your choice of operation: "<<std::endl;
    cin>>choice;
    switch(choice)
    {
        case 1: 
        
        
        {string nm,pswd,id;
        cout<<"Enter the ID of the customer"<<endl;
        cin>>id;
        cout<<"Enter the Name of the customer"<<endl;
        cin>>nm;
        cout<<"Enter the Password for this customer"<<endl;
        cin>>pswd;
        banker->createCustomer(customers,id, nm, pswd); 
        
        break;
}

        case 2: 
        {banker->displayAllCustomers(customers); 
        break;}

        case 3:
{
    string customerID;
    string accountNumber;
    double initialBalance;

    cout << "Enter Customer ID: ";
    cin >> customerID;

    
    if (!customers.count(customerID))
    {
        cout << "Customer not found." << endl;
        break;
    }

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    shared_ptr<Account> account =
        make_shared<SavingsAccount>(accountNumber,
                                    initialBalance,
                                    3.5);

    customers[customerID]->addAccount(account);

    cout << "Savings Account Added Successfully." << endl;

    break;
}
        
        
        case 4:
        {
        cout<<"Logging out of the system..."<<endl;

         
        return;
        }
        default:
        {
            cout << "Invalid Choice\n" << endl;
        break;
    }

    }
}while(choice!=4);
return;


}
