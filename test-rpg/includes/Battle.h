#ifndef BATTLE_H
#define BATTLE_H

// Custom Headers
#include "Standard.h"
#include "Character.h"
#include "MathEngine.h"
#include <FileSystem.h>

// Standard Headers
#include <iostream>

namespace rpgText
{
    // Prints the start of an enemy encounter
    void print_encounter(Enemy &enemy, std::string playerName);

    // Prints the battle state
    void print_battle(Player &player, Enemy &enemy);

    // Initiates battle with enemy
    void initiate_battle(Player &player);

} // namespace rpgText

#endif // !BATTLE_H
