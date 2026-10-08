#include <iostream>
#include <string>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    Transaction()
    {
        type = "";
        amount = 0;
    }

    Transaction(string t, double a)
    {
        type = t;
        amount = a;
    }
};

class Account
{
public:
    int accountNumber;
    double balance;
    Transaction transactions[100];
    int transactionCount;

    Account()
    {
        accountNumber = 0;
        balance = 0;
        transactionCount = 0;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;

            transactions[transactionCount] =
                Transaction("Deposit", amount);

            transactionCount++;

            cout << "Deposit successful." << endl;
        }
        else
        {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;

            transactions[transactionCount] =
                Transaction("Withdrawal", amount);

            transactionCount++;

            cout << "Withdrawal successful." << endl;
        }
        else
        {
            cout << "Not enough balance or invalid amount." << endl;
        }
    }

    void transfer(Account &other, double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            other.balance = other.balance + amount;

            transactions[transactionCount] =
                Transaction("Transfer", amount);

            transactionCount++;

            cout << "Transfer successful." << endl;
        }
        else
        {
            cout << "Transfer failed." << endl;
        }
    }

    void showTransactions()
    {
        cout << "\nTransaction History:" << endl;

        if (transactionCount == 0)
        {
            cout << "No transactions yet." << endl;
        }
        else
        {
            for (int i = 0; i < transactionCount; i++)
            {
                cout << transactions[i].type
                     << " : "
                     << transactions[i].amount
                     << endl;
            }
        }
    }

    void showAccount()
    {
        cout << "\nAccount Number: "
             << accountNumber << endl;

        cout << "Balance: "
             << balance << endl;
    }
};

class Customer
{
public:
    string name;
    int customerId;
    Account account;

    Customer(string n, int id, int accNumber)
    {
        name = n;
        customerId = id;
        account.accountNumber = accNumber;
    }

    void showCustomer()
    {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Customer ID: " << customerId << endl;

        account.showAccount();
    }
};

int main()
{
    Customer customer1("Abdullah", 1, 1001);
    Customer customer2("Ahmed", 2, 1002);

    int choice;
    double amount;

    cout << "Banking System" << endl;

    do
    {
        cout << "\n1. Show Account Information" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Show Transactions" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            customer1.showCustomer();
        }
        else if (choice == 2)
        {
            cout << "Enter amount: ";
            cin >> amount;

            customer1.account.deposit(amount);
        }
        else if (choice == 3)
        {
            cout << "Enter amount: ";
            cin >> amount;

            customer1.account.withdraw(amount);
        }
        else if (choice == 4)
        {
            cout << "Enter amount: ";
            cin >> amount;

            customer1.account.transfer(customer2.account, amount);
        }
        else if (choice == 5)
        {
            customer1.account.showTransactions();
        }
        else if (choice == 6)
        {
            cout << "Thank you for using the Banking System." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}

