//
// Created by s.nowaczyk on 12.03.2024.
//

#ifndef CLION_DEBUG_LOG_TXT_COLLISIONLAYER_H
#define CLION_DEBUG_LOG_TXT_COLLISIONLAYER_H

#include "Game.h"

class CollisionLayer {
public:
    CollisionLayer();

    void LoadColliders(int collidersArray [12][20]);
    void RandomColliders();
    void RemoveCollider(int localX, int localY);
    void AddCollider(int localX, int localY);
    void MoveCollider(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY);

    bool DetectCollision(int localX, int localY);

    void Render();

private:
    bool bA_colliders[12][20];

    SDL_Texture* sdlTex_texture;
    SDL_Rect sdlRect_srcRect;
    SDL_Rect sdlRect_dstRect;
};


#endif //CLION_DEBUG_LOG_TXT_COLLISIONLAYER_H
