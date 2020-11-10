#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
private:
    char *str;
public:
    Mystring();

    Mystring(const char *s);

    Mystring(const Mystring &source); // Copy constructor

    Mystring(Mystring &&source); // Move constructor

    ~Mystring(); // Destructor

    Mystring &operator=(const Mystring &rhs); // Copy assignment

    Mystring &operator=(Mystring &&rhs); // Move assignment

    Mystring operator-() const; // unary operator, make lowercase

    Mystring operator+(const Mystring &rhs) const; // binary operator, concat

    bool operator==(const Mystring &rhs) const; // binary operator

    void display() const;

    int length() const;

    const char *get_str() const;
};

#endif
