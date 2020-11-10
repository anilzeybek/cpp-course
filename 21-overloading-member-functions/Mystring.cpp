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
    rhs.str = nullptr;

    return *this;
}

Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, this->str);

    for (size_t i{0}; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);

    Mystring temp{buff};
    delete[] buff;

    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(this->str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);

    Mystring temp{buff};
    delete[] buff;
    return temp;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) == 0);
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

