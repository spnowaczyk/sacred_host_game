//
// Created by Admin on 10.03.2024.
//

#include "ObjectManager.h"
#include "Game.h"

ObjectManager::ObjectManager(SFXManager* sfxManager) {
    this->cl_layer = new CollisionLayer();
    this->sfxMan_manager = sfxManager;

    for(int y = 0; y < 12; y++) {
        for(int x = 0; x < 20; x++) {
            goA_gameObjectsByLocals[y][x] = nullptr;
        }
    }
}

ObjectManager::~ObjectManager() {
    delete cl_layer;
}

void ObjectManager::SetCollidersOccupied(int localX, int localY) {
    for (int i = 0; i < 4; ++i) {
        cl_layer->AddCollider(i, localX, localY);
    }
}

void ObjectManager::FixSharedColliders(int localX, int localY) {
    for (int i = 0; i < 4; ++i) {
        GameObject* go_adjacent;
        switch (i) {
            case 0:
                go_adjacent = GetObjectByLocals(localX, localY - 1);
                if(go_adjacent) {
                    cl_layer->AddCollider(i, localX, localY);
                }
                break;
            case 1:
                go_adjacent = GetObjectByLocals(localX + 1, localY);
                if(go_adjacent) {
                    cl_layer->AddCollider(i, localX, localY);
                }
                break;
            case 2:
                go_adjacent = GetObjectByLocals(localX, localY + 1);
                if(go_adjacent) {
                    cl_layer->AddCollider(i, localX, localY);
                }
                break;
            case 3:
                go_adjacent = GetObjectByLocals(localX - 1, localY);
                if(go_adjacent) {
                    cl_layer->AddCollider(i, localX, localY);
                }
                break;

        }
    }
}

void ObjectManager::SetCollidersUnoccupied(int localX, int localY) {
    for (int i = 0; i < 4; ++i) {
        cl_layer->RestoreCollider(i, localX, localY);
    }
    std::cout << localX << "+++" << localY << std::endl;
}

GameObject* ObjectManager::CreateCharacter(std::string name, const char *textureSheet, int width, int height, int xTile,
                                           int yTile) {
    GameObject* object = new CharacterGO(name, textureSheet, width, height, xTile, yTile, this, sfxMan_manager);
    goA_gameObjectsByLocals[yTile][xTile] = object;
    goV_gameObjectsGeneral.push_back(object);
    SetCollidersOccupied(xTile, yTile);
    return object;
}

GameObject * ObjectManager::CreateObject(std::string name, const char *textureSheet, int width, int height, int xTile, int yTile, std::string message) {
    GameObject* object = new GameObject(name, textureSheet, width, height, xTile, yTile, this, sfxMan_manager, message);
    goA_gameObjectsByLocals[yTile][xTile] = object;
    goV_gameObjectsGeneral.push_back(object);
    SetCollidersOccupied(xTile, yTile);
    return object;
}

void ObjectManager::ChangeObjectLocals(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY) {
    GameObject* object = goA_gameObjectsByLocals[oldLocalY][oldLocalX];
    goA_gameObjectsByLocals[oldLocalY][oldLocalX] = nullptr;
    goA_gameObjectsByLocals[newLocalY][newLocalX] = object;
    SetCollidersOccupied(newLocalX, newLocalY);
    SetCollidersUnoccupied(oldLocalX, oldLocalY);
    FixSharedColliders(oldLocalX, oldLocalY);
}

GameObject *ObjectManager::GetObjectByLocals(int localX, int localY) {
    if(localX < Game::i_tilesX && localY < Game::i_tilesY) return goA_gameObjectsByLocals[localY][localX]; // CHANGE THIS SHIT
    else return nullptr;                                                           // THIS IS FUCKING IMMORAL
}

void ObjectManager::DeleteObjectFromLocals(int localX, int localY) {
    goA_gameObjectsByLocals[localY][localX];
    //here delete collider
}

void ObjectManager::DestroyObject(GameObject *object) {
    if(goA_gameObjectsByLocals[object->getIYTile()][object->getIXTile()] == object){
        goA_gameObjectsByLocals[object->getIYTile()][object->getIXTile()] = nullptr;
    }
    SetCollidersUnoccupied(object->getIXTile(), object->getIYTile());
    object->MarkToDeath();
}

void ObjectManager::Update() {
    for(auto i : goV_gameObjectsGeneral) i->Update();

    if(!goV_gameObjectsGeneral.empty()) {
        for(int i = goV_gameObjectsGeneral.size() - 1; i >= 0; i--) {
            if(goV_gameObjectsGeneral[i]->IsMarkedToDeath()) {
                delete goV_gameObjectsGeneral[i];
                goV_gameObjectsGeneral.erase(goV_gameObjectsGeneral.begin() + i );
            }
        }
    }
}

void ObjectManager::Render() {
    for(auto i : goV_gameObjectsGeneral) i->Render();
}

void ObjectManager::Adjust(int previousTileSize) {
    for(auto i : goV_gameObjectsGeneral) i->Adjust(previousTileSize);
}





