//
// Created by s.nowaczyk on 12.03.2024.
//

#ifndef CLION_DEBUG_LOG_TXT_COLLISIONLAYER_H
#define CLION_DEBUG_LOG_TXT_COLLISIONLAYER_H

#include <string>
#include <vector>
#include "SDL.h"
#include "deque"

class Map;

class CollisionLayer {
public:
    CollisionLayer();
    ~CollisionLayer();

    void LoadColliders(std::string path);
    void RemoveCollider(int localX, int localY);
    void AddCollider(int localX, int localY);
    void MoveCollider(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY);

    bool DetectCollision(int direction, int x, int y);
    std::deque<std::pair<int, int>> findWay(int startX, int startY, int finishX, int finishY);

    void Render();

private:
    std::vector<bool>* bV_colliders;

    SDL_Texture* sdlTex_texture;
    SDL_Rect sdlRect_srcRect;
    SDL_Rect sdlRect_dstRect;

    int i_width;
    int i_height;
};


class Step{
public:
    Step(int x, int y, Step* mother) : posX(x), posY(y), motherCell(mother) {
    }
    ~Step() {
    }

    int posX, posY;
    Step* motherCell;

    static constexpr int directionsX[4] = {0,1, 0, -1};
    static constexpr int directionsY[4] = {-1, 0, 1, 0};
};

#endif //CLION_DEBUG_LOG_TXT_COLLISIONLAYER_H
