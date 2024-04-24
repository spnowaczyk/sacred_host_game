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
    int GetColliderId(int direction, int localX, int localY);

    void AddCollider(int direction, int localX, int localY);
    void DeleteCollider(int direction, int localX, int localY);
    void RestoreCollider(int direction, int localX, int localY);

    bool DetectCollision(int direction, int localX, int localY);
    std::deque<std::pair<int, int>> FindWay(int startX, int startY, int finishX, int finishY);

    void Render();

private:
    std::vector<bool>* bV_colliders;
    std::vector<bool>* bV_colliders_template;

    SDL_Texture* sdlTex_texture;
    SDL_Rect sdlRect_srcRect;
    SDL_Rect sdlRect_dstRectHorizontal;
    SDL_Rect sdlRect_dstRectVertical;

    int i_width;
    int i_height;

    int i_walliderTexX = 8;
    int i_walliderTexY = 8;
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
