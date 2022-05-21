#include <iostream>
#include <vector>

void helloWorld(int a) {
    std::cout << "Hello World! Value: " << a << std::endl;
}

void printValue(int value) { std::cout << value << std::endl; }

// Second arg of this function is a function that takes an int and returns void
void forEach(const std::vector<int> &values, void (*func)(int)) {
    for (int value: values) func(value);
}

int main() {
    // The actual type of func is: void (*func)(int a)
    auto func = helloWorld;
    func(1);
    func(2);

    std::cout << "\n================\n" << std::endl;

    std::vector<int> values{1, 5, 4, 2, 3};
    forEach(values, printValue);

    // We could also do same thing better with lambda functions, like this:
    // forEach(values, [](int value) { std::cout << value << std::endl; });

    return 0;
}
