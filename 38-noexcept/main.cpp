#include <iostream>

// Since this function has noexcept keyword in its declaration
// It means this method won't throw any exceptions
double calculate_kpl(int kilometers, int liters) noexcept {
    return static_cast<double>(kilometers) / liters;
}

int main() {
    std::cout << calculate_kpl(12, 5) << std::endl;
    return 0;
}
