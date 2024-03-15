//
// Created by Admin on 10.03.2024.
//

#ifndef CLION_DEBUG_LOG_TXT_FADINGTEXTBOX_H
#define CLION_DEBUG_LOG_TXT_FADINGTEXTBOX_H

#include "TextBox.h"

class FadingTextBox : public TextBox{
public:
    FadingTextBox(int posX, int posY, int reds, int greens, int blues, int size, const char *message, int alpha);
    ~FadingTextBox() override;
    void Update() override;

private:
    int i_cnt;
};


#endif //CLION_DEBUG_LOG_TXT_FADINGTEXTBOX_H
