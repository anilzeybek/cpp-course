#include <iostream>

class Base {
public:

    // Since there is a virtual function, there must be virtual destructor!
    // If there is no virtual destructor, then deleting the pointer below
    // would not call the destructor for derived class which is a HUGE problem!!!
    virtual void say_hello() const {
        std::cout << "Hello, I'm a Base class object" << std::endl;
    }

    virtual ~Base() { std::cout << "Base::destructor" << std::endl; }
};

class Derived : public Base {
public:

    // Now, there will not be the problem since the base class's function is virtual
    // And we use override keyword for the override functions
    void say_hello() const override {
        std::cout << "Hello, I'm a Derived class object" << std::endl;
    }

    ~Derived() override { std::cout << "Derived::destructor" << std::endl; }

};

// This method will use dynamic binding instead of static binding,
// So it will run as we want it to
void greetings(const Base &obj) {
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main() {
    Base b;
    greetings(b);

    Derived d;
    greetings(d);

    Base *ptr = new Derived();
    ptr->say_hello();

    delete ptr;

    return 0;
}
