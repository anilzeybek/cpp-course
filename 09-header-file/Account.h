#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string name;
    double balance;

public:
    void set_balance(double bal);

    double get_balance();

    void set_name(std::string s);

    std::string get_name();

    bool deposit(double amount);

    bool withdraw(double amount);
};

#endif
