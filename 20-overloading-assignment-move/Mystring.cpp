#include "Mystring.h"
#include <cstring>
#include <iostream>

Mystring::Mystring() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s) : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source) : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) : str{source.str} {
    source.str = nullptr;
}


Mystring::~Mystring() {
    delete[] str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;
    if (this == &rhs)
        return *this;

    delete[] str;
    // in here, we create a new memory area
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;

    delete[] str;
    str = rhs.str;
    // we null the r-value's str
    rhs.str = nullptr;

    return *this;
}

void Mystring::display() const {
    std::cout << str << " : " << length() << std::endl;
}

int Mystring::length() const {
    return std::strlen(str);
}

const char *Mystring::get_str() const {
    return str;
}

