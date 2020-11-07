#include "Account.h"

void Account::set_balance(double bal) {
    balance = bal;
}

double Account::get_balance() {
    return balance;
}


void Account::set_name(std::string s) {
    name = std::move(s);
}

std::string Account::get_name() {
    return name;
}

bool Account::deposit(double amount) {
    // if verify amount
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}
