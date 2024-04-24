//
// Created by s.nowaczyk on 12.03.2024.
//

#include "CollisionLayer.h"
#include "Game.h"
#include "fstream"

CollisionLayer::CollisionLayer() {
    sdlRect_srcRect.x = sdlRect_srcRect.y = 0;
    sdlRect_srcRect.w = i_walliderTexX;
    sdlRect_srcRect.h = i_walliderTexY;
    sdlRect_dstRectHorizontal.w = Game::i_tileSize;
    sdlRect_dstRectHorizontal.h = i_walliderTexY;
    sdlRect_dstRectVertical.w = i_walliderTexX;
    sdlRect_dstRectVertical.h = Game::i_tileSize;

    sdlTex_texture = TextureManager::LoadTexture("../assets/wallider.png");

    i_height = Game::i_tilesY;
    i_width = Game::i_tilesX;

    bV_colliders = new std::vector<bool>;
    bV_colliders_template = new std::vector<bool>;
}
CollisionLayer::~CollisionLayer() {
    SDL_DestroyTexture(sdlTex_texture);
    delete bV_colliders;
}

void CollisionLayer::LoadColliders(std::string path) {
    char c_collider;
    std::fstream fs_collidersFile;
    fs_collidersFile.open(path);

    while (fs_collidersFile.get(c_collider)) {
        if(c_collider != ',') {
            switch (c_collider) {
                case '0':
                    bV_colliders->push_back(false);
                    break;
                case '1':
                    bV_colliders->push_back(true);
                    break;
                default:
                    bV_colliders->push_back(true);
                    break;
            }
        }
    }
    fs_collidersFile.close();

    if(bV_colliders && bV_colliders_template) {
        *bV_colliders_template = *bV_colliders;
    }
}

int CollisionLayer::GetColliderId(int direction, int localX, int localY) {
    int topCollider = (2 * i_height + 1) * localX + (2 * localY);
    switch (direction) {
        case 0:
            return topCollider;
            break;
        case 1:
            return topCollider + 2 + (2 * i_height);
            break;
        case 2:
            return topCollider + 2;
            break;
        case 3:
            return topCollider + 1;
            break;
        default:
            return -1;
            break;
    }
}

void CollisionLayer::AddCollider(int direction, int localX, int localY) {
    (*bV_colliders)[GetColliderId(direction, localX, localY)] = true;
}

void CollisionLayer::DeleteCollider(int direction, int localX, int localY) {
    (*bV_colliders)[GetColliderId(direction, localX, localY)] = false;
}

void CollisionLayer::RestoreCollider(int direction, int localX, int localY) {
    int colliderId = GetColliderId(direction, localX, localY);
    (*bV_colliders)[colliderId] = (*bV_colliders_template)[colliderId];
}

bool CollisionLayer::DetectCollision(int direction, int localX, int localY) {
    return (*bV_colliders)[GetColliderId(direction, localX, localY)];
}

std::deque<std::pair<int, int>> CollisionLayer::FindWay(int startX, int startY, int finishX, int finishY) {
    std::vector<std::vector<Step *>> generations;
    std::vector<Step *> gen;

    Step *correctPath = nullptr;
    std::deque<std::pair<int, int>> res;

    gen.push_back(new Step(startX, startY, nullptr));
    generations.push_back(gen);

    while (!generations.back().empty()) {
        std::vector<Step *> tempGen;
        for (auto i: generations.back()) {
            for (int j = 0; j < 4; j++) {
                int newPosX = i->posX + Step::directionsX[j];
                int newPosY = i->posY + Step::directionsY[j];

                bool visitedByOtherStepThisGeneration = false;
                for (auto j: tempGen) {
                    if (newPosX == j->posX && newPosY == j->posY)
                        visitedByOtherStepThisGeneration = true;
                }

                bool visitedByOtherStepOtherGeneration = false;
                for (auto j: generations) {
                    for (auto k: j) {
                        if (newPosX == k->posX &&
                            newPosY == k->posY)
                            visitedByOtherStepOtherGeneration = true;
                    }
                }

                if (!DetectCollision(j, i->posX, i->posY) && !visitedByOtherStepOtherGeneration &&
                    !visitedByOtherStepThisGeneration) {
                    tempGen.push_back(new Step(newPosX, newPosY, i));

                    if (tempGen.back()->posX == finishX && tempGen.back()->posY == finishY) {
                        correctPath = tempGen.back();
                        break;
                    }
                }
                if (correctPath != nullptr) break;
            }
        }
        generations.push_back(tempGen);
        if (correctPath != nullptr) break;
    }

    while (correctPath != nullptr) {
        res.push_front(std::make_pair(correctPath->posX, correctPath->posY));
        correctPath = correctPath->motherCell;
    }

    if(res.empty()) std::cout << "no way man!" << std::endl;

    for(auto g : generations) {
        for(auto h : g) {
            delete h;
        }
    }

    generations.clear();
    return res;
}

void CollisionLayer::Render() {
    for (int y = 0; y < Game::i_tilesY; ++y) {
        for (int x = 0; x < Game::i_tilesX; ++x) {
            if ((*bV_colliders)[GetColliderId(0, x, y)]) {
                sdlRect_dstRectHorizontal.y = y * Game::i_tileSize - (i_walliderTexY / 2);
                sdlRect_dstRectHorizontal.x = x * Game::i_tileSize;
                sdlRect_dstRectHorizontal.w = Game::i_tileSize;
                TextureManager::DrawTexture(sdlTex_texture, sdlRect_srcRect, sdlRect_dstRectHorizontal);
            }
        }
    }
    for (int x = 0; x < Game::i_tilesX; ++x) {
        for (int y = 0; y < Game::i_tilesY; ++y) {
            if ((*bV_colliders)[GetColliderId(3, x, y)]) {
                sdlRect_dstRectVertical.y = y * Game::i_tileSize;
                sdlRect_dstRectVertical.x = x * Game::i_tileSize - (i_walliderTexY / 2);
                sdlRect_dstRectVertical.h = Game::i_tileSize;
                TextureManager::DrawTexture(sdlTex_texture, sdlRect_srcRect, sdlRect_dstRectVertical);
            }
        }
    }
    for (int x = 0; x < Game::i_tilesX; ++x) {
        if ((*bV_colliders)[GetColliderId(2, x, Game::i_tilesY - 1)]) {
            sdlRect_dstRectHorizontal.y = Game::i_tilesY * Game::i_tileSize - (i_walliderTexY / 2);
            sdlRect_dstRectHorizontal.x = x * Game::i_tileSize;
            sdlRect_dstRectHorizontal.w = Game::i_tileSize;
            TextureManager::DrawTexture(sdlTex_texture, sdlRect_srcRect, sdlRect_dstRectHorizontal);
        }
    }
    for (int y = 0; y < Game::i_tilesY; ++y) {
        if ((*bV_colliders)[GetColliderId(1, Game::i_tilesX-1, y)]) {
            sdlRect_dstRectVertical.y = y * Game::i_tileSize;
            sdlRect_dstRectVertical.x = Game::i_tilesX * Game::i_tileSize - (i_walliderTexY / 2);
            sdlRect_dstRectVertical.h = Game::i_tileSize;
            TextureManager::DrawTexture(sdlTex_texture, sdlRect_srcRect, sdlRect_dstRectVertical);
        }
    }
}




