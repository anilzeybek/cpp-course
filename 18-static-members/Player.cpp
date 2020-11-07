#include "Player.h"

// this is the way to assign values to static variables
int Player::num_players{0};

Player::Player(std::string name_val, int health_val, int xp_val)
        : name{name_val}, health{health_val}, xp{xp_val} {
    ++num_players;
}

Player::Player(const Player &source) : Player{source.name, source.health, source.xp} {}

Player::~Player() {
    --num_players;
}

int Player::get_num_players() {
    return num_players;
}


std::string Player::get_name() const {
    return name;
}

int Player::get_health() const {
    return health;
}

int Player::get_xp() const {
    return xp;
}

void Player::set_name(std::string name_val) {
    name = name_val;
}

