//
// Created by Admin on 07.03.2024.
//

#include "VisualEffect.h"
#include "Game.h"

VisualEffect::VisualEffect(SFXManager* sfxManager) : sfxMan_manager(sfxManager){
    b_markedToDeath = false;
    Game::i_visualEffects++;
}

VisualEffect::~VisualEffect() {
    Game::i_visualEffects--;
}

void VisualEffect::Update() {

}

void VisualEffect::Render() {

}

bool VisualEffect::IsMarkedToDeath() {
    return b_markedToDeath;
}

