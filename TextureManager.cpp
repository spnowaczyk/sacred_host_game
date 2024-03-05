//
// Created by Admin on 29.02.2024.
//

#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture(const char *path) {
    SDL_Texture* sdlTex_Texture;
    SDL_Surface* sdlSurf_Surface = IMG_Load(path);
    sdlTex_Texture = SDL_CreateTextureFromSurface(Game::sdlRen_renderer, sdlSurf_Surface);
    SDL_FreeSurface(sdlSurf_Surface);
    return sdlTex_Texture;
}

void TextureManager::DrawTexture(SDL_Texture *texture, SDL_Rect src, SDL_Rect dst) {
    SDL_RenderCopy(Game::sdlRen_renderer, texture, &src, &dst);
}
