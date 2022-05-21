#include <iostream>
#include "Shallow.h"

// THIS PROGRAM WILL CRASH

// When this method is called, it will create new shallow s, with using copy constructor
// Then at the end of this method, this object's destructor will be called, and it will delete its num
// But since we used raw pointers, the real obj1's num will also be released in memory,
// and it is the below when we try to reach the same place again, it will crash;
void display_shallow(Shallow s) {
    std::cout << s.get_num() << std::endl;
}

int main() {
    Shallow obj1{100};
    display_shallow(obj1);

    obj1.set_num(200);

    return 0;
}
