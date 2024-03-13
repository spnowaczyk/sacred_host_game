//
// Created by Admin on 05.03.2024.
//

#ifndef SACRED_HOST_CHARACTERGO_H
#define SACRED_HOST_CHARACTERGO_H

#include "GameObject.h"
#include "deque"

class TextBox;


class CharacterGO : public GameObject {
public:
    CharacterGO(std::string name, const char* textureSheet, int width, int height, int xTile, int yTile, ObjectManager* menager);
    ~CharacterGO() override;
    void Update() override;

    void Move(int tileX, int tileY);
    void SelectDestination();
    void MakeStep(int speed);

private:
    TextBox* textBox_position;
    std::deque<std::pair<int, int>> Diip_WalkPath;
};


#endif //SACRED_HOST_CHARACTERGO_H
