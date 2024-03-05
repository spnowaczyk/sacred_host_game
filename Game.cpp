//
// Created by Admin on 20.02.2024.
//

#include "Game.h"

int i_cnt = 0;
SDL_Renderer* Game::sdlRen_renderer = nullptr;
CharacterGO* go_player;
Map* m_map;

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

        this->sdlWin_window = SDL_CreateWindow(title, xpos, ypos, width, height, i_flags);
        if (sdlWin_window) {
            std::cout << "Window created properly" << std::endl;
        }
        this->sdlRen_renderer = SDL_CreateRenderer(sdlWin_window, -1, 0);
        if (sdlRen_renderer) {
            SDL_SetRenderDrawColor(sdlRen_renderer, 255, 255, 255, 255);
            std::cout << "Renderer created properly" << std::endl;
        }
        if(sdlWin_window && sdlRen_renderer) std::cout << "All systems nominal" << std::endl;

        b_running = true;
    }else{
        b_running = false;
    }
    go_player = new CharacterGO("Seth", "../assets/Seth2.png");
    m_map = new Map();
    m_map->RandomMap();
}

void Game::HandleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            b_running = false;
            break;
        default:
            break;
    }
}

void Game::Update() {
    i_cnt++;
    go_player->Update();
}

void Game::Render() {
    SDL_RenderClear(sdlRen_renderer);
    m_map->RenderMap();
    go_player->Render();
    SDL_RenderPresent(sdlRen_renderer);
}

void Game::Clear() {
    SDL_DestroyWindow(sdlWin_window);
    SDL_DestroyRenderer(sdlRen_renderer);
    SDL_Quit();
    std::cout << "game quit" << std::endl;
}
