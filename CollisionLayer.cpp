//
// Created by s.nowaczyk on 12.03.2024.
//

#include "CollisionLayer.h"

CollisionLayer::CollisionLayer() {
    sdlRect_srcRect.x = sdlRect_srcRect.y = 0;
    sdlRect_srcRect.w = sdlRect_srcRect.h = 64;

    sdlRect_dstRect.w = sdlRect_dstRect.h = 64;

    sdlTex_texture = TextureManager::LoadTexture("../assets/collider.png");

}

void CollisionLayer::LoadColliders(int collidersArray[12][20]) {
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            bA_colliders[row][col] = collidersArray[row][col];
        }
    }
}

void CollisionLayer::RandomColliders() {
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            this->bA_colliders[row][col] = (rand()%3)/2 % 2;
        }
    }
}

void CollisionLayer::RemoveCollider(int localX, int localY) {
    bA_colliders[localY][localX] = false;
}

void CollisionLayer::AddCollider(int localX, int localY) {
    bA_colliders[localY][localX] = true;
}

void CollisionLayer::MoveCollider(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY) {
    bA_colliders[oldLocalY][oldLocalX] = false;
    bA_colliders[newLocalY][newLocalX] = true;
}

bool CollisionLayer::DetectCollision(int localX, int localY) {
    return bA_colliders[localY][localX];
}

void CollisionLayer::Render() {
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            if(bA_colliders[row][col] == true) {
                this->sdlRect_dstRect.x = col * 64;
                this->sdlRect_dstRect.y = row * 64;

                SDL_RenderCopy(Game::sdlRen_renderer, sdlTex_texture, &sdlRect_srcRect, &sdlRect_dstRect);
            }
        }
    }
}
