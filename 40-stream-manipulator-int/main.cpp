#include <iostream>

int main() {
    int num{255};

    // print in decimal, this is default
    std::cout << std::dec << num << std::endl;
    // print in hexadecimal
    std::cout << std::hex << num << std::endl;
    // print in octal - base8
    std::cout << std::oct << num << std::endl;

    std::cout << "===========" << std::endl;

    // If we want to show their base prefix (notice decimal one will not show anything as it should be):
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "===========" << std::endl;

    // If we want to see the chars in hex uppercase, this wont effect decimal or octal:
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;


    // All the showbase, uppercase and hex,dex,oct manipulators are until the end of program

    return 0;
}
