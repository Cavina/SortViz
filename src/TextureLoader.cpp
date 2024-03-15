// TextureLoader.cpp
#include "TextureLoader.h"
#include <SDL2_image/SDL_image.h>

SDL_Texture* TextureLoader::loadTexture(const char* filePath, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filePath);
    SDL_Texture* texture = nullptr;

    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    return texture;
}
