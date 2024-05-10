#include"constants.h"
#include"declarations.h"

int main(int argc, char* argv[])
{
    Engine gameEngine;
    Game snake;

    gameEngine.initializing();
    Renderer renderer(gameEngine.renderer);

    if(gameEngine.is_running)
    {
        setup(snake);

        while(gameEngine.is_running)
        {
            process_input(gameEngine, snake);
            update(gameEngine);
            render(renderer, gameEngine, snake);
        }

        return 0;
    }

    return 1;
}