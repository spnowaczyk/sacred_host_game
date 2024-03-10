//
// Created by Admin on 10.03.2024.
//

#include "FadingTextBox.h"

FadingTextBox::FadingTextBox(int posX, int posY, int reds, int greens, int blues, int size, const char *message,
                             int alpha) : TextBox(posX, posY, reds, greens, blues, size, message, alpha) {
    i_cnt = 90;
}

FadingTextBox::~FadingTextBox() {

}

void FadingTextBox::Update() {
    TextBox::Update();
    if(i_cnt > 0) {
        i_cnt--;
        SDL_SetTextureAlphaMod(sdlTexture_texture, i_cnt * 2);
    } else if(i_cnt <= 0) b_markedToDeath = true;
}
