#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

void display_array(const std::array<int, 5> &arr) {
    std::cout << "[ ";
    for (const auto &i: arr) std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1=====================" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};

    // This will have 0 initially
    std::array<int, 5> arr2{};

    display_array(arr1);
    display_array(arr2);

    std::cout << "Size of arr1: " << arr1.size() << std::endl;
    std::cout << "Size of arr2: " << arr2.size() << std::endl;

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display_array(arr1);

    std::cout << "Front of arr1: " << arr1.front() << std::endl;
    std::cout << "Back of arr1: " << arr1.back() << std::endl;
}

void test2() {
    std::cout << "\nTest2=====================" << std::endl;
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    // This data gives us underlying raw data
    // We shouldn't use it but some libraries require them, so we may need them
    int *ptr = arr.data();
    std::cout << ptr << std::endl;
    *ptr = 255;

    display_array(arr);
}

void test3() {
    std::cout << "\nTest3=====================" << std::endl;
    std::array<int, 5> arr{4, 2, 5, 1, 3};
    display_array(arr);

    // We can use STL algorithms with std::array
    std::sort(arr.begin(), arr.end());
    display_array(arr);
}

void test4() {
    std::cout << "\nTest4=====================" << std::endl;
    std::array<int, 5> arr{4, 2, 5, 1, 3};

    std::array<int, 5>::iterator min_num =
            std::min_element(arr.begin(), arr.end());
    auto max_num = std::max_element(arr.begin(), arr.end());

    std::cout << "min: " << *min_num << ", max: " << *max_num << std::endl;
}

void test5() {
    std::cout << "\nTest4=====================" << std::endl;
    std::array<int, 5> arr{4, 2, 5, 1, 3};

    // Sum all of them with initial value 0
    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    std::cout << "Sum of elements in arr: " << sum << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}