//
// Created by Admin on 02.03.2024.
//

#ifndef SACRED_HOST_MAP_H
#define SACRED_HOST_MAP_H

#include "Game.h"
#include "TextureManager.h"
#include "vector"


class Map {
public:
    Map();
    ~Map();

    void RandomMap();
    void LoadMap(int tileArray [12][20]);
    void RenderMap();

private:
    SDL_Rect sdlRect_src, sdlRect_dst;

    SDL_Texture* sdlTexture_concrete;
    SDL_Texture* sdlTexture_sand;
    SDL_Texture* sdlTexture_grass;

    std::vector<SDL_Texture**> sdlTextureA_tiles {
        &sdlTexture_concrete,
        &sdlTexture_sand,
        &sdlTexture_grass
    };

    int iA_tileMap[12][20];

};


#endif //SACRED_HOST_MAP_H
