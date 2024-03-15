// Button.cpp
#include <SDL2_image/SDL_image.h>
#include "TextureLoader.h"
#include "Button.h"

Button::Button(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

Button::~Button() {}

bool Button::isMouseOver(int mouseX, int mouseY) const {
    return mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height;
}

void Button::handleEvent(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (isMouseOver(mouseX, mouseY)) {
            onClick();
        }
    }
}

int Button::getX() const {
    return x;
}

int Button::getY() const {
    return y;
}

int Button::getWidth() const {
    return width;
}

int Button::getHeight() const {
    return height;
}

SDL_Texture* Button::loadTexture(const char* filePath, SDL_Renderer* renderer) {
    return TextureLoader::loadTexture(filePath, renderer);
}
