//
// Created by Admin on 05.03.2024.
//

#ifndef SACRED_HOST_TEXTBOX_H
#define SACRED_HOST_TEXTBOX_H

#include "SDL_ttf.h"
#include <vector>


class TextBox {
public:
    TextBox(int posX, int posY, int reds, int greens, int blues, int size, const char *message,  int alpha);
    void WriteMessage(const char* message);
    void Render();
    void Update();
    bool IsMarkedToDeath();
    void MarkToDeath();

private:
    SDL_Surface* sdlSurface_surface;
    SDL_Texture* sdlTexture_texture;
    TTF_Font* ttfFont_font;
    SDL_Color sdlColor_color;
    SDL_Rect sdlRect_rect;

    bool b_markedToDeath;
};


#endif //SACRED_HOST_TEXTBOX_H
