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
bool Banker::authenticate(const string& pwd) //dont forget the return type && parameter list must be exactly as defoine 
{
    //compare the password we have with the objects password 
    if(pwd==password) //only password cuz we are already working inside the current object 
    return true;
    return false;
}
void Banker::createCustomer(map<string, shared_ptr<Customer>>& customers, string id, string name, string pwd)
{
    //map(name,cstomer object ) we are direclty having the actual map itself not a copy
    //we got id, name , password

    //first step check for duplicate id if it exists already then return failure 
    //need to iterate over customers
    //count function auutomatically gives whther the id is present int the map or not 
    if(customers.count(id)) //means customer already exists
            {
                cout<<"This customer already exists."<<endl;
            }
    else
    {
        //create a customer
        shared_ptr<Customer> customer=make_shared<Customer>(id,name,pwd);
        customers[id]=customer; //insert it into the map
        cout<<"Customer Created Successfully!!!"<<endl;
    }
}
void Banker::displayAllCustomers(const map<string, shared_ptr<Customer>> &customers)
{
    //uusing the iterator method
    if(customers.empty())
{
    cout << "No customers available.\n";
    return;
}
    for (auto it = customers.begin(); it != customers.end(); it++)//remeber to use auto cuz we dont the type of it na 
    {
        it->second->displayCustomerInfo(); //cuz in maps the "first" will be key and the "second" will be value here second is our customer object 
    }
    
}
