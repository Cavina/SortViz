#ifndef UIBAR_H
#define UIBAR_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class UIBar {

public:
    UIBar(int x, int y, int width, int height);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    void render(SDL_Renderer* renderer) const;

protected:
    int x, y, width, height;
};



#endif
