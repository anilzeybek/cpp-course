#include <iostream>
// Those vector, set, map and list are all containers
#include <list>
#include <map>
#include <set>
#include <vector>

void display(const std::vector<int> &vec) {
    std::cout << "[";
    for (const auto &i : vec) std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n=====================\n" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};

    auto it = nums1.begin();
    std::cout << *it << std::endl;  // 1

    it++;
    std::cout << *it << std::endl;  // 2

    it += 2;
    std::cout << *it << std::endl;  // 4

    it = nums1.end() - 1;
    std::cout << *it << std::endl;  // 5
}

void test2() {
    std::cout << "\n=====================\n" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};

    std::vector<int>::iterator it = nums1.begin();
    while (it != nums1.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;
        it++;
    }

    display(nums1);
}

void test3() {
    std::cout << "\n=====================\n" << std::endl;
    std::vector<int> nums1{1, 2, 3, 4, 5};

    std::vector<int>::const_iterator it1 = nums1.begin();
    // or we can write as: auto it1 = nums1.cbegin();

    while (it1 != nums1.cend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    // It would throw error if we try to make something like *it1 = 0;
}

void test4() {
    std::cout << "\n=====================\n" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    auto it1 = vec.rbegin();
    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    std::list<std::string> name{"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin();
    std::cout << *it2 << std::endl;
    it2++;
    std::cout << *it2 << std::endl;

    std::map<std::string, std::string> favorites{
        {"Frank", "C++"}, {"Bill", "Java"}, {"James", "Haskell"}};
    auto it3 = favorites.begin();
    while (it3 != favorites.end()) {
        std::cout << it3->first << ": " << it3->second << std::endl;
        it3++;
    }
}

int main() {
    test1();
    test2();
    test3();
    test4();

    return 0;
}