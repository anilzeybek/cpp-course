#include <algorithm>
#include <cctype>
#include <iostream>
#include <list>
#include <vector>

class Person {
    std::string name;
    int age;

   public:
    Person() = default;
    Person(std::string name, int age) : name{name}, age{age} {}

    bool operator<(const Person &rhs) const { return this->age < rhs.age; }

    bool operator==(const Person &rhs) const {
        return this->name == rhs.name && this->age == rhs.age;
    }
};

void find_test() {
    std::cout << "\n================\n" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    auto loc1 = std::find(vec.begin(), vec.end(), 1);

    if (loc1 != vec.end())
        std::cout << "Found the number:" << *loc1 << std::endl;
    else
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Person> players{{"Anil", 22}, {"Deniz", 17}, {"Hasan", 51}};
    auto loc2 = std::find(players.begin(), players.end(), Person{"Deniz", 17});

    if (loc2 != players.end())
        std::cout << "Found Deniz" << std::endl;
    else
        std::cout << "Couldn't find Deniz" << std::endl;
}

void count_test() {
    std::cout << "\n================\n" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 1, 3, 5, 1};

    // Here, we are looking how many elements with value "1" are there
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurences found" << std::endl;
}

void count_if_test() {
    std::cout << "\n================\n" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // This method counts the ones that return true in given func
    int evenNumbers =
        std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });

    std::cout << evenNumbers << " even numbers found" << std::endl;
}

void replace_test() {
    std::cout << "\n================\n" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 5, 4, 3, 2, 1};

    // This method replaces given number with other number
    std::replace(vec.begin(), vec.end(), 4, 400);
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;
}

void all_of_test() {
    std::cout << "\n================\n" << std::endl;
    std::vector<int> vec{3, 4, 5, 5, 4, 3};

    // checks all elements return true from the func
    if (std::all_of(vec.begin(), vec.end(), [](int x) { return x >= 3; }))
        std::cout << "All elements are >= 3" << std::endl;

    else
        std::cout << "All elements are not >= 3" << std::endl;
}

void string_transform_test() {
    std::cout << "\n================\n" << std::endl;

    std::string str{"This is a test"};

    // 3rd arg is where to start placing results
    std::transform(str.begin(), str.end(), str.begin(), toupper);
    std::cout << str << std::endl;
}

int main() {
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();

    return 0;
}