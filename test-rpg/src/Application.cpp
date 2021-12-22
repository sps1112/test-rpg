// Custom Headers
#include <Game.h>

// Standard Headers
#include <iostream>

// Main Function
int main()
{
    rpgText::Game game;
    while (game.get_running())
    {
        game.game_loop();
    }
    return 0;
}
