#include"constants.h"
#include"declarations.h"

void restart()
{
    
}

void update(Engine& gameEngine) //main update function
{
    gameEngine.fpsCap();
    gameEngine.countDeltaTime();
}