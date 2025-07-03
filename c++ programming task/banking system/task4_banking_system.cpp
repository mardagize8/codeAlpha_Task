#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) : type(t), amount(a) {}
};

class Account {
public:
    double balance;
    vector<Transaction> history;
    Account() : balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        history.emplace_back("Deposit", amount);
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        history.emplace_back("Withdrawal", amount);
        return true;
    }

    void display() {
        cout << "Balance: $" << balance << endl;
        cout << "Transactions:\n";
        for (auto &t : history)
            cout << t.type << ": $" << t.amount << endl;
    }
};

class Customer {
public:
    string name;
    Account account;
    Customer(string n) : name(n) {}
};

int main() {
    Customer user("Alice");
    user.account.deposit(500);
    user.account.withdraw(150);
    user.account.display();
    return 0;
}
