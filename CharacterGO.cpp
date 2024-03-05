//
// Created by Admin on 05.03.2024.
//

#include "CharacterGO.h"

CharacterGO::CharacterGO(std::string name, const char *textureSheet, int width, int height, int xPos, int yPos)
    : GameObject(name, textureSheet, width, height, xPos, yPos) {
    i_desYPos = 3;
    i_desXPos = 3;
}

void CharacterGO::Update() {
    MakeStep();
}

void CharacterGO::Move(int tileX, int tileY) {
    i_desXPos = tileX;
    i_desYPos = tileY;
}

void CharacterGO::MakeStep() {
    if(sdlRect_dstRect.x < i_desXPos*64) sdlRect_dstRect.x++;
    else if(sdlRect_dstRect.x > i_desXPos*64) sdlRect_dstRect.x--;
    else if(sdlRect_dstRect.y < i_desYPos*64) sdlRect_dstRect.y++;
    else if(sdlRect_dstRect.y > i_desYPos*64) sdlRect_dstRect.y--;

    i_yPos = sdlRect_dstRect.y / 64;
    i_xPos = sdlRect_dstRect.x / 64;
}
