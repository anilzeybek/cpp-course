#ifndef SHALLOW_H
#define SHALLOW_H

class Shallow {
private:
    int *num;
public:
    Shallow(int d);
    Shallow(const Shallow &source);
    ~Shallow();

    int get_num();
    void set_num(int num_val);
};

#endif
