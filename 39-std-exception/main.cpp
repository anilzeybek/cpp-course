#include <iostream>

class DivideByZeroException : public std::exception {
public:
    DivideByZeroException() noexcept = default;

    // Destructor methods are noexcept by default
    // Throwing any exceptions from destructors can't be catch, so it shouldn't used
    ~DivideByZeroException() override = default;

    // This what method is pure virtual function defined in std::exception
    // We should create our own custom exceptions like this
    const char *what() const noexcept override {
        return "Divide by 0 exception";
    }
};

double calculate_kpl(int kilometers, int liters) {
    if (liters == 0)
        throw DivideByZeroException();
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
    } catch (DivideByZeroException &ex) {
        std::cerr << ex.what() << std::endl;
    } catch (...) {
        std::cerr << "Some undefined error occurred" << std::endl;
    }

    std::cout << "Bye!" << std::endl;
    return 0;
}
