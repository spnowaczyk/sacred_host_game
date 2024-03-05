//
// Created by Admin on 29.02.2024.
//

#ifndef SACRED_HOST_TEXTUREMANAGER_H
#define SACRED_HOST_TEXTUREMANAGER_H

#include "SDL_image.h"


class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* path);
    static void DrawTexture(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
};


#endif //SACRED_HOST_TEXTUREMANAGER_H
