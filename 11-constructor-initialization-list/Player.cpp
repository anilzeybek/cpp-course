#include "Player.h"
#include <iostream>
#include <string>


Player::Player() : name{"None"}, health{0}, xp{0} {
}

Player::Player(const std::string &name_val) : name{name_val}, health{0}, xp{0} { // This is better in performance
    std::cout << "String arg constructor called" << std::endl;
}

Player::Player(const std::string &name_val, int health_val, int xp_val) : name{name_val}, health{health_val},
                                                                          xp{xp_val} {
    std::cout << "Three args constructor called" << std::endl;
}

Player::~Player() {
    std::cout << "Destructor called for " << name << std::endl;
}
