//
// Created by Admin on 07.03.2024.
//

#include "Game.h"
#include "SFXManager.h"


SFXManager::SFXManager() {
    for(auto i : AsdlTex_textures) {
        i = nullptr;
    }
    AsdlTex_textures[TEXTURES(PINPOINT)] = TextureManager::LoadTexture("../assets/pinpoint.png");
}

SFXManager::~SFXManager() {
    for(auto i : AsdlTex_textures) {
        if(i != nullptr) SDL_DestroyTexture(i);
    }
}

void SFXManager::DrawPinpoint() {
    Vvf_visualEffects.push_back(new Pinpoint(Game::i_cursorCoordinatesX / Game::i_tileSize, Game::i_cursorCoordinatesY / Game::i_tileSize, this));
}

void SFXManager::Update() {
    for(auto i : SFXManager::Vvf_visualEffects) i->Update();

    if(!SFXManager::Vvf_visualEffects.empty()) {
        for(int i = SFXManager::Vvf_visualEffects.size() - 1; i >= 0; i--) {
            if(SFXManager::Vvf_visualEffects[i]->IsMarkedToDeath()) {
                delete SFXManager::Vvf_visualEffects[i];
                SFXManager::Vvf_visualEffects.erase(SFXManager::Vvf_visualEffects.begin() + i );
            }
        }
    }

}

void SFXManager::Render() {
    for(auto i : SFXManager::Vvf_visualEffects) i->Render();
}

SDL_Texture *SFXManager::GetTexture(int textureID) {
    return AsdlTex_textures[TEXTURES(textureID)];
}

