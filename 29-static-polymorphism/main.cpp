#include <iostream>

class Base {
public:
    void say_hello() const {
        std::cout << "Hello, I'm a Base class object" << std::endl;
    }
};

class Derived : public Base {
public:
    void say_hello() const {
        std::cout << "Hello, I'm a Derived class object" << std::endl;
    }
};


// In this example, whatever Base object comes, it will always call the Base class' say_hello method
// This is because of static binding (compile time binding), not dynamic binding and we will solve this problem
// in future examples
void greetings(const Base &obj) {
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main() {
    Base b;
    greetings(b);

    Derived d;
    greetings(d);

    // The example below is also a problem, we want it to say I'm a Derived class object but it says
    // I'm a Base class object
    Base *ptr = new Derived();
    ptr->say_hello();

    delete ptr;

    return 0;
}
