cmake_minimum_required(VERSION 3.26)
project(sacred_host)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "C:/Dev/newSDL2filesforTM/SDL2-2.28.5/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SDL2_IMAGE_PATH "C:/Dev/newSDL2filesforTM/SDL2_image-2.8.2/x86_64-w64-mingw32")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(sacred_host main.cpp
        Game.cpp
        Game.h
        TextureManager.cpp
        TextureManager.h
        GameObject.cpp
        GameObject.h
        Map.cpp
        Map.h
        CharacterGO.cpp
        CharacterGO.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})