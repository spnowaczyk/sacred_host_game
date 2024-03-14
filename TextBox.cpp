//
// Created by Admin on 05.03.2024.
//

#include "TextBox.h"
#include "SDL.h"
#include "Game.h"

TextBox::TextBox(int posX, int posY, int reds, int greens, int blues, int size, const char *message, int alpha) {
    b_markedToDeath = false;
    ttfFont_font = TTF_OpenFont("steiner.ttf", size);
    sdlColor_color.r = reds;
    sdlColor_color.g = greens;
    sdlColor_color.b = blues;
    sdlColor_color.a = alpha;
    TTF_SizeText(ttfFont_font, message, &sdlRect_rect.w, &sdlRect_rect.h);
    sdlSurface_surface = TTF_RenderText_Solid(ttfFont_font, message, sdlColor_color);
    sdlTexture_texture = SDL_CreateTextureFromSurface(Game::sdlRen_renderer, sdlSurface_surface);
    sdlRect_rect.x = posX;
    sdlRect_rect.y = posY;
    SDL_FreeSurface(sdlSurface_surface);
    Game::i_textBoxes++;
    std::cout << "created textbox with message " + std::string(message) << std::endl;
}

TextBox::~TextBox() {
    Game::i_textBoxes--;
    TTF_CloseFont(ttfFont_font);
    SDL_DestroyTexture(sdlTexture_texture);
}

void TextBox::WriteMessage(const char *message) {
    TTF_SizeText(ttfFont_font, message, &sdlRect_rect.w, &sdlRect_rect.h);
    sdlSurface_surface = TTF_RenderText_Solid(ttfFont_font, message, sdlColor_color);
    SDL_DestroyTexture(sdlTexture_texture);
    sdlTexture_texture = SDL_CreateTextureFromSurface(Game::sdlRen_renderer, sdlSurface_surface);
    SDL_FreeSurface(sdlSurface_surface);
}

void TextBox::Render() {
    SDL_RenderCopy(Game::sdlRen_renderer, sdlTexture_texture, NULL, &sdlRect_rect);
}

void TextBox::Update() {

}

bool TextBox::IsMarkedToDeath() {
    return b_markedToDeath;
}

void TextBox::MarkToDeath() {
    b_markedToDeath = true;
}
