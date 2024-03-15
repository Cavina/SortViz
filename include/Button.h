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
    //Accepts an x, y coordinates and width, height as ints.
    Button(int x, int y, int width, int height);
    virtual ~Button(); // Add a virtual destructor for base class

    //Virtual for onClick
    virtual void onClick() = 0;

    //When mouse is hovering over a location
    bool isMouseOver(int mouseX, int mouseY) const;
    //Event handler
    void handleEvent(SDL_Event& event);
    // return X 
    int getX() const;
    //return Y
    int getY() const;
    //returns Width
    int getWidth() const;
    //returns Height
    int getHeight() const;

    /// @brief Load a texture
    /// @param filePath accepts a path to a texture file
    /// @param renderer the SDL Renderer
    /// @return a pointer to the SDL_Texture object
    SDL_Texture *loadTexture(const char *filePath, SDL_Renderer *renderer);

    /// @brief Abstract to render the object to the screen
    /// @param renderer A pointer to the SDL_Renderer object.
    virtual void render(SDL_Renderer* renderer) const = 0;

protected:
    int x, y, width, height;
};

#endif // BUTTON_H
