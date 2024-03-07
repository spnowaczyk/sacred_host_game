//
// Created by Admin on 20.02.2024.
//

#ifndef TEMPLES_MESSENGER_GAME_H
#define TEMPLES_MESSENGER_GAME_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <stdio.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "CharacterGO.h"
#include "Map.h"
#include "TextBox.h"
#include "MouseController.h"


class Game {
public:
    Game();
    ~Game();

    void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void HandleEvents();
    void Update();
    void Render();
    void Clear();
    inline bool in_Running() { return b_running; }

    static SDL_Renderer* sdlRen_renderer;
    static SDL_Event sdlEvent_event;

    static int i_cursorCoordinatesX, i_cursorCoordinatesY;
    static bool b_selectButton;

private:
    bool b_running;
    SDL_Window* sdlWin_window;
};


#endif //TEMPLES_MESSENGER_GAME_H
