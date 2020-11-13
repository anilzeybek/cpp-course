#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }

    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }

    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }

    int get_data() const { return data; }
};

// ALL SMART POINTERS ARE INITIALIZED TO NULLPTR, NOT TO A GARBAGE MEMORY AREA LIKE RAW POINTERS
int main() {
    // This is default way to create pointers, but they require deleting after using
    // Or there would be a memory leak!
    // Test *t1 = new Test{1000};
    // delete t1;


    // Now, we don't need to call delete for t1, since its a smart pointer
    // Its also on heap like raw pointers, but there is now memory leak chance
    std::unique_ptr<Test> t1{new Test{100}};
    std::cout << "----------\n" << std::endl;

    // This is c++14 way of creating unique pointers
    // This should be the preferred way to create unique pointers and its more efficient
    // Also we can print the object's memory address using the get() method provided by unique pointer
    std::unique_ptr<Test> t2 = std::make_unique<Test>(200);
    std::cout << t2.get() << std::endl;
    std::cout << "----------\n" << std::endl;


    // The following will make t3 nullptr and delete it
    auto t3 = std::make_unique<Test>(300);
    t3.reset();
    std::cout << "----------\n" << std::endl;


    // We can't do the following assignment because there is no assignment operator for unique pointers
    // t2 = t1;


    // to push these smart pointers to vectors, we need to use std::move
    // because there is no copy constructor for unique_ptr
    // since its unique, and only one pointer can reference to that area
    std::vector<std::unique_ptr<Test>> unique_ptr_vector;
    unique_ptr_vector.push_back(std::move(t1));
    unique_ptr_vector.push_back(std::move(t2));


    // Now, the following expression will print true, because t1 is now a nullptr, like reset() method called
    // Since its moved to vector
    std::cout << std::boolalpha;
    std::cout << (t1 == nullptr) << std::endl;
    std::cout << "----------\n" << std::endl;


    // i here must be reference object because otherwise we would be call the copy constructor
    // which doesn't exist for unique pointers
    for (const auto &i : unique_ptr_vector)
        std::cout << i->get_data() << std::endl;


    // In here, we don't need to delete these pointers, they are automatically deleted
    std::cout << "----------\n" << std::endl;

    return 0;
}
