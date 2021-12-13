#include "Battle.h"

namespace rpgText
{
    // Checks if Enemy is encountered based on "chance"
    bool check_for_battle(int chance)
    {
        int num = (rand() % 100) + 1;
        return (num <= chance);
    }

    // Initiates battle with enemy
    void initiate_battle(const Player &player)
    {
        Enemy enemy("Goblin");
        print("A ");
        print(enemy.name);
        print(" is attacking ");
        log(player.name);
        int attackChoice{};
        while (enemy.get_status())
        {
            print("Enemy's health is ");
            log(enemy.cStats.health);
            attackChoice = get_int_prompt("Press 1 to attack or any other to wait: ");
            if (attackChoice == 1)
            {
                enemy.change_health(-player.cStats.attack);
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
