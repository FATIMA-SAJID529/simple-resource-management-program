#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    string name;
    double balance;

public:
    // Constructor
    BankAccount(string n, double b)
    {
        cout << "Constructor called for " << n << endl;
        if (b < 0)
            throw runtime_error("Invalid account creation: Negative balance not allowed.");
        name = n;
        balance = b;
    }
    // Withdraw function
    void withdraw(double amount)
    {
        if (amount > balance)
            throw runtime_error("Withdrawal failed: Insufficient balance.");
        balance -= amount;
        cout << "Withdrawal successful for " << name<< ". Remaining balance: " << balance << endl;
    }
    // Display function
    void display() 
    {
        cout << "The Account Holder is: " << name << endl;
        cout << "The Balance is: " << balance << endl;
    }
    // Destructor
    ~BankAccount()
    {
        cout << "Destructor called for " << name << endl;
    }
};
int main()
{
    BankAccount* acc = nullptr;
    BankAccount* acc1 = nullptr;
    BankAccount* acc2 = nullptr;
    // Test first account
    try
    {
        acc = new BankAccount("fatima", 500);
        acc->display();
        acc->withdraw(700);    // Will throw
    }
    catch (const exception& e)
    {
        cout << "Exception caught for fatima: " << e.what() << endl; 
    }
    // Test second account
    try
    {
        acc1 = new BankAccount("ali", -100); // Will throw
        acc1->display();
    }
    catch (const exception& e)
    {
        cout << "Exception caught for ali: " << e.what() << endl;
    }
    // Test third account
    try
    {
        acc2 = new BankAccount("ahmed", 300);
        acc2->display();
        acc2->withdraw(200);
        cout << "Account for ahmed created and withdrawal successful." << endl;
    }
    catch (const exception& e)
    {
        cout << "Exception caught for ahmed: " << e.what() << endl;
    }
    // Cleanup (only valid objects)
    delete acc;
    delete acc1;  
    delete acc2;
    cout << "Program continues normally." << endl;
    return 0;
}

