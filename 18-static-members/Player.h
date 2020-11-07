#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
private:
    static int num_players;

    std::string name;
    int health;
    int xp;
public:
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

    Player(const Player &source);

    ~Player();

    static int get_num_players();

    std::string get_name() const;

    int get_health() const;

    int get_xp() const;

    void set_name(std::string name_val);
};

#endif
