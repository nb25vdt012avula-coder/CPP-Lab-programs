#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double b) {
        balance = b;
    }

    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Balance: Rs. " << balance << endl;
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }

    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(double b) : Account(b) {}

    double calculateInterest() const override {
        return balance * 0.06;
    }
};

class Current : public Account {
public:
    Current(double b) : Account(b) {}

    double calculateInterest() const override {
        return balance * 0.03;
    }
};

int main() {
    Savings s(10000);
    Current c(20000);

    Account* accounts[2] = {&s, &c};

    for (int i = 0; i < 2; i++) {
        accounts[i]->display();
        cout << endl;
    }

    return 0;
}