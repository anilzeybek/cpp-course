#include <iostream>
#include <string>
#include <sstream>

int main() {
    int num{};
    double total{};
    std::string name{};

    std::string info{"Moe 100 1234.5"};
    std::stringstream in_ss{info};

    in_ss >> name >> num >> total;
    std::cout << name << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;


    std::cout << "\n==============\n" << std::endl;


    std::stringstream out_ss{};
    out_ss << "Deno " << 1234 << " asdasd" << std::endl;

    std::cout << out_ss.str() << std::endl;

    return 0;
}