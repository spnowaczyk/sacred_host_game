//
// Created by Admin on 07.03.2024.
//

#include "Pinpoint.h"
#include "Game.h"

Pinpoint::Pinpoint(int tileX, int tileY) : VisualEffect() {
    i_tileX = tileX;
    i_tileY = tileY;
    i_tilesHeight = 1;
    i_tilesWidth = 1;
    i_cnt = 60;

    sdlTex_texture = TextureManager::LoadTexture("../assets/pinpoint.png");

    sdlRect_srcRect.x = 0;
    sdlRect_srcRect.y = 0;

    sdlRect_srcRect.h = sdlRect_dstRect.h = i_tilesHeight*64;
    sdlRect_srcRect.w = sdlRect_dstRect.w = i_tilesWidth*64;

    sdlRect_dstRect.x = i_tileX*64;
    sdlRect_dstRect.y = i_tileY*64;

    Game::i_pinPoints++;
}

Pinpoint::~Pinpoint() {
    Game::i_pinPoints--;
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

