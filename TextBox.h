//
// Created by Admin on 05.03.2024.
//

#ifndef SACRED_HOST_TEXTBOX_H
#define SACRED_HOST_TEXTBOX_H

#include "SDL_ttf.h"
#include <vector>


class TextBox {
public:
    TextBox(int posX, int posY, int reds, int greens, int blues, int size, const char *message = "",  int aplha = 255);
    void WriteMessage(const char* message);
    void Render();

    static std::vector<TextBox*> textBoxV_textBoxes;
private:
    SDL_Surface* sdlSurface_surface;
    SDL_Texture* sdlTexture_texture;
    TTF_Font* ttfFont_font;
    SDL_Color sdlColor_color;
    SDL_Rect sdlRect_rect;
};


#endif //SACRED_HOST_TEXTBOX_H
