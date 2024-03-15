//
// Created by Admin on 29.02.2024.
//

#ifndef SACRED_HOST_GAMEOBJECT_H
#define SACRED_HOST_GAMEOBJECT_H

#include "SDL.h"
#include "string"

class ObjectManager;

class GameObject {
public:
    GameObject(std::string name, const char* textureSheet, int width, int height, int xTile, int yTile,  ObjectManager* manager, std::string message);
    GameObject(std::string name, const char* textureSheet, int width, int height, int xTile, int yTile,  ObjectManager* manager);
    virtual ~GameObject();

    virtual void Update();
    void Render();

    virtual void Interact();

    bool IsMarkedToDeath();
    void MarkToDeath();

    int getIXTile() const;
    int getIYTile() const;

protected:
    std::string s_name;
    std::string s_message;

    int i_xTile;
    int i_yTile;

    int i_desXTile;
    int i_desYTile;

    int i_enqueuedXTile;
    int i_enqueuedYTile;

    int i_Width;
    int i_Height;

    bool b_markedToDeath;

    SDL_Texture* sdlTex_objTexture;
    SDL_Rect sdlRect_srcRect, sdlRect_dstRect;

    ObjectManager* om_manager;
};


#endif //SACRED_HOST_GAMEOBJECT_H
