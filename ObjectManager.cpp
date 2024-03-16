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

GameObject* ObjectManager::CreateCharacter(std::string name, const char *textureSheet, int width, int height, int xTile,
                                           int yTile) {
    GameObject* object = new CharacterGO(name, textureSheet, width, height, xTile, yTile, this, sfxMan_manager);
    goA_gameObjectsByLocals[yTile][xTile] = object;
    goV_gameObjectsGeneral.push_back(object);
    this->cl_layer->AddCollider(xTile, yTile);
    return object;
}

GameObject * ObjectManager::CreateObject(std::string name, const char *textureSheet, int width, int height, int xTile, int yTile, std::string message) {
    GameObject* object = new GameObject(name, textureSheet, width, height, xTile, yTile, this, sfxMan_manager, message);
    goA_gameObjectsByLocals[yTile][xTile] = object;
    goV_gameObjectsGeneral.push_back(object);
    this->cl_layer->AddCollider(xTile, yTile);
    return object;
}

void ObjectManager::ChangeObjectLocalsAndColliders(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY) {
    GameObject* object = goA_gameObjectsByLocals[oldLocalY][oldLocalX];
    goA_gameObjectsByLocals[oldLocalY][oldLocalX] = nullptr;
    goA_gameObjectsByLocals[newLocalY][newLocalX] = object;
    this->cl_layer->MoveCollider(oldLocalX, oldLocalY, newLocalX, newLocalY);
}

GameObject *ObjectManager::getObjectByLocals(int localX, int localY) {
    return goA_gameObjectsByLocals[localY][localX];
}

void ObjectManager::DeleteObjectFromLocals(int localX, int localY) {
    goA_gameObjectsByLocals[localY][localX];
    this->cl_layer->RemoveCollider(localX, localY);
}

void ObjectManager::DestroyObject(GameObject *object) {
    if(goA_gameObjectsByLocals[object->getIYTile()][object->getIXTile()] == object){
        goA_gameObjectsByLocals[object->getIYTile()][object->getIXTile()] = nullptr;
    }
    this->cl_layer->RemoveCollider(object->getIXTile(), object->getIYTile());
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


