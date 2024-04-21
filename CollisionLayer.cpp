//
// Created by s.nowaczyk on 12.03.2024.
//

#include "CollisionLayer.h"
#include "Game.h"
#include "fstream"

CollisionLayer::CollisionLayer() {
    sdlRect_srcRect.x = sdlRect_srcRect.y = 0;
    sdlRect_srcRect.w = sdlRect_srcRect.h = Game::i_tileSize;

    sdlRect_dstRect.w = sdlRect_dstRect.h = Game::i_tileSize;

    sdlTex_texture = TextureManager::LoadTexture("../assets/collider.png");

    i_height = Game::i_tilesY;
    i_width = Game::i_tilesX;

    bV_colliders = new std::vector<bool>;
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
}

void CollisionLayer::RemoveCollider(int localX, int localY) {
}

void CollisionLayer::AddCollider(int localX, int localY) {
}

void CollisionLayer::MoveCollider(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY) {

}

bool CollisionLayer::DetectCollision(int direction, int x, int y) {
    int topCollider = (2 * i_height + 1) * x + (2 * y);
    switch (direction) {
        case 0:
            return (*bV_colliders)[topCollider];
            break;
        case 1:
            std::cout << "collider id: " << topCollider + 2 + (2 * i_height) << "| if \"1\" collider detected: "
                      << (*bV_colliders)[topCollider + 2 + (2 * i_height)] << std::endl;
            return (*bV_colliders)[topCollider + 2 + (2 * i_height)];
            break;
        case 2:
            std::cout << "collider id: " << topCollider + 2 << "| if \"1\" collider detected: "
                      << (*bV_colliders)[topCollider + 2] << std::endl;
            return (*bV_colliders)[topCollider + 2];
            break;
        case 3:
            std::cout << "collider id: " << topCollider + 1 << "| if \"1\" collider detected: "
                      << (*bV_colliders)[topCollider + 1] << std::endl;
            return (*bV_colliders)[topCollider + 1];
            break;
    }
}

std::deque<std::pair<int, int>> CollisionLayer::findWay(int startX, int startY, int finishX, int finishY) {
    std::vector<std::vector<Step *>> generations;
    std::vector<Step *> gen;

    Step *correctPath = nullptr;
    std::deque<std::pair<int, int>> res;

    gen.push_back(new Step(startX, startY, nullptr));
    generations.push_back(gen);

    int steps = 0;

    while (!generations.back().empty()) {
        std::cout << "new cycle" << std::endl;
        std::vector<Step *> tempGen;
        for (auto i: generations.back()) {
            for (int j = 0; j < 4; j++) {
                int newPosX = i->posX + Step::directionsX[j];
                int newPosY = i->posY + Step::directionsY[j];

                std::cout << "since the old position was: " << i->posX << "|" << i->posY
                          << " and modif was: "
                          << Step::directionsX[j] << "|" << Step::directionsY[j] << " new position is "
                          << newPosX << "|" << newPosY
                          << std::endl;

                bool visitedByOtherStepThisGeneration = false;
                for (auto j: tempGen) {
                    if (newPosX == j->posX && newPosY == j->posY)
                        visitedByOtherStepThisGeneration = true;
                }
                std::cout << "this gen checked" << std::endl;

                bool visitedByOtherStepOtherGeneration = false;
                for (auto j: generations) {
                    for (auto k: j) {
                        if (newPosX == k->posX &&
                            newPosY == k->posY)
                            visitedByOtherStepOtherGeneration = true;
                    }
                }
                std::cout << "other gen checked" << std::endl;

                if (!DetectCollision(j, i->posX, i->posY) && !visitedByOtherStepOtherGeneration &&
                    !visitedByOtherStepThisGeneration) {
                    tempGen.push_back(new Step(newPosX, newPosY, i));
                    std::cout << ">>>>>>>>>coord pushed " << tempGen.back()->posX << "|"
                              << tempGen.back()->posY
                              << std::endl;
                    if (tempGen.back()->posX == finishX && tempGen.back()->posY == finishY) {
                        correctPath = tempGen.back();
                        break;
                    }
                }
                if (correctPath != nullptr) break;
            }
            for (auto g: tempGen) {
                std::cout << g->posX << " | ";
                std::cout << g->posY << std::endl;
            }
        }
        generations.push_back(tempGen);
        if (correctPath != nullptr) break;
    }

    while (correctPath != nullptr) {
        res.push_front(std::make_pair(correctPath->posX, correctPath->posY));
        correctPath = correctPath->motherCell;
    }

    for (auto i: res) {
        std::cout << "X: " << i.first << " Y: " << i.second << std::endl;
    }
    if(res.empty()) std::cout << "no way man!" << std::endl;

    for(auto g : generations) {
        for(auto h : g) {
            delete h;
        }
    }
    generations.clear();

    return res;}

void CollisionLayer::Render() {

}