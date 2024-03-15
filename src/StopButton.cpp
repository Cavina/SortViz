// StopButton.cpp
#include "StopButton.h"

StopButton::StopButton(int x, int y, int width, int height, SDL_Texture* texture)
    : Button(x, y, width, height), texture(texture) {}

StopButton::~StopButton() {
    // Release resources, e.g., SDL_Texture
    SDL_DestroyTexture(texture);
}

void StopButton::onClick() {
    // Handle stop button click
    // Add your code here
}

void StopButton::render(SDL_Renderer* renderer) const {
    SDL_Rect destRect = {getX(), getY(), getWidth(), getHeight()};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}
