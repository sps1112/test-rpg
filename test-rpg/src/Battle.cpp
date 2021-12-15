#include "Battle.h"

namespace rpgText
{
    bool check_for_battle(int chance)
    {
        int num = (rand() % 100) + 1;
        return (num <= chance);
    }

    void initiate_battle(const Player &player)
    {
        Enemy enemy(FileSystem::get_path("test-rpg/data/Enemies/Goblin.enemy").c_str());
        print("A ");
        print(enemy.name);
        print(" is attacking ");
        log(player.name);
        new_line();
        log("Enemy stats are:-");
        enemy.print_stats();
        int attackChoice;
        while (enemy.get_status())
        {
            print_data("Enemy's health: ", enemy.cStats.health);
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
