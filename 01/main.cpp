#include <iostream>

int main() {
    int favNumber = 0;
    std::cout << "What's your favorite number? ";
    std::cin >> favNumber;

    if (favNumber == 24) {
        std::cout << "That's my favorite number too!" << std::endl;
    } else {
        std::cout << "Nice, my favourite number is 24!" << std::endl;
    }
    return 0;
}
