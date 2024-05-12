#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"constants.h"
#include<cstdlib>
#include<ctime>

typedef struct playerstats
{
    float x;
    float y;
    float width;
    float height;
    int direction;
    bool horizontal;
    int speed;

    playerstats() = default;

    playerstats(float _x, float _y, float _w, float _h) : x(_x), y(_y), width(_w), height(_h) {}
} Player;

class Game
{
    private:


    public:
        Player player;
        SDL_Rect apple;
        unsigned score;

        Game();

        void newApple();     
        void addScore(); 
};

class Renderer
{
    private:
        SDL_Renderer* renderer;
    
    public:
        Renderer(SDL_Renderer* _renderer) : renderer(_renderer) {}

        void drawTextOn(const std::string& text, TTF_Font* font, const int& x, const int& y, const SDL_Color& color={255,255,255,255});
        void setRenderDrawColor(const SDL_Color& color);
        void renderFillRectFloatT(const SDL_FRect* frect);
        void renderFillRectIntT(const SDL_Rect* rect);
        void renderPresent();
        void renderClear();
};

class Engine
{
    private:
        int last_frame_time;
        SDL_Event input_event;

    public:
        int is_running;
        SDL_Window* window;
        SDL_Renderer* renderer;
        TTF_Font* font;
        float delta_time;
    
    Engine();
    
    void initializing();
    void countDeltaTime();
    void fpsCap();
    Uint32 getEventType();
    SDL_Keycode getPressedKeyOnKB();
    const char* getLastError();

    ~Engine();
};

//Game loop functions
void setup(Game& snake);
void process_input(Engine& gameEngine, Game& snake);
void update(Engine& gameEngine, Game& snake);
void render(Renderer& renderer, Engine& gameEngine, const Game& snake);

#endif