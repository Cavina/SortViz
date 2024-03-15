// Button.h
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>

//*****Button.h*****//
//Button is a base class to build
//other buttons with.
//The class needs to override the virtual
//method to render the button as expected.



class Button {
public:
    Button(int x, int y, int width, int height);
    virtual ~Button(); // Add a virtual destructor for base class

    virtual void onClick() = 0;

    bool isMouseOver(int mouseX, int mouseY) const;
    void handleEvent(SDL_Event& event);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    SDL_Texture *loadTexture(const char *filePath, SDL_Renderer *renderer);

    virtual void render(SDL_Renderer* renderer) const = 0;

protected:
    int x, y, width, height;
};

#endif // BUTTON_H
