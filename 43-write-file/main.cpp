#include <iostream>
#include <fstream>

int main() {
    // By default, if file doesn't exists, it creates, and if exists, deletes the content
    // If std::ios::app given, appends instead of deleting content, still creates file if not exists
    std::ofstream out_file{"../file.txt", std::ios::app};
    if (!out_file) {
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Enter something to write to file: ";
    std::cin >> line;

    out_file << line << std::endl;
    std::cout << line << " appended to file." << std::endl;

    out_file.close();


    std::cout << "\n==============\n" << std::endl;


    std::ifstream poem{"../../42-read-file/poem.txt"};
    std::ofstream copied_file{"../peom_copy.txt"};

    if (!poem) {
        std::cerr << "Error opening poem file" << std::endl;
        return 1;
    }

    if (!copied_file) {
        std::cerr << "Error opening copy file" << std::endl;
        return 1;
    }

    while (std::getline(poem, line)) {
        copied_file << line << std::endl;
    }

    std::cout << "Copy finished" << std::endl;

    poem.close();
    copied_file.close();

    return 0;
}