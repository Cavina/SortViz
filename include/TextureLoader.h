// TextureLoader.h
#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SDL2/SDL.h>

class TextureLoader {
public:
    static SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer);
};

#endif // TEXTURELOADER_H
