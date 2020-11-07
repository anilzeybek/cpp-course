#include <iostream>

class Deep {
private:
    int *num;
public:
    void set_data_value(int d) { *num = d; }

    int get_data_value() { return *num; }

    Deep(int d);

    Deep(const Deep &source);

    ~Deep();
};

Deep::Deep(int d) {
    num = new int;
    *num = d;
}


// Comparing to shallow copy, in here we only copy the value inside the pointer
// So there will be new int object for the new copy object
// And after deleting, original object's num will remain
Deep::Deep(const Deep &source)
        : Deep{*source.num} {
    std::cout << "Copy constructor - deep copy" << std::endl;
}

Deep::~Deep() {
    delete num;
    std::cout << "Destructor freeing num" << std::endl;
}

void display_deep(Deep s) {
    std::cout << s.get_data_value() << std::endl;
}

int main() {
    Deep obj1{100};
    display_deep(obj1);

    obj1.set_data_value(200);
    return 0;
}

