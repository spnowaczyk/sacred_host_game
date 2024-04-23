//
// Created by Admin on 05.03.2024.
//

#include "CharacterGO.h"
#include "Game.h"


CharacterGO::CharacterGO(std::string name, const char *textureSheet, int tilesWidth, int tilesHeight, int xTile, int yTile,
                         ObjectManager* objectManager, SFXManager* sfxManager)
    : GameObject(name, textureSheet, tilesWidth, tilesHeight, xTile, yTile, objectManager, sfxManager, "") {
    textBox_position = TextManager::CreateTextBox(100, 700, "character coords");
    textBox_velocity = TextManager::CreateTextBox(0, 0, "velocity");
}

CharacterGO::~CharacterGO() {
    TextManager::DestroyTextBox(textBox_position);
}

void CharacterGO::Update() {
    SelectDestination();
    MakeStep(2);
    TextManager::WriteMessage(textBox_position, "X: " + std::to_string(i_xTile) + " / Y: " + std::to_string(i_yTile));
}

void CharacterGO::Move(int tileX, int tileY) {
    i_desXTile = tileX;
    i_desYTile = tileY;
}

void CharacterGO::SelectDestination() {
    if(Game::b_selectButton == true) {
        int cursorTileX = Game::i_cursorCoordinatesX/Game::i_tileSize;
        int cursorTileY = Game::i_cursorCoordinatesY/Game::i_tileSize;
        if(objMan_manager->getObjectByLocals(cursorTileX, cursorTileY) == nullptr) {
            Diip_WalkPath.clear();
            Diip_WalkPath = this->objMan_manager->cl_layer->findWay(i_desXTile, i_desYTile, cursorTileX, cursorTileY);
            sfxMan_manager->DrawPinpoint();
        } else if (abs(cursorTileX - getIXTile()) <= 1 && abs(cursorTileY - getIYTile()) <= 1){
            objMan_manager->getObjectByLocals(cursorTileX, cursorTileY)->Interact();
        }
    }
}

void CharacterGO::MakeStep(int speed) {
    int i_velocity = ((float)speed / 4) * ((float)Game::i_tileSize / 8);
    if(sdlRect_dstRect.x < i_desXTile * Game::i_tileSize) sdlRect_dstRect.x += i_velocity;
    else if(sdlRect_dstRect.x > i_desXTile * Game::i_tileSize) sdlRect_dstRect.x -= i_velocity;
    else if(sdlRect_dstRect.y < i_desYTile * Game::i_tileSize) sdlRect_dstRect.y += i_velocity;
    else if(sdlRect_dstRect.y > i_desYTile * Game::i_tileSize) sdlRect_dstRect.y -= i_velocity;

    TextManager::WriteMessage(textBox_velocity, std::to_string(i_velocity) + "/ " + std::to_string(Game::i_tileSize));


    if(sdlRect_dstRect.y % Game::i_tileSize == 0 && sdlRect_dstRect.x % Game::i_tileSize == 0) {
        if(i_desXTile != sdlRect_dstRect.x/Game::i_tileSize || i_desYTile != sdlRect_dstRect.y/Game::i_tileSize){
            std::cout << "Whut bro!";
        }

        int i_prevYTile = i_yTile;
        int i_prevXTile = i_xTile;
        i_yTile = sdlRect_dstRect.y / Game::i_tileSize;
        i_xTile = sdlRect_dstRect.x / Game::i_tileSize;

        objMan_manager->ChangeObjectLocals(i_prevXTile, i_prevYTile, i_xTile, i_yTile);

        if(!Diip_WalkPath.empty()) {
            Move(Diip_WalkPath.front().first, Diip_WalkPath.front().second);
            Diip_WalkPath.pop_front();
        }
    }
}


