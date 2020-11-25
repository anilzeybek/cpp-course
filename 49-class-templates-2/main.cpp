#include <iostream>
#include <string>

// Now, user can specify the size of array
// We don't need to use typename always in templates
template <typename T, int N>
class Array {
    int size{N};
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[";
        for (const auto &val : arr.values) os << val << " ";
        os << "]" << std::endl;

        return os;
    }

   public:
    // This makes it the default constructor
    Array() = default;
    Array(T init_val) {
        for (auto &item : values) item = init_val;
    }

    void fill(T val) {
        for (auto &item : values) item = val;
    }

    int get_size() const { return size; }

    T &operator[](int index) { return values[index]; }
};

int main() {
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;

    // It will initially show garbage value
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[1] = 2000;
    std::cout << nums << std::endl;

    Array<std::string, 10> strings{"deno"};
    std::cout << "The size of strings is: " << strings.get_size() << std::endl;

    strings[0] = "Anil";
    std::cout << strings << std::endl;

    return 0;
}