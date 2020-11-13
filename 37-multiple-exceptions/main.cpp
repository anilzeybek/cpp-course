#include <iostream>
#include <string>

double calculate_kpl(int kilometers, int liters) {
    if (liters == 0)
        throw 0;
    if (kilometers < 0 || liters < 0)
        throw std::string{"Negative value error"};
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

    } catch (int &ex) {
        std::cerr << "Tried to divide by 0" << std::endl;
    } catch (std::string &ex) {
        std::cerr << ex << std::endl;
    } catch (...) {
        // This ... means catch any exceptions here
        std::cerr << "Some undefined error occurred" << std::endl;
    }

    std::cout << "Bye!" << std::endl;
    return 0;
}
