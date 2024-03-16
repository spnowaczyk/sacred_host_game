//
// Created by Admin on 29.02.2024.
//

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(std::string name, const char *textureSheet, int tilesWidth, int tilesHeight, int xTile, int yTile,
                       ObjectManager* objectManager, SFXManager* sfxManager, std::string message) : s_name(name), s_message(message), i_xTile(xTile),
                                                                            i_yTile(yTile), objMan_manager(objectManager),
                                                                            sfxMan_manager(sfxManager){
    this->sdlTex_objTexture = TextureManager::LoadTexture(textureSheet);
    b_markedToDeath = false;

    sdlRect_dstRect.x = xTile * Game::i_tileSize;
    sdlRect_dstRect.y = yTile * Game::i_tileSize;

    i_tilesWidth = tilesWidth;
    i_tilesHeight = tilesHeight;

    i_enqueuedXTile = i_desXTile = xTile;
    i_enqueuedYTile = i_desYTile = yTile;

    sdlRect_srcRect.x = 0;
    sdlRect_srcRect.y = 0;

    sdlRect_srcRect.h = Game::i_srcTileSize*tilesHeight;
    sdlRect_dstRect.h = Game::i_tileSize*tilesWidth;
    sdlRect_srcRect.w = Game::i_srcTileSize*tilesHeight;
    sdlRect_dstRect.w = Game::i_tileSize*tilesWidth;

    Game::i_gameObjects++;
}

GameObject::~GameObject() {
    Game::i_gameObjects--;
    SDL_DestroyTexture(sdlTex_objTexture);
}

void GameObject::Update() {
}

void GameObject::Render() {
    sdlRect_dstRect.h = Game::i_tileSize*i_tilesWidth;
    sdlRect_dstRect.w = Game::i_tileSize*i_tilesWidth;
    SDL_RenderCopy(Game::sdlRen_renderer, sdlTex_objTexture, &sdlRect_srcRect, &sdlRect_dstRect);
}

void GameObject::Interact() {
    if(!s_message.empty()) TextManager::CreateFadingTextBox(i_xTile*Game::i_tileSize, i_yTile*Game::i_tileSize, s_message);
}

int GameObject::getIXTile() const {
    return i_xTile;
}

int GameObject::getIYTile() const {
    return i_yTile;
}

bool GameObject::IsMarkedToDeath() {
    return b_markedToDeath;
}

void GameObject::MarkToDeath() {
    b_markedToDeath = true;
}

void GameObject::Adjust(int previousTileSize) {
    this->sdlRect_dstRect.x = this->i_xTile * Game::i_tileSize;
    this->sdlRect_dstRect.y = this->i_yTile * Game::i_tileSize;
}



