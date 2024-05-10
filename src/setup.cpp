#include"constants.h"
#include"declarations.h"

void setup(Game& snake) //main setup function
{
    snake.score = 0;
    snake.player = Player(CENTER_X, CENTER_Y, 10, 10);
}