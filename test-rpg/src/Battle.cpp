#include "Battle.h"

namespace rpgText
{
    void print_encounter(Enemy &enemy, std::string playerName)
    {
        print("A ");
        print(enemy.name);
        print(" is attacking ");
        log(playerName);
        new_line();
        log("Enemy Stats:-");
        enemy.print_stats();
        print("Enter any number to initiate combat: ");
    }

    void print_battle(Player &player, Enemy &enemy)
    {
        print_line();
        log("[PLAYER]");
        print("Name: ");
        log(player.name);
        print_data("Health: ", player.cStats.health);
        print_data("Mana: ", player.cStats.mana);
        print_line();
        log("[ENEMY]");
        print("Name: ");
        log(enemy.name);
        print_data("Health: ", enemy.cStats.health);
        print_data("Mana: ", enemy.cStats.mana);
        print_line();
        new_line();

        log("Choose one of the following options:-");
        log("1-> Attack");
        log("2-> Magic");
        log("3-> Item");
        log("4-> Wait");
        log("5-> Run Away");
        print("Choose the option by entering linked number: ");
    }

    void initiate_battle(Player &player)
    {
        Enemy enemy(FileSystem::get_path("test-rpg/data/Enemies/Goblin.enemy").c_str());
        print_encounter(enemy, player.name);
        int choice = get_int();
        clear_screen();
        bool onBattle = true;
        while (onBattle)
        {
            print_battle(player, enemy);
            int attackChoice = -1;
            while (attackChoice == -1)
            {
                attackChoice = get_int();
                if (attackChoice < 1 || attackChoice > 5)
                {
                    attackChoice = -1;
                    print("Wrong option! Select Again: ");
                }
                else
                {
                    break;
                }
            }
            switch (attackChoice)
            {
            case 1:
                enemy.change_health(-player.cStats.attack);
                log("You attacked the enemy");
                break;
            case 2:
                enemy.change_health(-player.cStats.mAttack);
                log("You used magic to attack enemy");
                break;
            case 3:
                log("You used an item");
                break;
            case 4:
                log("You waited this turn");
                break;
            case 5:
                if (check_event(60))
                {
                    onBattle = false;
                    log("You ran away from the battle");
                }
                break;
            default:
                break;
            }
            if (!enemy.get_status())
            {
                log("Enemy Defeated");
                onBattle = false;
            }
            if (onBattle)
            {
                attackChoice = get_int_prompt("Enter to start next turn: ");
                clear_screen();
            }
        }
        choice = get_int_prompt("Enter any number to go back to Map: ");
    }

} // namespace rpgText
