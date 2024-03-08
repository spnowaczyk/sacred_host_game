//
// Created by Admin on 08.03.2024.
//

#ifndef CLION_DEBUG_LOG_TXT_TEXTMANAGER_H
#define CLION_DEBUG_LOG_TXT_TEXTMANAGER_H

#include "TextBox.h"
#include <string>


class TextManager {
public:
    static std::vector<TextBox*> textBoxV_textBoxes;

    static TextBox* CreateTextBox(int posX, int posY, const char *message = "", int size = 20, int reds = 255, int greens = 255, int blues = 255,  int alpha = 255);
    static void DestroyTextBox(TextBox*);
    static void WriteMessage(TextBox* textBox_box, const char* message);
    static void WriteMessage(TextBox* textBox_box, std::string message);


    static void Update();
    static void Render();
};


#endif //CLION_DEBUG_LOG_TXT_TEXTMANAGER_H
