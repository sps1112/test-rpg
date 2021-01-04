#include "Battle.h"

namespace rpgText
{
    // Checks if Enemy is encountered based on "chance"
    bool CheckBattle(int chance)
    {
        int num = (rand() % 100) + 1;
        if (num <= chance)
        {
            return 1;
        }
        return 0;
    }

    //Initiates battle with enemy
    void StartBattle(const Player &player)
    {
        Enemy enemy("Goblin");
        Print("A ");
        Print(enemy.name);
        Print(" is attacking ");
        Log(player.name);
        int attackChoice{};
        while (enemy.GetStatus())
        {
            Print("Enemy's health is ");
            Log(enemy.health);
            attackChoice = GetIntWithPrompt("Press 1 to attack or any other to wait: ");
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
