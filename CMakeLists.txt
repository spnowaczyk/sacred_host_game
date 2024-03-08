cmake_minimum_required(VERSION 3.26)
project(sacred_host)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "${CMAKE_SOURCE_DIR}/SDL2_libs/SDL2-2.28.5/x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SDL2_IMAGE_PATH "${CMAKE_SOURCE_DIR}/SDL2_libs/SDL2_image-2.8.2/x86_64-w64-mingw32")
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

set(SDL2_TTF_PATH "${CMAKE_SOURCE_DIR}/SDL2_libs/SDL2_ttf-2.22.0/x86_64-w64-mingw32")
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

set(SDL2_MIXER_PATH "${CMAKE_SOURCE_DIR}/SDL2_libs/SDL2_mixer-2.8.0/x86_64-w64-mingw32")
find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_MIXER_INCLUDE_DIR})

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
        CharacterGO.h
        TextBox.cpp
        TextBox.h
        MouseController.cpp
        MouseController.h
        SFX.cpp
        SFX.h
        VisualEffect.cpp
        VisualEffect.h
        Pinpoint.cpp
        Pinpoint.h
        TextManager.cpp
        TextManager.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})