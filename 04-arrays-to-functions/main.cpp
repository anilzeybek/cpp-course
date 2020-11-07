#include <iostream>


void print_array(const int arr[], size_t size);

void set_array(int arr[], size_t size, int value);

// const makes it produce error if we try to change
// because arrays are passed by reference, since its only a memory location actually
void print_array(const int arr[], size_t size) {
    for (size_t i{0}; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    // arr[0] = 50000; // bug
}

// set each array element to value
// we also have to send the size info, otherwise we can't iterate
void set_array(int arr[], size_t size, int value) {
    for (size_t i{0}; i < size; ++i)
        arr[i] = value;
}

int main() {
    int my_scores[]{100, 98, 90, 86, 84};

    print_array(my_scores, 5);
    set_array(my_scores, 5, 100);
    print_array(my_scores, 5);
    print_array(my_scores, 5);

    std::cout << std::endl;
    return 0;
}

