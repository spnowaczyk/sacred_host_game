//
// Created by Admin on 02.03.2024.
//

#include "Map.h"

Map::Map() {
    sdlTexture_sand = TextureManager::LoadTexture("../assets/sand.png");
    sdlTexture_grass = TextureManager::LoadTexture("../assets/grass.png");
    sdlTexture_concrete = TextureManager::LoadTexture("../assets/wall.png");
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
    sdlRect_src.h = sdlRect_dst.h = 64;
    sdlRect_src.w = sdlRect_dst.w = 64;
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            int i_type = iA_tileTexturesMap[row][col];
            this->sdlRect_dst.x = col*64;
            this->sdlRect_dst.y = row*64;
            TextureManager::DrawTexture(*sdlTextureA_tiles[i_type], sdlRect_src, sdlRect_dst);
        }
    }
}

void Map::RenderObscuringMap() {
    sdlRect_src.h = sdlRect_dst.h = 96;
    sdlRect_src.w = sdlRect_dst.w = 64;
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            int i_type = iA_tileTexturesMap[row][col];
            if(i_type == 0) {
                this->sdlRect_dst.x = col*64;
                this->sdlRect_dst.y = row*64-32;
                TextureManager::DrawTexture(*sdlTextureA_tiles[i_type], sdlRect_src, sdlRect_dst);
            }
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

bool Map::IsWall(int tileX, int tileY) {
    if(iA_tileTexturesMap[tileY][tileX] == 0) return true;
    else return false;
}

