// Application.h
#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "Window.h"
#include "StopButton.h"
#include "UIBar.h"
#include "Triangle.h"


//*****Application*****//
//Handles running of application.
//Declare components as private variables 
//

class Application {
public:
    //Constructor
    //Will need to create another to pass parameters possibly
    Application();
    ~Application();

    //Runs the application
    void run();

private:
    Window window;

    //Loads an SDL texture.
    //Accepts a const pointer to char for filePath
    //Accepts a pointer to the SDL_Renderer.
    //Returns a pointer to the SDL_Texture
    SDL_Texture* loadTexture(const char* filePath, SDL_Renderer* renderer);
    std::vector<int> createDataVector(const int &size);
    void renderDataVisualizations(std::vector<int> &data);
    void selectAndRenderBar(int i, const std::vector<int> &data, SDL_Color color);
    void visualize(int x, int y, int z, const std::vector<int> &data);
    void bubbleSort(std::vector<int> &data);
};

#endif // APPLICATION_H
