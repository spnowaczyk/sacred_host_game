//
// Created by Admin on 29.02.2024.
//

#ifndef SACRED_HOST_GAMEOBJECT_H
#define SACRED_HOST_GAMEOBJECT_H

#include "SDL.h"
#include "string"

class GameObject {
public:
    GameObject(std::string name, const char* textureSheet, int width = 64, int height = 64, int xTile = 0, int yTile = 0);
    ~GameObject();

    void Update();
    void Render();

    int getIXPos() const;
    int getIYPos() const;

protected:
    std::string s_name;

    int i_xTile;
    int i_yTile;

    int i_desXTile;
    int i_desYTile;

    int i_enqueuedXTile;
    int i_enqueuedYTile;

    int i_Width;
    int i_Height;

    SDL_Texture* sdlTex_objTexture;
    SDL_Rect sdlRect_srcRect, sdlRect_dstRect;
};


#endif //SACRED_HOST_GAMEOBJECT_H
