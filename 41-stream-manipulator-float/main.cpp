#include <iostream>
#include <iomanip>

int main() {
    double num1{123456789.987654321};
    double num2{1234.5678};
    double num3{1234.0};

    // The precision is 6 by default and if we exceed the precision, then it will shown as scientific
    // And its always rounded, so for num2, instead of 1234.56, 1234.57
    std::cout << "Defaults:" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "=========" << std::endl;

    std::cout << std::setprecision(2);
    std::cout << "Precision 2:" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    std::cout << std::setprecision(9);
    std::cout << "Precision 9:" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    std::cout << "=========" << std::endl;

    // If we set to fixed, then precision will only occur only after decimal point
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << "Precision 3 with fixed:" << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;


    return 0;
}
