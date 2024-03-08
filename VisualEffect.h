//
// Created by Admin on 07.03.2024.
//

#ifndef SACRED_HOST_VISUALEFFECT_H
#define SACRED_HOST_VISUALEFFECT_H

#include "TextureManager.h"

class VisualEffect {
public:
    virtual void Update();
    virtual void Render();
    bool IsMarkedToDeath();

    VisualEffect();
    ~VisualEffect();

protected:
    int i_tileX;
    int i_tileY;
    int i_tilesWidth;
    int i_tilesHeight;
    int i_cnt;

    bool b_markedToDeath;

    SDL_Texture* sdlTex_texture;
    SDL_Rect sdlRect_srcRect;
    SDL_Rect sdlRect_dstRect;
};


#endif //SACRED_HOST_VISUALEFFECT_H
