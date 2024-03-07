//
// Created by s.nowaczyk on 07.03.2024.
//

#include "MouseController.h"
#include "Game.h"
#include "SDL.h"

void MouseController::MousePositionQuery(int *mouseX, int *mouseY) {
    if(Game::sdlEvent_event.type == SDL_MOUSEMOTION) {
        *mouseX = Game::sdlEvent_event.motion.x;
        *mouseY = Game::sdlEvent_event.motion.y;
    }
}

void MouseController::MouseClickQuery(bool *mouseClickFlag) {
    if(Game::sdlEvent_event.type == SDL_MOUSEBUTTONDOWN) {
        switch (Game::sdlEvent_event.button.button) {
            case SDL_BUTTON_LEFT:
                *mouseClickFlag = true;
                break;
            default:
                break;
        }
    } if (Game::sdlEvent_event.type == SDL_MOUSEBUTTONUP) {
        switch (Game::sdlEvent_event.button.button) {
            case SDL_BUTTON_LEFT:
                *mouseClickFlag = false;
                break;
            default:
                break;
        }
    }
}

