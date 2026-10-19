#include <iostream>
using namespace std;

// Base class
class Payment {
public:
    virtual void pay(double amount) {
        cout << "Processing payment of "
             << amount << endl;
    }

    virtual ~Payment() {}
};

// First derived class
class MobileMoney : public Payment {
public:
    void pay(double amount) override {
        cout << "Paying UGX " << amount
             << " using Mobile Money." << endl;
    }
};

// Second derived class
class BankCard : public Payment {
public:
    void pay(double amount) override {
        cout << "Paying UGX " << amount
             << " using a Bank Card." << endl;
    }
};

int main() {
    MobileMoney mobile;
    BankCard card;

    // Base-class pointers
    Payment* payment;

    cout << "PAYMENT SYSTEM" << endl;
    cout << "--------------" << endl;

    payment = &mobile;
    payment->pay(50000);

    payment = &card;
    payment->pay(100000);

    return 0;
}