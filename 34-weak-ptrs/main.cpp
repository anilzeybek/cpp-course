#include <iostream>
#include <memory>

class B;

class A {
    std::shared_ptr<B> b_ptr;
public:
    void set_B(const std::shared_ptr<B> &b) {
        b_ptr = b;
    }

    A() { std::cout << "A constructor" << std::endl; }

    ~A() { std::cout << "A destructor" << std::endl; }
};


class B {
    // If this would be a shared_ptr instead of weak_ptr, there would be memory leak
    std::weak_ptr<A> a_ptr;
public:
    void set_A(const std::shared_ptr<A> &a) {
        a_ptr = a;
    }

    B() { std::cout << "B constructor" << std::endl; }

    ~B() { std::cout << "B destructor" << std::endl; }

};

int main() {
    // Now, we have a circular reference in these classes
    // Let's say class B's a_ptr is a shared pointer
    // Then, when the shared pointers try to delete, it cant because which one will be deleted first?
    // So we have a memory leak here
    // But if we declare it as a weak pointer, there will be no problem

    // Weak pointers are also shared pointers but they are weak so destroying them is not problem


    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->set_B(b);
    b->set_A(a);

    return 0;
}
