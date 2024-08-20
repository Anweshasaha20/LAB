#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class SavingsAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;
    static double interestRate;
    static int nextAccountNumber;

public:
    SavingsAccount(const string& name, double initialBalance)
        : accountHolderName(name), balance(initialBalance) {
        accountNumber = nextAccountNumber++;
        if (balance < 1000) {
            balance = 1000; // Ensure minimum balance
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 1000) {
            balance -= amount;
        } else {
            cout << "Insufficient funds or withdrawal amount invalid.\n";
        }
    }

    double calculateInterest() const {
        return balance * interestRate;
    }

    void addInterest() {
        double interest = calculateInterest();
        deposit(interest);
    }

    static void setInterestRate(double rate) {
        interestRate = rate;
    }

    static double getInterestRate() {
        return interestRate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    static int getNextAccountNumber() {
        return nextAccountNumber;
    }

    static void resetAccountNumber() {
        nextAccountNumber = 1; // Reset account number if needed
    }

    static double calculateTotalInterest(const vector<SavingsAccount>& accounts) {
        double totalInterest = 0.0;
        for (const auto& account : accounts) {
            totalInterest += account.calculateInterest();
        }
        return totalInterest;
    }
};

// Initialize static members
double SavingsAccount::interestRate = 0.05; // 5% interest rate
int SavingsAccount::nextAccountNumber = 1;

int main() {
    // Seed random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    vector<SavingsAccount> accounts;
    const int numAccounts = 100;

    // Create 100 SavingsAccount objects with random balances
    for (int i = 0; i < numAccounts; ++i) {
        double initialBalance = 1000 + rand() % 99001; // Random balance between 1000 and 100000
        accounts.emplace_back("AccountHolder" + to_string(i + 1), initialBalance);
    }

    // Calculate interest for each account, deposit it, and print the details
    for (auto& account : accounts) {
        double interest = account.calculateInterest();
        account.addInterest();
        cout << "Account Number: " << account.getAccountNumber()
             << ", Account Holder: " << account.getAccountHolderName()
             << ", Interest: Rs. " << interest
             << ", Updated Balance: Rs. " << account.getBalance() << endl;
    }

    // Calculate total interest paid to all accounts
    double totalInterest = SavingsAccount::calculateTotalInterest(accounts);

    cout << "\nTotal interest paid to all accounts in one year: Rs. " << totalInterest << endl;

    return 0;
}
