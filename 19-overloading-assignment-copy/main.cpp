#include "Mystring.h"

int main() {
    Mystring a{"Hello"};
    Mystring b;

    // If we don't didn't overload the assignment operator, this would result an error
    // In here, b's str and a's str is in different locations
    b = a;

    // In here, actually "deno" is not a Mystring object, its a const char*
    // But compiler thinks its a new object and creates a object from it with calling the constructor
    // so "deno" becomes Mystring temp{"deno"} actually
    b = "deno";
    b.display();

    return 0;
}
