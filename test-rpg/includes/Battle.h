#ifndef BATTLE_H
#define BATTLE_H

// Custom Headers
#include "Standard.h"
#include "Character.h"
#include <FileSystem.h>

// Standard Headers
#include <iostream>

namespace rpgText
{
    // Checks if Enemy is encountered based on "chance"
    bool check_for_battle(int chance);

    // Initiates battle with enemy
    void initiate_battle(const Player &player);

} // namespace rpgText

#endif // !BATTLE_H
