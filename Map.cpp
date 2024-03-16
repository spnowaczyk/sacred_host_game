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
    sdlRect_src.h = Game::i_srcTileSize;
    sdlRect_dst.h = Game::i_tileSize;
    sdlRect_src.w = Game::i_srcTileSize;
    sdlRect_dst.w = Game::i_tileSize;
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            int i_type = iA_tileTexturesMap[row][col];
            this->sdlRect_dst.x = col*Game::i_tileSize;
            this->sdlRect_dst.y = row*Game::i_tileSize;
            TextureManager::DrawTexture(*sdlTextureA_tiles[i_type], sdlRect_src, sdlRect_dst);
        }
    }
}

void Map::RenderObscuringMap() {
    sdlRect_src.h = Game::i_srcTileSize * 1.5;
    sdlRect_dst.h = Game::i_tileSize * 1.5;
    sdlRect_src.w = Game::i_srcTileSize;
    sdlRect_dst.w = Game::i_tileSize;
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            int i_type = iA_tileTexturesMap[row][col];
            if(i_type == 0) {
                this->sdlRect_dst.x = col*Game::i_tileSize;
                this->sdlRect_dst.y = row*Game::i_tileSize - Game::i_tileSize * 0.5;
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

