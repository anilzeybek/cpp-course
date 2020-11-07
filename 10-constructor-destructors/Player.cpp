#include "Player.h"
#include <iostream>
#include <string>


void Player::set_name(std::string name_val) {
    name = name_val;
}

Player::Player() {
    std::cout << "No args constructor called" << std::endl;
}

Player::Player(const std::string &name) {
    std::cout << "String arg constructor called" << std::endl;
}

Player::Player(const std::string &name, int health, int xp) {
    std::cout << "Three args constructor called" << std::endl;
}

Player::~Player() {
    std::cout << "Destructor called for " << name << std::endl;
}
