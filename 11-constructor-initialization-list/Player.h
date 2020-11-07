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
    Player();

    Player(const std::string &name);

    Player(const std::string &name, int health, int xp);

    ~Player();
};


#endif
