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

    // Initiates battle with enemy
    void StartBattle(const Player &player)
    {
        Enemy enemy("Goblin");
        print("A ");
        print(enemy.name);
        print(" is attacking ");
        log(player.name);
        int attackChoice{};
        while (enemy.GetStatus())
        {
            print("Enemy's health is ");
            log(enemy.health);
            attackChoice = get_int_prompt("Press 1 to attack or any other to wait: ");
            if (attackChoice == 1)
            {
                enemy.ChangeHealth(-player.attack);
                log("You attacked");
            }
            else
            {
                log("You waited");
            }
        }
        log("Enemy Defeated!");
    }
} // namespace rpgText
