#include "UIBar.h"

UIBar::UIBar(int x, int y, int width, int height)
: x(x), y(y), width(width), height(height) {}


void UIBar::render(SDL_Renderer* renderer) const {
    SDL_Rect barRect = {getX(), getY(), getWidth(), getHeight()};
    SDL_SetRenderDrawColor(renderer, 72, 73, 75, 255);
    SDL_RenderFillRect(renderer, &barRect);
}

int UIBar::getX() const { return x; }
int UIBar::getY() const { return y; }
int UIBar::getWidth() const { return width; }
int UIBar::getHeight() const { return height; }