#include <iostream>
#include "Mystring.h"

int main() {
    Mystring anil{"Anil"};
    Mystring zeynep{"Zeynep"};

    std::cout << std::boolalpha;
    std::cout << (anil == zeynep) << std::endl;
    std::cout << (zeynep == "Zeynep") << std::endl;


    Mystring love = anil + zeynep;
    love.display();

    Mystring lowerAnil = -anil;
    lowerAnil.display();

    return 0;
}
