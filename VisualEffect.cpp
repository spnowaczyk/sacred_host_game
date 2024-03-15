//
// Created by Admin on 07.03.2024.
//

#include "VisualEffect.h"
#include "Game.h"

VisualEffect::VisualEffect() {
    b_markedToDeath = false;
    Game::i_visualEffects++;
}

VisualEffect::~VisualEffect() {
    SDL_DestroyTexture(sdlTex_texture);
    Game::i_visualEffects--;
}

void VisualEffect::Update() {

}

void VisualEffect::Render() {

}

bool VisualEffect::IsMarkedToDeath() {
    return b_markedToDeath;
}

