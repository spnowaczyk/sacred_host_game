//
// Created by Admin on 05.03.2024.
//

#ifndef SACRED_HOST_CHARACTERGO_H
#define SACRED_HOST_CHARACTERGO_H

#include "GameObject.h"


class CharacterGO : public GameObject {
public:
    CharacterGO(std::string name, const char* textureSheet, int width = 64, int height = 64, int xPos = 0, int yPos = 0);
    void Update();

    void Move(int tileX, int tileY);
    void MakeStep();
private:
};


#endif //SACRED_HOST_CHARACTERGO_H
