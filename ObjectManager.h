//
// Created by Admin on 10.03.2024.
//

#ifndef CLION_DEBUG_LOG_TXT_OBJECTMANAGER_H
#define CLION_DEBUG_LOG_TXT_OBJECTMANAGER_H

#include "Game.h"

class ObjectManager {
public:
    static GameObject* CreateCharacter(std::string name, const char* textureSheet, int width = 64, int height = 64, int xTile = 0, int yTile = 0);
    static GameObject* CreateObject(std::string name, const char *textureSheet, int width = 64, int height = 64, int xTile = 0, int yTile = 0, std::string message = "");
    static void ChangeObjectLocals(int oldLocalX, int oldLocalY, int newLocalX, int newLocalY);
    static GameObject* getObjectByLocals(int localX, int LocalY);
    static void DeleteObjectFromLocals(int LocalX, int LocalY);
    static void DestroyObject(GameObject* object);
    static void Update();
    static void Render();

    static GameObject* goA_gameObjectsByLocals[12][20];
    static std::vector<GameObject*> goV_gameObjectsGeneral;


};


#endif //CLION_DEBUG_LOG_TXT_OBJECTMANAGER_H
