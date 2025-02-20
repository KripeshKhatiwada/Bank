#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class Account_Details{
long long acc_no=0;
string name;
int balance=0, pin=0;
public:
   void account_create();
   void deposit();
    void withdrawal();
   void balance_inquiry();

};

void Account_Details::account_create() {
    cout<<"Enter account number: ";
    cin>>acc_no;
    cout<<"Enter account name: ";
    cin>>name;
    cout<<"Enter account PIN: ";
    cin>>pin;
    cout<<"\nAccount created\n"<<endl;
}
void Account_Details::deposit() {
    double amount;
    cout<<"Enter deposit amount"<<endl;
    cin>> amount;
    if (amount<=0) {
    cout<<"Invalid deposit"<<endl;
    }
    else {
        balance= balance+ amount;
        cout << "Deposit successful! New balance: " << balance << endl;
    }

}

void Account_Details::withdrawal() {
    double amount;
    cout<<"Enter withdrawal amount"<<endl;
    cin>> amount;
    if (amount>balance) {
        cout<<"Invalid withdrawal Insufficient Balance"<<endl;
    }
    else {
        balance= balance- amount;
        cout<<"New balance: " << balance << endl;
    }

}

void Account_Details::balance_inquiry() {
    cout<<"Your current balance is: "<<balance<<endl;

}
void menu(Account_Details& account) {
    int choice;
    bool isRunning = true;

    while (isRunning) {
        cout << "\n*** Banking System ***\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdrawal\n";
        cout << "4. Balance Inquiry\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.account_create();
            break;
            case 2:
                account.deposit();
            break;
            case 3:
                account.withdrawal();
            break;
            case 4:
                account.balance_inquiry();
            break;
            case 5:
                isRunning = false;  // Set isRunning to false to exit the loop
            cout << "Exiting the system. Goodbye!" << endl;
            break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }
}

int main() {
    Account_Details account;
    menu(account);

    return 0;
}