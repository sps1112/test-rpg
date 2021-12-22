#include "Game.h"

namespace rpgText
{
    Game::Game()
    {
        state = STATE_MENU;
        running = true;
        saved = false;
    }

    bool Game::get_running()
    {
        return running;
    }

    void Game::game_loop()
    {
        clear_screen();
        switch (state)
        {
        case STATE_MENU:
            run_main_menu();
            break;
        case STATE_OPTIONS:
            run_options();
            break;
        case STATE_QUIT:
            quit_game();
            running = false;
            break;
        case STATE_MAP:
            run_game();
            break;
        default:
            running = false;
        }
    }

    void Game::run_main_menu()
    {
        print_title();
        print_menu(saved);
        int choice = -1;
        while (choice == -1)
        {
            choice = get_int();
            switch (choice)
            {
            case 1:
            case 2:
            case 3:
                break;
            default:
                choice = -1;
                print("Wrong option! Select Again: ");
            }
        }
        new_line();
        switch (choice)
        {
        case 1:
            state = STATE_MAP;
            break;
        case 2:
            state = STATE_OPTIONS;
            break;
        case 3:
            state = STATE_QUIT;
            break;
        }
    }

    void Game::run_options()
    {
        print_options();
        int choice = -1;
        while (choice == -1)
        {
            choice = get_int();
            switch (choice)
            {
            case 1:
            case 2:
                break;
            default:
                choice = -1;
                print("Wrong option! Select Again: ");
            }
        }
        new_line();
        if (choice == 1)
        {
            player.print_stats();
            choice = get_int_prompt("Enter any number to go back to menu: ");
        }
        state = STATE_MENU;
    }

    void Game::quit_game()
    {
        print_end();
        int choice = get_int();
        clear_screen();
    }

    void Game::run_game()
    {
        bool gameRunning = true;
        log("You have landed on a new world! This is you character:-");
        log("");
        player.print_stats();
        log("");
        while (gameRunning)
        {
            int choice = -1;
            log("What do you want to do?");
            log("1-> Travel to a new location");
            log("2-> Pause the game to access options");
            log("3-> Quit to Main Menu");
            print("Choose by entering linked number:- ");
            while (choice == -1)
            {
                choice = get_int();
                switch (choice)
                {
                case 1:
                case 2:
                case 3:
                    break;
                default:
                    choice = -1;
                    print("Wrong option! Select Again: ");
                    break;
                }
            }
            clear_screen();
            if (choice == 1)
            {
                choice = -1;
                log("Choose one of the 4 directions to move in:- ");
                log("1-> North");
                log("2-> East");
                log("3-> South");
                log("4-> West");
                print("Choose by entering linked number:- ");
                while (choice == -1)
                {
                    choice = get_int();
                    switch (choice)
                    {
                    case 1:
                        log("You moved North");
                        break;
                    case 2:
                        log("You moved East");
                        break;
                    case 3:
                        log("You moved South");
                        break;
                    case 4:
                        log("You moved West");
                        break;
                    default:
                        choice = -1;
                        print("Wrong option! Select Again: ");
                    }
                }
                print_line();
                new_line();
                for (int i = 0; i < 10; i++)
                {
                    if (rpgText::check_event(20))
                    {
                        state = STATE_BATTLE;
                        start_battle();
                        if (state == STATE_MENU)
                        {
                            player.reset_stats();
                            gameRunning = false;
                            break;
                        }
                    }
                }
            }
            else if (choice == 2)
            {
                state = STATE_PAUSE;
                pause_game();
                if (state == STATE_MENU)
                {
                    gameRunning = false;
                }
            }
            else if (choice == 3)
            {
                state = STATE_MENU;
                gameRunning = false;
            }
            clear_screen();
        }
    }

    void Game::start_battle()
    {
        clear_screen();
        log("You encountered an enemy");
        print_line();
        initiate_battle(player);
        print_line();
        state = (player.get_status()) ? STATE_MAP : STATE_MENU;
    }

    void Game::pause_game()
    {
        print_pause();
        int choice = -1;
        while (choice == -1)
        {
            choice = get_int();
            switch (choice)
            {
            case 1:
            case 2:
            case 3:
                break;
            default:
                choice = -1;
                print("Wrong option! Select Again: ");
            }
        }
        new_line();
        switch (choice)
        {
        case 1:
            state = STATE_MAP;
            break;
        case 2:
            player.print_stats();
            choice = get_int_prompt("Enter any number to go back to map: ");
            state = STATE_MAP;
            break;
        case 3:
            state = STATE_MENU;
            break;
        default:
            break;
        }
    }

} // namespace rpgText
