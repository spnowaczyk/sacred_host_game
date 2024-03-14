//
// Created by s.nowaczyk on 12.03.2024.
//

#include "CollisionLayer.h"
#include "Game.h"

CollisionLayer::CollisionLayer() {
    sdlRect_srcRect.x = sdlRect_srcRect.y = 0;
    sdlRect_srcRect.w = sdlRect_srcRect.h = 64;

    sdlRect_dstRect.w = sdlRect_dstRect.h = 64;

    sdlTex_texture = TextureManager::LoadTexture("../assets/collider.png");

    i_length = 12;
    i_width = 20;

}
CollisionLayer::~CollisionLayer() {

}

void CollisionLayer::LoadColliders(Map* map) {
    for (int row = 0; row < 12; ++row) {
        for (int col = 0; col < 20; ++col) {
            bA_colliders[row][col] = map->IsWall(col, row);
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
    if(localX >= 0 && localX < i_width && localY >= 0 && localY < i_length) {
        return bA_colliders[localY][localX];
    }
    else return true;
}

std::deque<std::pair<int, int>> CollisionLayer::findWay(int startX, int startY, int finishX, int finishY) {
    std::vector<std::vector<Step*>> generations;
    std::vector<Step*> gen;

    Step* correctPath = nullptr;
    std::deque<std::pair<int, int>> res;

    gen.push_back(new Step(startX, startY, nullptr));
    generations.push_back(gen);

    do {
        std::vector<Step*> tempGen;
        for(auto i : generations.back()) {
            for(int j = 0; j < 4; j++) {
                int newPosX = i->posX + Step::directionsX[j];
                int newPosY = i->posY + Step::directionsY[j];

                bool visitedByOtherStepThisGeneration = false;
                for(auto j : tempGen) {
                    if(newPosX == j->posX && newPosY == j->posY) visitedByOtherStepThisGeneration = true;
                }

                bool visitedByOtherStepPreviousGeneration = false;
                for(auto j : generations) {
                    for(auto k : j) {
                        if(newPosX == k->posX && newPosY == k->posY) visitedByOtherStepThisGeneration = true;
                    }
                }

                if(!DetectCollision(newPosX,newPosY) && !visitedByOtherStepThisGeneration && !visitedByOtherStepPreviousGeneration) {
                    tempGen.push_back(new Step(newPosX, newPosY, i));
                    if(tempGen.back()->posX == finishX && tempGen.back()->posY == finishY) {
                        correctPath = tempGen.back();
                        break;
                    }
                }
            }
            if(correctPath != nullptr) break;
        }
        generations.push_back(tempGen);
        if(correctPath != nullptr) break;
    } while (!generations.back().empty());

    while (correctPath != nullptr) {
        res.push_front(std::make_pair(correctPath->posX, correctPath->posY));
        correctPath = correctPath->motherCell;
    }

    for(auto i : generations) {
        for(auto j : i) {
            delete j;
        }
    }
    return res;
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