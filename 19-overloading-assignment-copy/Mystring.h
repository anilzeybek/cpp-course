#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring {
private:
    char *str;
public:
    Mystring();

    Mystring(const char *s);

    Mystring(const Mystring &source);

    ~Mystring();

    Mystring &operator=(const Mystring &rhs); // Copy assignment

    void display() const;

    int length() const;

    const char *get_str() const;
};

#endif
