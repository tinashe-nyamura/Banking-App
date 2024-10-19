#include <iostream>
#include <vector>
#include <string>

using namespace std;
string yesorno;
// Account class definition
class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    int number;
    string name;
    double initialBalance;
    string yesorno;
public:
    Account()
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited R" << amount << ". New balance: R" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew R" << amount << ". New balance: R" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void checkBalance() const {
        cout << "Account balance: R" << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

// Banking system class definition
class BankingSystem {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        int number;
        string name;
        double initialBalance;

        cout << "Enter account number: ";
        cin >> number;
        cin.ignore();  // To ignore leftover newline character in input buffer
        cout << "Enter account holder's name: ";
        getline(cin, name);
        cout << "Enter initial deposit amount: ";
        cin >> initialBalance;

        Account newAccount();
        cout << "Account created successfully." << endl;
    }

    Account* findAccount(int number) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == number) {
                return &account;
            }
        }
        return nullptr;
    }

    void depositMoney() {
        int number;
        double amount;

        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter deposit amount: ";
        cin >> amount;

        Account* account = findAccount(number);
        if (account) {
            account->deposit(amount);
        } else {
            cout << "Account not found." << endl;
        }
    }

    void withdrawMoney() {
        int number;
        double amount;

        cout << "Enter account number: ";
        cin >> number;
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        Account* account = findAccount(number);
        if (account) {
            account->withdraw(amount);
        } else {
            cout << "Insufficiant Funds." << endl;
        }
    }

    void checkAccountBalance() {
        int number;

        cout << "Enter account number: ";
        cin >> number;

        Account* account = findAccount(number);
        if (account) {
            account->checkBalance();
        } else {
            cout << "Error Please try again." << endl;
        }
    }
};

int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\n*** Banking System Menu ***\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Account Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.depositMoney();
                break;
            case 3:
                bank.withdrawMoney();
                break;
            case 4:
                bank.checkAccountBalance();
                break;
            case 5:
                cout << "Are you Sure you want to Exit?" << endl;
                cin >> yesorno;
                   if (yesorno=="no")
                {cout << ""<<endl;
                }
                else if (yesorno=="yes")
                {cout << "Thank You for Your Time. GOODBYE"<<endl;
                }

                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
