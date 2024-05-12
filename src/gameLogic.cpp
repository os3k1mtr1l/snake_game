#include"declarations.h"
#include"constants.h"

Game::Game()
{
    srand(time(NULL));
}

void Game::newApple()
{
    int x,y;

    x = rand() % (WINDOW_WIDTH - apple.w);
    y = rand() % (WINDOW_HEIGHT - apple.h);

    apple = {x, y, apple.w, apple.h};
}

void Game::addScore()
{
    score++;

    
}