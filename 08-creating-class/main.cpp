#include <iostream>
#include <vector>
#include <string>

class Player {
public:
    // attributes
    std::string name{"Player"};
    int health{100};
    int xp{0};

    // methods
    void talk(const std::string &text_to_say) {
        std::cout << name << " says " << text_to_say << std::endl;
    }

    bool is_dead();
};

int main() {
    Player frank;
    Player hero;

    frank.name = "Frank";
    std::cout << frank.name << std::endl;
    frank.talk("greetings");

    std::vector<Player> player_vec{frank};
    player_vec.push_back(hero);


    auto *enemy = new Player;
    enemy->name = "Venom";
    enemy->talk("I will destroy you!");
    delete enemy;

    return 0;
}
