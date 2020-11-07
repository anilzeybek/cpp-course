#include "Player.h"
#include <iostream>
#include <string>


Player::Player() : Player("None", 0, 0) { // This also executes code inside the delegated constructor
    std::cout << "No arg constructor called" << std::endl;
}

Player::Player(const std::string &name_val) : Player(name_val, 0, 0) {
    std::cout << "String arg constructor called" << std::endl;
}

Player::Player(const std::string &name_val, int health_val, int xp_val) : name{name_val}, health{health_val},
                                                                          xp{xp_val} {
    std::cout << "Three args constructor called" << std::endl;
}

Player::~Player() {
    std::cout << "Destructor called for " << name << std::endl;
}
