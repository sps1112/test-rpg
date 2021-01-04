#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>

#include "Standard.h"
#include "Character.h"

namespace rpgText
{
    // Checks if Enemy is encountered based on "chance"
    bool CheckBattle(int chance);

    //Initiates battle with enemy
    void StartBattle(const Player &player);

} // namespace rpgText

#endif