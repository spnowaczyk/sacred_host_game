//
// Created by Admin on 08.03.2024.
//

#include "TextManager.h"

TextBox* TextManager::CreateTextBox(int posX, int posY, const char *message, int size, int reds, int greens, int blues,
                                    int alpha) {
    TextBox* textBox_box = new TextBox(posX, posY, reds, greens, blues, size, message, alpha);
    TextManager::textBoxV_textBoxes.push_back(textBox_box);
    return textBox_box;
}

void TextManager::DestroyTextBox(TextBox* textBox_box) {
    textBox_box->MarkToDeath();
}

void TextManager::Update() {
    for(auto i : TextManager::textBoxV_textBoxes) i->Update();

    if(!TextManager::textBoxV_textBoxes.empty()) {
        for(int i = TextManager::textBoxV_textBoxes.size() - 1; i >= 0; i--) {
            if(TextManager::textBoxV_textBoxes[i]->IsMarkedToDeath()) {
                delete TextManager::textBoxV_textBoxes[i];
                TextManager::textBoxV_textBoxes.erase(TextManager::textBoxV_textBoxes.begin() + i );
            }
        }
    }
}

void TextManager::Render() {
    for(auto i : TextManager::textBoxV_textBoxes) i->Render();
}

void TextManager::WriteMessage(TextBox* textBox_box, const char *message) {
    if(textBox_box != nullptr) textBox_box->WriteMessage(message);
}

void TextManager::WriteMessage(TextBox* textBox_box, std::string message) {
    if(textBox_box != nullptr) textBox_box->WriteMessage(message.c_str());
}
