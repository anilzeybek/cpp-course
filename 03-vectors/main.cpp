#include <iostream>
#include <vector>

int main() {
    // std::vector<char> vowels; // empty
    // std::vector<char> vowels(5); // 5 elements

    std::vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    std::cout << vowels[2] << std::endl;

    // std::vector<int> test_scores(3); // 3 elements, all initialized to 0
    std::vector<int> test_scores(3, 5); // 3 elements, all initialized to 5
    std::cout << test_scores.size() << std::endl; // that would print 3, since there are 3 elements

    test_scores.push_back(6);
    std::cout << test_scores.size() << std::endl; // now, it would print 4 because we added new element

    std::vector<std::vector<int>> movie_ratings{
            {1, 2, 3, 4},
            {1, 2, 4, 4},
            {1, 3, 4, 5}
    };

    std::cout << movie_ratings[0][1] << std::endl; // prints 2
    std::cout << movie_ratings.at(0).at(1) << std::endl; // same as above, prints 2

    return 0;
}
