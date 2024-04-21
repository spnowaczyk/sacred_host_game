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

    void LoadTileSet(std::string path);
    void LoadMap(std::string path, int sizeX, int sizeY);
    void RenderMap();
    void RenderObscuringMap();


    GameObject* getOccupyingObject(int xTile, int yTile);

private:
    SDL_Rect sdlRect_src, sdlRect_dst;
    SDL_Texture* sdlTexture_tileset;
    std::vector<int> iV_tiles;
};


#endif //SACRED_HOST_MAP_H
