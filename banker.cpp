#include "banker.h"

Banker::Banker(string id, string nm, string pwd)
    : bankerID(id), name(nm), password(pwd)
{
}

void Banker::saveToFile(ofstream &out) const
{
    out << bankerID << ","
        << name << ","
        << password << endl;
}
bool Banker::authenticate(const string& pwd) 
{
    
    if(pwd==password) 
    return true;
    return false;
}
void Banker::createCustomer(map<string, shared_ptr<Customer>>& customers, string id, string name, string pwd)
{
    
    

    
    
    
    if(customers.count(id)) 
            {
                cout<<"This customer already exists."<<endl;
            }
    else
    {
        
        shared_ptr<Customer> customer=make_shared<Customer>(id,name,pwd);
        customers[id]=customer; 
        cout<<"Customer Created Successfully!!!"<<endl;
    }
}
void Banker::displayAllCustomers(const map<string, shared_ptr<Customer>> &customers)
{
    
    if(customers.empty())
{
    cout << "No customers available.\n";
    return;
}
    for (auto it = customers.begin(); it != customers.end(); it++)
    {
        it->second->displayCustomerInfo(); 
    }
    
}
