#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>

namespace rpgText
{
    bool CheckBattle(int chance)
    {
        int num = (rand() % 100) + 1;
        if (num <= chance)
        {
            return 1;
        }
        return 0;
    }

    void StartBattle(const Player &player)
    {
        Enemy enemy("Goblin");
        Print("A ");
        Print(enemy.name);
        Print(" is attacking ");
        Log(player.name);
        // Log(" is attacking");
        int attackChoice{};
        while (enemy.GetStatus())
        {
            Print("Enemy's health is ");
            Log(enemy.health);
            Print("Press 1 to attack or any other to wait: ");
            std::cin >> attackChoice;
            if (attackChoice == 1)
            {
                enemy.ChangeHealth(-player.attack);
                Log("You attacked");
            }
            else
            {
                Log("You waited");
            }
        }
        Log("Enemy Defeated!");
    }
} // namespace rpgText

#endif