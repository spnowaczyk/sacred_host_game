//
// Created by Admin on 07.03.2024.
//

#ifndef SACRED_HOST_SFX_H
#define SACRED_HOST_SFX_H

#include "Game.h"
#include "VisualEffect.h"

class SFX {
public:
    static void DrawPinpoint();
    static std::vector<VisualEffect*> Vvf_visualEffects;
    static void Update();
    static void Render();
};


#endif //SACRED_HOST_SFX_H
