
#include <iostream>
#include "Game.h"


int main()
{
    Game game;
    if (!game.Init()) {
        glfwTerminate();
        return -1;
    }
    game.Run();
    game.Exit();

    glfwTerminate();
    return 0;
}


