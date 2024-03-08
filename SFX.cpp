//
// Created by Admin on 07.03.2024.
//

#include "SFX.h"
#include "Game.h"


void SFX::DrawPinpoint() {

}

void SFX::Update() {
    for(auto i : SFX::Vvf_visualEffects) i->Update();

    if(!SFX::Vvf_visualEffects.empty()) {
        for(int i = SFX::Vvf_visualEffects.size() - 1; i >= 0; i--) {
            if(SFX::Vvf_visualEffects[i]->IsMarkedToDeath()) {
                delete SFX::Vvf_visualEffects[i];
                SFX::Vvf_visualEffects.erase(SFX::Vvf_visualEffects.begin() + i );
            }
        }
    }

}

void SFX::Render() {
    for(auto i : SFX::Vvf_visualEffects) i->Render();
}

