#ifndef RPG_GAME_H
#define RPG_GAME_H

// Custom Headers
#include <Standard.h>
#include <Printer.h>
#include <Character.h>
#include <FileSystem.h>
#include <Battle.h>

namespace rpgText
{
    // All the game modes
    enum GAME_STATE
    {
        STATE_MENU,    // Main Menu
        STATE_OPTIONS, // Options Menu
        STATE_QUIT,    // Quit Menu
        STATE_MAP,     // Map Menu
        STATE_BATTLE,  // Battle Menu
        STATE_PAUSE,   // Pause Menu
    };

    class Game
    {
    private:
        bool running; // Whether the game is running
        bool saved;   // Whether save data is available

    public:
        // The current game state
        GAME_STATE state;

        Player player = Player(FileSystem::get_path("test-rpg/data/Player.char").c_str());

        // Default Game Class Constructor
        Game();

        // Returns running status
        bool get_running();

        // Runs the game loop
        void game_loop();

        // Main Menu Function
        void run_main_menu();

        // Options Menu Function
        void run_options();

        // Quits the Game
        void quit_game();

        // Runs the rpg map mode
        void run_game();

        // Starts a new battle
        void start_battle();

        // Pauses the game
        void pause_game();
    };

} // namespace rpgText

#endif // !RPG_GAME_H
