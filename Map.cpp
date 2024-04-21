//
// Created by Admin on 02.03.2024.
//

#include "Map.h"
#include <fstream>

Map::Map() {

}

Map::~Map() {

}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
    char c_tile;
    std::string s_tempTileString;
    std::fstream fs_mapFile;
    fs_mapFile.open(path);

    while (fs_mapFile.get(c_tile)) {
        if(c_tile != ',') {
            s_tempTileString += c_tile;
        } else {
            iV_tiles.push_back(std::stoi(s_tempTileString));
            s_tempTileString.clear();
        }
    }
    fs_mapFile.close();
}

void Map::RenderMap() {
    sdlRect_src.h = Game::i_srcTileSize;
    sdlRect_dst.h = Game::i_tileSize;
    sdlRect_src.w = Game::i_srcTileSize;
    sdlRect_dst.w = Game::i_tileSize;
    int i_cnt = 0;
    for (int y = 0; y < Game::i_tilesY; y++) {
        for (int x = 0; x < Game::i_tilesX; x++) {
            sdlRect_src.x = (iV_tiles[i_cnt] % 8) * Game::i_srcTileSize;
            sdlRect_src.y = (iV_tiles[i_cnt] / 8) * Game::i_srcTileSize;
            sdlRect_dst.x = x * Game::i_tileSize;
            sdlRect_dst.y = y * Game::i_tileSize;
            TextureManager::DrawTexture(sdlTexture_tileset, sdlRect_src, sdlRect_dst);
            i_cnt++;
        }
    }

}

void Map::LoadTileSet(std::string path) {
    this->sdlTexture_tileset = TextureManager::LoadTexture(path.c_str());
}

void Map::RenderObscuringMap() {

}

