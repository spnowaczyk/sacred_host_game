#include <iostream>
#include "SDL.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {

    const int Ci_FPS = 60;
    const int Ci_frameDelay = 1000 / 60;


    Uint32 ui32_frameStart, ui32_frameTime;

    game = new Game();
    game->Init("Endiesel Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 768, false);

    while(game->in_Running()) {
        ui32_frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

        ui32_frameTime = SDL_GetTicks() - ui32_frameStart;
        if(Ci_frameDelay > ui32_frameTime) SDL_Delay(Ci_frameDelay - ui32_frameTime);
    }

    game->Clear();

    return 0;
}