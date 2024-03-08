//
// Created by Admin on 05.03.2024.
//

#include "CharacterGO.h"
#include "Game.h"

CharacterGO::CharacterGO(std::string name, const char *textureSheet, int width, int height, int xTile, int yTile)
    : GameObject(name, textureSheet, width, height, xTile, yTile) {
    textBox_position = TextManager::CreateTextBox(100, 700);
}

void CharacterGO::Update() {
    SelectDestination();
    MakeStep(4);
    if(i_xTile == 10 && i_yTile == 10) TextManager::DestroyTextBox(textBox_position);
    TextManager::WriteMessage(textBox_position, "X: " + std::to_string(i_xTile) + " / Y: " + std::to_string(i_yTile));
}

void CharacterGO::Move(int tileX, int tileY) {
    i_enqueuedXTile = tileX;
    i_enqueuedYTile = tileY;
}

void CharacterGO::SelectDestination() {
    if(Game::b_selectButton == true) {
        Move(Game::i_cursorCoordinatesX/64, Game::i_cursorCoordinatesY/64);
        SFX::Vvf_visualEffects.push_back(new Pinpoint(Game::i_cursorCoordinatesX/64, Game::i_cursorCoordinatesY/64));
    }
}

void CharacterGO::MakeStep(int speed) {
    if(sdlRect_dstRect.x < i_desXTile * 64) sdlRect_dstRect.x += speed;
    else if(sdlRect_dstRect.x > i_desXTile * 64) sdlRect_dstRect.x -= speed;
    else if(sdlRect_dstRect.y < i_desYTile*64) sdlRect_dstRect.y += speed;
    else if(sdlRect_dstRect.y > i_desYTile*64) sdlRect_dstRect.y -= speed;

    i_yTile = sdlRect_dstRect.y / 64;
    i_xTile = sdlRect_dstRect.x / 64;

    if(sdlRect_dstRect.y % 64 == 0 && sdlRect_dstRect.x % 64 == 0) {
        i_desXTile = i_enqueuedXTile;
        i_desYTile = i_enqueuedYTile;
    }
}


