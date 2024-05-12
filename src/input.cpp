#include"constants.h"
#include"declarations.h"

void process_input(Engine& gameEngine, Game& snake) //main input function
{
    switch(gameEngine.getEventType())
    {
        case SDL_QUIT:
            gameEngine.is_running = FALSE;
            break;
        
        case SDL_KEYDOWN:
            switch(gameEngine.getPressedKeyOnKB())
            {
                case SDLK_ESCAPE:
                    gameEngine.is_running = FALSE;
                    break;

                case SDLK_UP:
                    snake.player.horizontal = false;
                    snake.player.direction = -1;
                    break;
                
                case SDLK_DOWN:
                    snake.player.horizontal = false;
                    snake.player.direction = 1;
                    break;
                
                case SDLK_LEFT:
                    snake.player.horizontal = true;
                    snake.player.direction = -1;
                    break;
                
                case SDLK_RIGHT:
                    snake.player.horizontal = true;
                    snake.player.direction = 1;
                    break;
            }
            break;
    }
}