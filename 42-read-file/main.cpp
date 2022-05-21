#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;

    std::string line{};
    int num;
    double total;

    in_file.open("../test.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    // File is ready to read

    // this will extract based on whitespace or newline
    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;

    in_file.close();


    std::cout << "\n==============\n" << std::endl;


    std::ifstream in_file2;
    in_file2.open("../test2.txt");

    if (!in_file2) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    // this eof method will return true if we completed reading the file, otherwise false
    while (!in_file2.eof()) {
        in_file2 >> line >> num >> total;

        std::cout << line << std::endl;
        std::cout << num << std::endl;
        std::cout << total << std::endl;
    }

    in_file2.close();


    std::cout << "\n==============\n" << std::endl;


    // We can also open file just like that:
    std::ifstream in_file3{"../poem.txt"};

    if (!in_file3) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    while (std::getline(in_file3, line)) {
        std::cout << line << std::endl;
    }

    in_file3.close();
    return 0;
}