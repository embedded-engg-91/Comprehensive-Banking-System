#include "customerUi.h"


CustomerUI::CustomerUI(shared_ptr<Customer> cust)
    : customer(cust)
{
} //similar to the one we did in banker 
void CustomerUI::displayMenu()
{
    //view acc detail
    //deopsit
    //withdraw
    //transcation history 
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
        case 1://view account detials
        //cuustomer id, customer name, account number, account balance type,  
        customer->displayCustomerInfo();
        break;


        case 2:
        {
            string accNo; //declaring local variables so we need the braces for this case 
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount: ";
            cin >> amount;

            // Search through the customer's accounts

            int flag=0;
            for( auto it=accounts.begin();it!=accounts.end();it++)
            {
                if ((*it)->getAccountNumber() == accNo)
                {
                    (*it)->deposit(amount); //deposited amount in that type of account aiutomatically due to runtime polymorphism
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
            cout<<"This account number does not exist.Please try again"<<endl;
            return;
            }
            // Save the updated data to file will  be done at once before exit 

            cout<<"Amount has been deposited successfully"<<endl;


            
        }



        break;


        case 3: //withdrawing money 
        {
            string accNo; //declaring local variables so we need the braces for this case 
            double amount;

            cout << "Enter Account Number: ";
            cin >> accNo;

            cout << "Enter Amount: ";
            cin >> amount;

            // Search through the customer's accounts
            int flag=0;
            for( auto it=accounts.begin();it!=accounts.end();it++)
            {
                if ((*it)->getAccountNumber() == accNo)
                {
                    
                    (*it)->withdraw(amount); //deposited amount in that type of account aiutomatically due to runtime polymorphism
                    flag=1;
                    break;
                    
                }
            }
            if(flag==0)
            {
            cout<<"This account number does not exist.Please try again"<<endl;
            return;
            // Save the updated data to file will  be done at once before exit 
            }
            cout<<"Amount has been withdrawn successfully"<<endl;


            
        }
        break;



        case 4: //view transaction history
        //iterate theough each vector in trancaction in account class and dispaly the transaction

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