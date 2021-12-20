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
            if (enemy.cStats.speed > player.cStats.speed)
            {
                onBattle = enemy_turn(&player, &enemy);
                onBattle = (onBattle) ? (player_turn(&player, &enemy)) : (onBattle);
            }
            else
            {
                onBattle = player_turn(&player, &enemy);
                onBattle = (onBattle) ? (enemy_turn(&player, &enemy)) : (onBattle);
            }
            if (onBattle)
            {
                int turnChoice = get_int_prompt("Enter to start next turn: ");
                clear_screen();
            }
        }
        print_line();
        new_line();
        log("Battle Over!");
        choice = get_int_prompt("Enter any number to go back: ");
    }

    bool player_turn(Player *player, Enemy *enemy)
    {
        bool status = true;
        log("Choose one of the following options:-");
        log("1-> Attack");
        log("2-> Magic");
        log("3-> Item");
        log("4-> Wait");
        log("5-> Run Away");
        print("Choose the option by entering linked number: ");
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
            enemy->change_health(-player->cStats.attack);
            print("You attacked the ");
            log(enemy->name);
            break;
        case 2:
            enemy->change_health(-player->cStats.mAttack);
            print("You used magic to attack the ");
            log(enemy->name);
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
                log("You ran away from the battle");
                status = false;
            }
            break;
        default:
            break;
        }
        if (!enemy->get_status())
        {
            log("Enemy Defeated");
            status = false;
        }
        return status;
    }

    bool enemy_turn(Player *player, Enemy *enemy)
    {
        bool status = true;
        player->change_health(-enemy->cStats.attack);
        print(enemy->name);
        print(" attacked ");
        log(player->name);
        if (!player->get_status())
        {
            log("Player Defeated");
            status = false;
        }
        return status;
    }

} // namespace rpgText
