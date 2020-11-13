#include <iostream>
#include <memory>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }

    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }

    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }

    int get_data() const { return data; }
};

// it has to return void, and argument must be the raw pointer
void my_deleter(Test *ptr) {
    std::cout << "Using my custom deleter function for Test objects" << std::endl;
    delete ptr;
}


int main() {
    // Custom deleters are as the name suggests, the custom functions that called
    // when the given smart pointer has to die. This isn't used very often

    {
        // Custom deleter using a function
        std::shared_ptr<Test> ptr1{new Test{100}, my_deleter};
    }

    {
        // Custom deleter using a lambda
        std::shared_ptr<Test> ptr2{new Test{200}, [](Test *ptr) {
            std::cout << "Using my custom deleter lambda for Test objects" << std::endl;
            delete ptr;
        }};
    }

    return 0;
}
