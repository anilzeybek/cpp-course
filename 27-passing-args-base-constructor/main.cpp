#include <iostream>

class Base {
private:
    int value;
public:
    Base() : value{0} { std::cout << "Base no-args constructor" << std::endl; }

    Base(int x) : value{x} { std::cout << "Base (int) overloaded constructor" << std::endl; }

    ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
private:
    int doubled_value;

public:
    // this will call base class' no-arg constructor
    Derived() : Base{}, doubled_value{0} { std::cout << "Derived no-args constructor" << std::endl; }

    // this will call base class' int-arg constructor
    Derived(int x) : Base{x}, doubled_value{2 * x} { std::cout << "Derived (int) overloaded constructor" << std::endl; }

    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main() {
    Derived d{20};

    return 0;
}
