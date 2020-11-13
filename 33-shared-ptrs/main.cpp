#include <iostream>
#include <memory>

int main() {
    // Shared pointer is the smart pointer that allows copy and assignment unlike unique pointer
    // Its still frees all memory areas when they go out of scope and no memory leak chance
    // We can use use_count() method to see how many times that area pointed

    std::shared_ptr<int> p1{new int{100}};
    std::cout << "Use count: " << p1.use_count() << std::endl;

    // We can't do the following in unique pointer, we have to move it if we want to
    std::shared_ptr<int> p2{p1};
    std::cout << "Use count: " << p1.use_count() << std::endl;

    p1.reset();
    std::cout << "Use count: " << p1.use_count() << std::endl;
    std::cout << "Use count: " << p2.use_count() << std::endl;

    // This is the preferred way to create shared pointers
    // Its in c++11 and more efficient
    std::shared_ptr<int> ptr = std::make_shared<int>(100);


    return 0;
}
