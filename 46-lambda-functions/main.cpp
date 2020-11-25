#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// Second arg of this function is a function that takes an int and returns void
void forEach(const std::vector<int>& values,
             const std::function<void(int)>& func) {
    for (int value : values) func(value);
}

int main() {
    std::vector<int> values{1, 5, 4, 2, 3};

    std::string name{"I'm looking for: "};

    // Second arg we send to forEach function is a lambda function
    // In [] part, captures goes. Like an variable to use in our function
    // We are not changing name here, but if we want to, we need to specify
    // the lambda as mutable after the arguments (before the body)
    forEach(values,
            [&name](int value) { std::cout << name << value << std::endl; });

    std::cout << "\n=================\n" << std::endl;

    // This find_if method takes a iterator begin, iterator end,
    // and a lambda function that takes value of iterator, returns bool
    // Then find_if returns the first element that becomes true in lambda
    // In this case, it should be 5.
    auto it = std::find_if(values.begin(), values.end(),
                           [](int value) { return value > 3; });

    std::cout << *it << std::endl;

    return 0;
}