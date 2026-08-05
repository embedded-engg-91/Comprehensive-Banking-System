#include "customer.h"


bool Customer::authenticate(const string &pwd)
{
    return password == pwd;
}

void Customer::addAccount(shared_ptr<Account> acc)
{
    accounts.push_back(acc);
}

void Customer::displayCustomerInfo() const
{
    cout<<"Customer ID: "<<customerID<<endl;
    cout<<"Account Holder Name:"<<name<<endl;
    
    for (auto it = accounts.begin(); it != accounts.end(); it++)
{
    
    (*it)->displayAccount(); 
}



}
vector<shared_ptr<Account>>& Customer::getAccounts()
{
    return accounts;
}

void Customer::saveToFile(ofstream &out) const
{
    out << customerID << ","
        << name << ","
        << password << endl;
}

void Customer::displayTransactionHistory() const
{
    for (const auto &acc : accounts)
    {
        acc->displayTransactionHistory();
    }
}
