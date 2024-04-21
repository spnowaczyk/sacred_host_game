//
// Created by Admin on 07.03.2024.
//

#include "Pinpoint.h"
#include "Game.h"

Pinpoint::Pinpoint(int tileX, int tileY, SFXManager* sfxManager) : VisualEffect(sfxManager) {
    i_tileX = tileX;
    i_tileY = tileY;
    i_tilesHeight = 1;
    i_tilesWidth = 1;
    i_cnt = 60;

    sdlTex_texture = TextureManager::LoadTexture("../assets/pinpoint2.png");

    sdlRect_srcRect.x = 0;
    sdlRect_srcRect.y = 0;

    sdlRect_srcRect.h = i_tilesHeight*Game::i_srcTileSize;
    sdlRect_dstRect.h = i_tilesHeight*Game::i_tileSize;
    sdlRect_srcRect.w = i_tilesHeight*Game::i_srcTileSize;
    sdlRect_dstRect.w = i_tilesWidth*Game::i_tileSize;

    sdlRect_dstRect.x = i_tileX*Game::i_tileSize;
    sdlRect_dstRect.y = i_tileY*Game::i_tileSize;

    Game::i_pinPoints++;
}

Pinpoint::~Pinpoint() {
    Game::i_pinPoints--;
    SDL_DestroyTexture(sdlTex_texture);
}

void Pinpoint::Update() {
    if(i_cnt > 0) {
        i_cnt--;
        SDL_SetTextureAlphaMod(sdlTex_texture, i_cnt * 2);
    } else if(i_cnt <= 0) b_markedToDeath = true;
}

void Pinpoint::Render() {
    SDL_RenderCopy(Game::sdlRen_renderer, sdlTex_texture, &sdlRect_srcRect, &sdlRect_dstRect);
}

