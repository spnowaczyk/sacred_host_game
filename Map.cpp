//
// Created by Admin on 02.03.2024.
//

#include "Map.h"

Map::Map() {
    sdlTexture_sand = TextureManager::LoadTexture("../assets/sand.png");
    sdlTexture_grass = TextureManager::LoadTexture("../assets/grass.png");
    sdlTexture_concrete = TextureManager::LoadTexture("../assets/dusty_concrete.png");
    sdlRect_dst.w = sdlRect_dst.h = 64;
    sdlRect_src.w = sdlRect_src.h = 64;
    sdlRect_src.x = sdlRect_src.y = 0;
    sdlRect_dst.x = sdlRect_dst.y = 0;
}

Map::~Map() {

}

void Map::LoadMap(int tileTexturesArray [12][20]) {
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            this->iA_tileTexturesMap[row][col] = tileTexturesArray[row][col];
        }
    }
}

void Map::RenderMap() {
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            this->sdlRect_dst.x = col*64;
            this->sdlRect_dst.y = row*64;
            int i_type = iA_tileTexturesMap[row][col];
            TextureManager::DrawTexture(*sdlTextureA_tiles[i_type], sdlRect_src, sdlRect_dst);
        }
    }
}

void Map::RandomMap() {
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            this->iA_tileTexturesMap[row][col] = rand() % 3; // generates random numbers between 0 and 2
        }
    }
}

GameObject *Map::getOccupyingObject(int xTile, int yTile) {
    return goV_occupyingObjects[xTile][yTile];
}
