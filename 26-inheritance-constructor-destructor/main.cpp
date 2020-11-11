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
    using Base::Base; // This statement allows us to directly reach constructors of the base class
private:
    int doubled_value;

public:
    Derived() : doubled_value{0} { std::cout << "Derived no-args constructor" << std::endl; }

    // this constructor will call the no-args constructor of the base class, not int argument one
    Derived(int x) : doubled_value{2 * x} { std::cout << "Derived (int) overloaded constructor" << std::endl; }

    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main() {
    // Normally this would throw an exception if the Derived(int x) constructor is commented
    // But now it won't, because now it can use base class' constructor
    Derived d{20};


    return 0;
}
