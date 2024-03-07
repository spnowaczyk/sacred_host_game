//
// Created by Admin on 05.03.2024.
//

#include "CharacterGO.h"
#include "Game.h"

CharacterGO::CharacterGO(std::string name, const char *textureSheet, int width, int height, int xPos, int yPos)
    : GameObject(name, textureSheet, width, height, xPos, yPos) {
    i_desYPos = 3;
    i_desXPos = 3;
}

void CharacterGO::Update() {
    SelectDestination();
    MakeStep();
}

void CharacterGO::Move(int tileX, int tileY) {
    i_desXPos = tileX;
    i_desYPos = tileY;
}

void CharacterGO::SelectDestination() {
    if(Game::b_selectButton == true) {
        Move(Game::i_cursorCoordinatesX/64, Game::i_cursorCoordinatesY/64);
    }
}

void CharacterGO::MakeStep() {
    if(sdlRect_dstRect.x < i_desXPos*64) sdlRect_dstRect.x++;
    else if(sdlRect_dstRect.x > i_desXPos*64) sdlRect_dstRect.x--;
    else if(sdlRect_dstRect.y < i_desYPos*64) sdlRect_dstRect.y++;
    else if(sdlRect_dstRect.y > i_desYPos*64) sdlRect_dstRect.y--;

    i_yPos = sdlRect_dstRect.y / 64;
    i_xPos = sdlRect_dstRect.x / 64;
}


