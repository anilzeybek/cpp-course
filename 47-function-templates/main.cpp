#include <iostream>

struct Person {
    std::string name;
    int age;

    // This operator overloading can be written outside the struct
    bool operator<(const Person &rhs) const { return this->age < rhs.age; }
};

// Since the left hand side is std::ostream,
// we can't write this inside the struct
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name;
    return os;
}

// This method's arguments can be anything like int, float, char,
// Or any type that supports operator "<"
template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

// This method takes 2 types and prints them
template <typename T1, typename T2>
void func(T1 arg1, T2 arg2) {
    std::cout << arg1 << " " << arg2 << std::endl;
}

int main() {
    std::cout << min<int>(2, 3) << std::endl;
    std::cout << min<double>(32.6, 6.1) << std::endl;
    func<char, double>('a', 22.7);

    // Compiler can also understand and if it can understand,
    // we don't need to specify the types like here:
    std::cout << min(2.8, 3.5) << std::endl;
    func('f', 3.14);

    // We can use our types if we support the operators:
    Person p1{"Anil", 22};
    Person p2{"Deniz", 17};

    func(p1, p2);
    std::cout << min(p1, p2) << std::endl;

    return 0;
}