#ifndef UIBAR_H
#define UIBAR_H

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class UIBar {

public:
    /// @brief Constructor to draw a UI Bar
    /// @param x the x coordinate of the bar 
    /// @param y the y coordinate of the bar
    /// @param width the width of the bar
    /// @param height the height of the bar
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
