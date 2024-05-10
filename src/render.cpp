#include"constants.h"
#include"declarations.h"

void render(Renderer& renderer, Engine& gameEngine, const Game& snake) //main render function
{
    renderer.setRenderDrawColor({0,0,0,255});
    renderer.renderClear();

    std::string text = std::to_string(snake.score);

    SDL_FRect snakeRect = {
        snake.player.x,
        snake.player.y,
        snake.player.width,
        snake.player.height
    };

    renderer.setRenderDrawColor({255,255,255,255});
    renderer.renderFillRectFloatT(&snakeRect);
    renderer.drawTextOn(text, gameEngine.font, 10, 10);

    renderer.renderPresent();
}