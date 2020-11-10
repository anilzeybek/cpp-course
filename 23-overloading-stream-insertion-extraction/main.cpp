#include <iostream>
#include "Mystring.h"

int main() {
    Mystring anil{"Anil"};
    Mystring zeynep{"Zeynep"};

    Mystring relation;
    std::cout << "Enter the relationship between these two people: ";
    std::cin >> relation;

    std::cout << anil << " " << relation << " " << zeynep << std::endl;
    return 0;
}
