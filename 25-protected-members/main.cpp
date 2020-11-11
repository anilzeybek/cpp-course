#include <iostream>

class Base {
    // friends of this class have access to everything
public:
    int a{0};

    void display() { std::cout << a << ", " << b << ", " << c << std::endl; }

protected:
    int b{0};

private:
    int c{0};

};

class Derived : public Base {
public:
    void access_base_members() {
        a = 100;
        b = 200;
//      c = 300 // compiler error
    }
};

int main() {
    Base base;
    base.a = 100;
//  base.b = 200; // compiler error
//  base.c = 300;

    Derived d;
    d.a = 100;
//  d.b = 200; // compiler error
//  d.c = 300;

    return 0;
}
