//
// Created by Admin on 20.02.2024.
//

#include "Game.h"
#include "string"

bool b_displayColliders = false;
bool b_SizeChangedThisCycle = false;

int i_cnt = 0;
int Game::i_cursorCoordinatesX, Game::i_cursorCoordinatesY;
bool Game::b_selectButton;

int Game::i_tileSize = 64;
int Game::i_srcTileSize = 64;
SDL_Renderer* Game::sdlRen_renderer = nullptr;
SDL_Event Game::sdlEvent_event;
ObjectManager* objMan_objectManager;
SFXManager* sfxMan_sfxManager;
CharacterGO* go_player;
Map* m_map;


TextBox* textBox_mouseCoords;
TextBox* textBox_debug;

int Game::i_textBoxes;
int Game::i_pinPoints;
int Game::i_visualEffects;
int Game::i_gameObjects;

Game::Game() {

}
Game::~Game() {

}

void Game::Init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int i_flags = 0;
    if(fullscreen == true) {
        i_flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
        std::cout << "SDL initialized properly" << std::endl;

        if(TTF_Init() == 0) {

            if(Mix_Init(0) == 0) {
                std::cout << "SDL TTF initialized properly" << std::endl;

                this->sdlWin_window = SDL_CreateWindow(title, xpos, ypos, width, height, i_flags);
                if (sdlWin_window) {
                    std::cout << "Window created properly" << std::endl;
                }
                this->sdlRen_renderer = SDL_CreateRenderer(sdlWin_window, -1, 0);
                if (sdlRen_renderer) {
                    SDL_SetRenderDrawColor(sdlRen_renderer, 190, 80, 0, 255);
                    std::cout << "Renderer created properly" << std::endl;
                }

                if(sdlWin_window && sdlRen_renderer) std::cout << "All systems nominal" << std::endl;

            }
        }

        b_running = true;
    }else{
        b_running = false;
    }

    Game::i_gameObjects = 0;
    Game::i_pinPoints = 0;
    Game::i_visualEffects = 0;
    Game::i_textBoxes = 0;

    m_map = new Map();
    m_map->RandomMap();
    sfxMan_sfxManager = new SFXManager();
    objMan_objectManager = new ObjectManager(sfxMan_sfxManager);
    objMan_objectManager->cl_layer->LoadColliders(m_map);

    objMan_objectManager->CreateCharacter("Seth", "../assets/Seth2.png", 1, 1, 2, 2);
    objMan_objectManager->CreateObject("Chest", "../assets/chest.png", 1, 1, 7, 7, "looks like an old, rusty chest");

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* mixMusic_music = Mix_LoadMUS("../audio/night_watch.wav");
    //Mix_Chunk* mixChunk_sound = Mix_LoadWAV()
    Mix_PlayMusic(mixMusic_music, -1);

    textBox_mouseCoords = TextManager::CreateTextBox(1000, 700, "mouse coords");
    textBox_debug = TextManager::CreateTextBox(100, 100, "debug");

}

void Game::HandleEvents() {
    SDL_PollEvent(&sdlEvent_event);
    switch (sdlEvent_event.type) {
        case SDL_QUIT:
            b_running = false;
            break;
        default:
            break;
    }
    MouseController::MousePositionQuery(&i_cursorCoordinatesX, &i_cursorCoordinatesY);
    MouseController::MouseClickQuery(&b_selectButton);

    if(Game::sdlEvent_event.type == SDL_KEYDOWN) {
        int i_prevTileSize = Game::i_tileSize;
        switch(Game::sdlEvent_event.key.keysym.sym ){
            case SDLK_z:
                if(Game::i_tileSize < 96) {
                    Game::i_tileSize += 16;
                    objMan_objectManager->Adjust(i_prevTileSize);
                    std::cout << "tile size is now equal to: " << Game::i_tileSize << std::endl;
                    b_SizeChangedThisCycle = true;
                }
                break;
            case SDLK_x:
                if(Game::i_tileSize > 32) {
                    Game::i_tileSize -= 16;
                    objMan_objectManager->Adjust(i_prevTileSize);
                    std::cout << "tile size is now equal to: " << Game::i_tileSize << std::endl;
                    b_SizeChangedThisCycle = true;
                }
                break;
            case SDLK_c:
                if(b_displayColliders) b_displayColliders = false;
                else if(!b_displayColliders) b_displayColliders = true;
                break;
            default:
                break;
        }
    }
}

void Game::Update() {
    sfxMan_sfxManager->Update();
    if(!b_SizeChangedThisCycle) objMan_objectManager->Update();
    TextManager::Update();

    TextManager::WriteMessage(textBox_mouseCoords, ("X: " + std::to_string(Game::i_cursorCoordinatesX/Game::i_tileSize) + " / Y: "
        + std::to_string(Game::i_cursorCoordinatesY/Game::i_tileSize) + " C: " + std::to_string(b_selectButton)).c_str());
    TextManager::WriteMessage(textBox_debug, "pinpoints: " + std::to_string(i_pinPoints) + "  "
                                + "visualeffects: " + std::to_string(i_visualEffects) + "  "
                                + "gameobjects: " + std::to_string(i_gameObjects) + "  "
                                + "textboxes: " + std::to_string(i_textBoxes));
    b_SizeChangedThisCycle = false;
}

void Game::Render() {
    SDL_RenderClear(sdlRen_renderer);

    m_map->RenderMap();
    objMan_objectManager->Render();
    sfxMan_sfxManager->Render();
    m_map->RenderObscuringMap();
    if(b_displayColliders) objMan_objectManager->cl_layer->Render();
    TextManager::Render();

    SDL_RenderPresent(sdlRen_renderer);
}

void Game::Clear() {

    SDL_DestroyWindow(sdlWin_window);
    SDL_DestroyRenderer(sdlRen_renderer);
    SDL_Quit();
    std::cout << "game quit" << std::endl;
}
