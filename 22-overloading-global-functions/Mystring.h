#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);

    friend Mystring operator-(const Mystring &obj);

    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

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


    void display() const;

    int length() const;

    const char *get_str() const;
};

#endif
