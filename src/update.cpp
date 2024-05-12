#include"constants.h"
#include"declarations.h"

void restart()
{
    
}

void update(Engine& gameEngine, Game& snake) //main update function
{
    gameEngine.fpsCap();
    gameEngine.countDeltaTime();

    if(snake.player.horizontal)
    {
        if(snake.player.x < 0) snake.player.x = WINDOW_WIDTH;
        else if(snake.player.x > WINDOW_WIDTH) snake.player.x = 0;

        snake.player.x += snake.player.speed * gameEngine.delta_time * snake.player.direction;
    }
    else
    {
        if(snake.player.y < 0) snake.player.y = WINDOW_HEIGHT;
        else if(snake.player.y > WINDOW_HEIGHT) snake.player.y = 0;

        snake.player.y += snake.player.speed * gameEngine.delta_time * snake.player.direction;
    }
}