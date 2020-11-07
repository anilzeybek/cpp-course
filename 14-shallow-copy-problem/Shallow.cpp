#include "Shallow.h"
#include <iostream>

Shallow::Shallow(int d) {
    num = new int;
    *num = d;
}

Shallow::Shallow(const Shallow &source) : num{source.num} {
    std::cout << "Copy constructor - shallow copy" << std::endl;
}

Shallow::~Shallow() {
    delete num;
    std::cout << "Destructor freeing data" << std::endl;
}

int Shallow::get_num() {
    return *num;
}

void Shallow::set_num(int num_val) {
    *num = num_val;
}

