#include "customerUi.h"


CustomerUI::CustomerUI(shared_ptr<Customer> cust)
    : customer(cust)
{
} 
void CustomerUI::displayMenu()
{
    
    
    
    
    cout<<"Choose an option:"<<endl;
    cout<<"1. View Account Details"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. View Latest Transactions"<<endl;
    cout<<"5. Logout"<<endl;
}
void CustomerUI::handleOperations()
{
    
    auto &accounts = customer->getAccounts();
    int choice;
    do
    {
    displayMenu();
        cin>>choice;

    switch(choice)
    {
        case 1:
        
        customer->displayCustomerInfo();
        break;


        case 2:
        {
            string accNo; 
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount: ";
            cin >> amount;

            

            int flag=0;
            for( auto it=accounts.begin();it!=accounts.end();it++)
            {
                if ((*it)->getAccountNumber() == accNo)
                {
                    (*it)->deposit(amount); 
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
            cout<<"This account number does not exist.Please try again"<<endl;
            return;
            }
            

            cout<<"Amount has been deposited successfully"<<endl;


            
        }



        break;


        case 3: 
        {
            string accNo; 
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount: ";
            cin >> amount;

            
            int flag=0;
            for( auto it=accounts.begin();it!=accounts.end();it++)
            {
                if ((*it)->getAccountNumber() == accNo)
                {
                    
                    (*it)->withdraw(amount); 
                    flag=1;
                    break;
                    
                }
            }
            if(flag==0)
            {
            cout<<"This account number does not exist.Please try again"<<endl;
            return;
            
            }
            cout<<"Amount has been withdrawn successfully"<<endl;


            
        }
        break;



        case 4: 
        

        for (auto it = accounts.begin(); it != accounts.end(); it++)
        {
            (*it)->displayTransactionHistory();
        }

        
        break;

        case 5: 
        cout<<"Logging Out"<<endl;
        return;
        default:
        cout << "Invalid choice." << endl;
        break;
    }
    }while(choice!=5);
}
