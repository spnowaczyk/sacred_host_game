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
    void LoadMap(int tileTexturesArray [12][20]);
    bool IsWall(int tileX, int tileY);
    void RenderMap();
    void RenderObscuringMap();


    GameObject* getOccupyingObject(int xTile, int yTile);

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

    int iA_tileTexturesMap[12][20];

};


#endif //SACRED_HOST_MAP_H
