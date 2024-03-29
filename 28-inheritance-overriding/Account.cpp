#include "Account.h"
#include <iostream>

Account::Account() : balance{0} {}

Account::Account(double balance) : balance{balance} {}

void Account::deposit(double amount) {
    this->balance += amount;
}

void Account::withdraw(double amount) {
    if (this->balance - amount >= 0)
        this->balance -= amount;
    else
        std::cout << "Insufficient funds" << std::endl;

}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "Account balance: " << account.balance;
    return os;
}