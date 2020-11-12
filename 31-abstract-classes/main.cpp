#include <iostream>


// This is an abstract class
// Any class with a pure virtual function is an abstract class
// Only one pure virtual function is enough, and its created by = 0 initialization

// In addition, since this class only has pure virtual functions, its an interface
class Shape {
public:
    virtual void draw() = 0; // pure virtual function

    virtual void rotate() = 0; // pure virtual function

    virtual ~Shape() { std::cout << "Destroying Shape" << std::endl; }

};

// Any concrete class deriving from abstract class has to override all pure virtual functions
// Otherwise they would also be an abstract class
class Line : public Shape {
public:
    void draw() override {
        std::cout << "Drawing line" << std::endl;
    }

    void rotate() override {
        std::cout << "Rotating line" << std::endl;
    }

    ~Line() override { std::cout << "Destroying line" << std::endl; }

};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing circle" << std::endl;
    }

    void rotate() override {
        std::cout << "Rotating circle" << std::endl;
    }

    ~Circle() override { std::cout << "Destroying circle" << std::endl; }
};



int main() {
    // Shape shape;  // This will not work because Shape is an abstract class

    Line line;
    line.draw();

    Shape *circle = new Circle;
    circle->rotate();

    delete circle;

    return 0;
}
