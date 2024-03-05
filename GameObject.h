//
// Created by Admin on 29.02.2024.
//

#ifndef SACRED_HOST_GAMEOBJECT_H
#define SACRED_HOST_GAMEOBJECT_H

#include "SDL.h"
#include "string"

class GameObject {
public:
    GameObject(std::string name, const char* textureSheet, int width = 64, int height = 64, int xPos = 0, int yPos = 0);
    ~GameObject();

    void Update();
    void Render();

protected:
    std::string s_name;

    int i_xPos;
    int i_yPos;

    int i_desXPos;
    int i_desYPos;

    int i_Width;
    int i_Height;

    SDL_Texture* sdlTex_objTexture;
    SDL_Rect sdlRect_srcRect, sdlRect_dstRect;
};


#endif //SACRED_HOST_GAMEOBJECT_H
