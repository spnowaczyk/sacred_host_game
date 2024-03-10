//
// Created by Admin on 05.03.2024.
//

#ifndef SACRED_HOST_CHARACTERGO_H
#define SACRED_HOST_CHARACTERGO_H

#include "GameObject.h"

class TextBox;


class CharacterGO : public GameObject {
public:
    CharacterGO(std::string name, const char* textureSheet, int width = 64, int height = 64, int xTile = 0, int yTile = 0);
    ~CharacterGO() override;
    void Update() override;

    void Move(int tileX, int tileY);
    void SelectDestination();
    void MakeStep(int speed);

private:
    TextBox* textBox_position;
};


#endif //SACRED_HOST_CHARACTERGO_H
