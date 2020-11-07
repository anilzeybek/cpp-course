#include <iostream>
#include <string>
#include "Player.h"


void display_active_players() {
    // this is the way to call static methods
    std::cout << "Active players: " << Player::get_num_players() << std::endl;
}

int main() {
    display_active_players();
    Player hero{"Hero"};
    display_active_players();

    auto *enemy = new Player("Enemy", 100, 100);
    display_active_players();

    delete enemy;
    display_active_players();


    return 0;
}

