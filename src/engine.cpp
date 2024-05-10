#include"declarations.h"
#include"constants.h"

Engine::Engine()
{
    is_running = FALSE;
    window = NULL;
    renderer = NULL;
    font = NULL;
    last_frame_time = 0;
}

void Engine::initializing()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr<<SDL_GetError()<<"| Error initializing SDL.\n";
        is_running = FALSE;
    }

    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
    {
        std::cerr<<SDL_GetError()<<"| Error initializing image lib.\n";
        is_running = FALSE;
    }

    if(TTF_Init() != 0)
    {
        std::cerr<<SDL_GetError()<<"| Error initializing ttf.\n";
        is_running = FALSE;
    }

    SDL_Surface* gameIcon = IMG_Load("icon.png");

    if(gameIcon == NULL)
    {
        std::cerr<<SDL_GetError()<<"| Icon is not loaded.\n";
    }

    font = TTF_OpenFont("arial.ttf", 24);

    if(font == NULL)
    {
        std::cerr<<SDL_GetError()<<"| Font is not loaded.\n";
    }

    window = SDL_CreateWindow(
        "Snake",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if(!window)
    {
        std::cerr<<SDL_GetError()<<"| Error creating SDL Window.\n";
        is_running = FALSE;
    }

    SDL_SetWindowIcon(window, gameIcon);
    SDL_FreeSurface(gameIcon);

    renderer = SDL_CreateRenderer(window, -1, 0);

    if(!renderer)
    {
        std::cerr<<SDL_GetError()<<"| Error creating SDL Renderer.\n";
        is_running = FALSE;
    }

    is_running = TRUE;
}

void Engine::countDeltaTime()
{
    delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;    //delta time used to calculate speed of object px/s
    last_frame_time = SDL_GetTicks();   //get current ms value
}

void Engine::fpsCap()
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    if(time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }
}

Uint32 Engine::getEventType()
{
    SDL_PollEvent(&input_event);
    return input_event.type;
}

SDL_Keycode Engine::getPressedKeyOnKB()
{
    return input_event.key.keysym.sym;
}

const char* Engine::getLastError()
{
    return SDL_GetError();
}

Engine::~Engine()
{
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Renderer::drawTextOn(const std::string& text, TTF_Font* font, const int& x, const int& y, const SDL_Color& color)
{
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);

    if(textSurface == NULL)
    {
        std::cerr<<SDL_GetError()<<"| Failed to render text.\n";
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    if(textTexture == NULL)
    {
        std::cerr<<SDL_GetError()<<"| Failed to create text texture.\n";
        return;
    }

    SDL_Rect dstRect = {
        x,
        y,
        textSurface->w,
        textSurface->h
    };

    SDL_RenderCopy(renderer, textTexture, nullptr, &dstRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void Renderer::setRenderDrawColor(const SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Renderer::renderFillRectFloatT(const SDL_FRect* frect)
{
    SDL_RenderFillRectF(renderer, frect);
}

void Renderer::renderFillRectIntT(const SDL_Rect* rect)
{
    SDL_RenderFillRect(renderer, rect);
}

void Renderer::renderPresent()
{
    SDL_RenderPresent(renderer);
}

void Renderer::renderClear()
{
    SDL_RenderClear(renderer);
}

