#include "Player.h"
#include <iostream>
#include <string>


Player::Player(std::string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
    std::cout << "Normal constructor called for " << name << std::endl;
}

// we could use delegating here, but just for not seeing the output, we didn't
Player::Player(const Player &source) : name{source.name}, health{source.health}, xp{source.xp} {
    std::cout << "Copy constructor - made copy of: " << source.name << std::endl;
}

Player::~Player() {
    std::cout << "Destructor called for " << name << std::endl;
}

std::string Player::get_name() { return name; }

int Player::get_health() { return health; }

int Player::get_xp() { return xp; }