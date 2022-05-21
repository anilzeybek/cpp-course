#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

int main() {
    Account acc{};
    acc.deposit(2000);
    acc.withdraw(500);

    std::cout << std::endl;

    Account *p_acc{nullptr};
    p_acc = new Account();
    p_acc->deposit(1000);
    p_acc->withdraw(500);
    delete p_acc;

    std::cout << std::endl;

    Savings_Account sav_acc{};
    sav_acc.deposit(2000);
    sav_acc.withdraw(500);

    std::cout << std::endl;

    Savings_Account *p_sav_acc{nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000);
    p_sav_acc->withdraw(500);
    delete p_sav_acc;

    return 0;
}
