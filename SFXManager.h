//
// Created by Admin on 07.03.2024.
//

#ifndef SACRED_HOST_SFX_H
#define SACRED_HOST_SFX_H

#include "vector"

#define SFXAMOUNT 30

enum TEXTURES {
    PINPOINT
};

class VisualEffect;

class SFXManager {
public:
    SFXManager();
    ~SFXManager();
    void DrawPinpoint();
    void Update();
    void Render();

    SDL_Texture* GetTexture(int textureID);
private:
    std::vector<VisualEffect*> Vvf_visualEffects;

    SDL_Texture* AsdlTex_textures[SFXAMOUNT];
};


#endif //SACRED_HOST_SFX_H
