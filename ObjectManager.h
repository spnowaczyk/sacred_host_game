//
// Created by Admin on 10.03.2024.
//

#ifndef CLION_DEBUG_LOG_TXT_OBJECTMANAGER_H
#define CLION_DEBUG_LOG_TXT_OBJECTMANAGER_H

#include "iostream"
#include "vector"

class GameObject;
class CollisionLayer;
class SFXManager;

class ObjectManager {
public:
    ObjectManager(SFXManager* sfxManager);
    ~ObjectManager();
    GameObject* CreateCharacter(std::string name, const char* textureSheet, int width = 1, int height = 1, int xTile = 0, int yTile = 0);
    GameObject* CreateObject(std::string name, const char *textureSheet, int width = 1, int height = 1, int xTile = 0, int yTile = 0, std::string message = "");
    void ChangeObjectLocalsAndColliders(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY);
    GameObject* getObjectByLocals(int localX, int LocalY);
    void DeleteObjectFromLocals(int LocalX, int LocalY);
    void DestroyObject(GameObject* object);
    void Update();
    void Render();
    void Adjust(int previousTileSize);

    GameObject* goA_gameObjectsByLocals[12][20];
    std::vector<GameObject*> goV_gameObjectsGeneral;
    CollisionLayer* cl_layer;
    SFXManager* sfxMan_manager;

};


#endif //CLION_DEBUG_LOG_TXT_OBJECTMANAGER_H
