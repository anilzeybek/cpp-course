#include <iostream>
#include <string>

// Template classes are typically completely contained in header files
// So, we would have the template class in Item.h and no Item.cpp file
// would be used
template <typename T>
class Item {
   private:
    std::string name;
    T value;

   public:
    Item(std::string name, T value) : name{name}, value{value} {}

    std::string get_name() const { return name; }

    T get_value() const { return value; }
};

template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};

int main() {
    Item<int> item1{"Anil", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2{"Anil", "Professor"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;

    Item<Item<int>> item3{"Deniz", {"Zeybek", 17}};
    std::cout << item3.get_name() << " " << item3.get_value().get_name() << " "
              << item3.get_value().get_value() << std::endl;


    My_Pair <std::string, int> p1 {"Anil", 22};
    std::cout << p1.first << " " << p1.second << std::endl;
    return 0;
}