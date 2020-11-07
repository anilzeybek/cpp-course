#include <iostream>
#include <string>


class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    // Making this method const means in this method, we will not change anything
    std::string get_name() const;

    void set_name(std::string name_val);

    Player();

    Player(std::string name_val);

    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
        : Player{"None", 0, 0} {
}

Player::Player(std::string name_val)
        : Player{name_val, 0, 0} {
}

Player::Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val} {
}

std::string Player::get_name() const {
    return name;
}

void Player::set_name(std::string name_val) {
    name = name_val;
}

void display_player_name(const Player &p) {
    std::cout << p.get_name() << std::endl;
}

int main() {
    const Player villain{"Villain", 100, 55};
    Player hero{"Hero", 100, 15};

    // The get_name method for villain would not compile if we didn't have const qualifier in that method
    // Because compiler thinks there can be modification and doesn't allow that
    std::cout << villain.get_name() << std::endl;
    std::cout << hero.get_name() << std::endl;

    display_player_name(villain);
    display_player_name(hero);


    return 0;
}

