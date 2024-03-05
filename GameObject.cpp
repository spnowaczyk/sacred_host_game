//
// Created by Admin on 29.02.2024.
//

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(std::string name, const char *textureSheet, int width, int height, int xPos, int yPos) {
    this->sdlTex_objTexture = TextureManager::LoadTexture(textureSheet);
    s_name = name;

    i_xPos = xPos;
    i_yPos = yPos;

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

