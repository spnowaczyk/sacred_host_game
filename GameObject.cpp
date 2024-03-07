//
// Created by Admin on 29.02.2024.
//

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(std::string name, const char *textureSheet, int width, int height, int xTile, int yTile) {
    this->sdlTex_objTexture = TextureManager::LoadTexture(textureSheet);
    s_name = name;

    sdlRect_dstRect.x = xTile * 64;
    sdlRect_dstRect.y = yTile * 64;

    i_enqueuedXTile = i_desXTile = xTile;
    i_enqueuedYTile = i_desYTile = yTile;

    sdlRect_srcRect.x = 0;
    sdlRect_srcRect.y = 0;

    sdlRect_srcRect.h = sdlRect_dstRect.h = width;
    sdlRect_srcRect.w = sdlRect_dstRect.w = height;
}

void GameObject::Update() {
}

void GameObject::Render() {
    SDL_RenderCopy(Game::sdlRen_renderer, sdlTex_objTexture, &sdlRect_srcRect, &sdlRect_dstRect);
}

int GameObject::getIXPos() const {
    return i_xPos;
}

int GameObject::getIYPos() const {
    return i_yPos;
}

