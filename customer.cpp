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
    //here i need to caall the account to dispaly the account type nnumber and balance 
    for (auto it = accounts.begin(); it != accounts.end(); it++)
{
    // *it is a shared_ptr<Account>
    (*it)->displayAccount(); //the  object already exists inside the vecotr 
}
//we use vetor na vector is dynamic array 
//so vector 0= saving account goes to thas display fucntion automatiicaly--polymorphism
//vector 1=FD account goes to that display fucntion automatically----polymorphism
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