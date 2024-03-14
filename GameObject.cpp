//
// Created by Admin on 29.02.2024.
//

#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject(std::string name, const char *textureSheet, int width, int height, int xTile, int yTile, ObjectManager* manager, std::string message) {
    this->sdlTex_objTexture = TextureManager::LoadTexture(textureSheet);
    b_markedToDeath = false;
    s_name = name;
    s_message = message;

    sdlRect_dstRect.x = xTile * 64;
    sdlRect_dstRect.y = yTile * 64;

    i_enqueuedXTile = i_desXTile = xTile;
    i_enqueuedYTile = i_desYTile = yTile;

    sdlRect_srcRect.x = 0;
    sdlRect_srcRect.y = 0;

    sdlRect_srcRect.h = sdlRect_dstRect.h = width;
    sdlRect_srcRect.w = sdlRect_dstRect.w = height;

    i_yTile = yTile;
    i_xTile = xTile;

    om_manager = manager;

    Game::i_gameObjects++;
}

GameObject::~GameObject() {
    Game::i_gameObjects--;
}

void GameObject::Update() {
}

void GameObject::Render() {
    SDL_RenderCopy(Game::sdlRen_renderer, sdlTex_objTexture, &sdlRect_srcRect, &sdlRect_dstRect);
}

void GameObject::Interact() {
    if(!s_message.empty()) TextManager::CreateFadingTextBox(i_xTile*64, i_yTile*64, s_message);
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


