#include "Mystring.h"

int main() {
    Mystring a{"Hello"};
    Mystring b;

    // Both of these will call move assignment since both are r-values
    // The reason of using move assignment for r values is,
    // its more efficient, because in copy constructor, we use create new memory area for copy purposes
    // because the original object's str shouldn't be released.
    // But in move constructor, we don't use new memory area, but use the created memory area
    // by r-value's initialization, and null the r-value's memory.
    // so we don't try to create new area again in memory, it becomes more efficient
    a = Mystring{"Hola"};
    a = "Merhaba";


    a.display();
    return 0;
}
