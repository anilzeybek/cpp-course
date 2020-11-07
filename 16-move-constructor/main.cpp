#include <iostream>
#include <vector>


class Move {
private:
    int *num;
public:
    void set_num(int d) { *num = d; }

    int get_num() { return *num; }

    Move(int d);

    // Deep copy constructor
    Move(const Move &source);

    // Move Constructor
    Move(Move &&source) noexcept;

    ~Move();
};

Move::Move(int d) {
    num = new int;
    *num = d;
    std::cout << "Constructor for: " << d << std::endl;
}

// Copy constructor
Move::Move(const Move &source)
        : Move{*source.num} {
    std::cout << "Copy constructor  - deep copy for: " << *num << std::endl;
}

// Move constructor
// This && symbol makes it reference for r values
// So in vector push, created object will be created in this constructor
// since the given values in push methods are r values
// We also null the values of r values to block its using memory
Move::Move(Move &&source) noexcept
        : num{source.num} {
    source.num = nullptr;
    std::cout << "Move constructor - moving resource: " << *num << std::endl;
}

Move::~Move() {
    if (num != nullptr)
        std::cout << "Destructor freeing num for: " << *num << std::endl;
    else
        std::cout << "Destructor freeing num for nullptr" << std::endl;

    delete num;
}

int main() {
    std::vector<Move> vec;

    // If we don't use move constructor, it will be very inefficient
    // Because each time we push a obj to our vector, it makes a deep copy in here
    // But we are creating a move constructor for this and it makes very efficient
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});


    return 0;
}