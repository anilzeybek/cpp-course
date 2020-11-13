#include <string>
#include "Player.h"
#include "Test.h"


int main() {
    {
        // Using default constructor and destructor
        Test test;
    }

    {
        Player slayer;
        slayer.set_name("Slayer");
    }

    {
        Player frank;
        frank.set_name("Frank");
        Player hero("Hero");
        hero.set_name("Hero");
        Player villain("Villain", 100, 12);
        villain.set_name("Villain");
    }

    auto *enemy = new Player;
    enemy->set_name("Enemy");

    auto *level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Level Boss");

    delete enemy;
    delete level_boss;

    return 0;
}

