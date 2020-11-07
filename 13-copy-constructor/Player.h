#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
private:
    std::string name{};
    int health{};
    int xp{};

public:
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

    // Copy constructor
    Player(const Player &source);

    ~Player();

    std::string get_name();

    int get_health();

    int get_xp();
};


#endif
