#include"constants.h"
#include"declarations.h"

void setup(Game& snake) //main setup function
{
    snake.score = 0;
    snake.player = Player(CENTER_X, CENTER_Y, 10, 10);
    snake.player.speed = 25;
    snake.player.direction = 1;
    snake.player.horizontal = true;

    snake.apple = {0,0,10,10};
    snake.newApple();
}