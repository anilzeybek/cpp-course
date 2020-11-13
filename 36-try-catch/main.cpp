#include <iostream>

double calculate_kpl(int kilometers, int liters) {
    // We can throw anything with throw keyword, but best practice is to throw an object derived from std::exception
    if (liters == 0)
        throw 0;
    return static_cast<double>(kilometers) / liters;
}

int main() {
    int kilometers{}, liters{};

    std::cout << "Enter kilometers: ";
    std::cin >> kilometers;
    std::cout << "Enter  liters: ";
    std::cin >> liters;

    try {
        double kpl = calculate_kpl(kilometers, liters);
        std::cout << "Result: " << kpl << std::endl;

        // The argument in the catch block should be reference to thrown object
    } catch (int &ex) {
        std::cerr << "Tried to divide by 0" << std::endl;
    }

    std::cout << "Bye!" << std::endl;
    return 0;
}
