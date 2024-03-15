// Application.cpp

#include <iostream>
#include "Application.h"
#include "TextureLoader.h"

Application::Application()
    : window("SDL Buttons Example", 800, 600),
      stopButton(100, 100, 48, 48, loadTexture("src/button.png", window.getRenderer())),
      playButton(50, 50, 48, 48, loadTexture("src/buttons.png", window.getRenderer())),
      Bar(0, 0, 800, 37),
      triangle( {300,200}, {300,400}, {200, 300}) {
    // Load textures for other buttons if needed

}

Application::~Application() {
    // Cleanup resources if needed
}

//Polls events, checking for quit or button input
//Afterwards, it renders all the buttons 
void Application::run() {
    bool quit = false;
    SDL_Event event;

    std::vector<int> data = createData(130);

    std::cout << data.size() << std::endl;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

            // Handle events for buttons
            stopButton.handleEvent(event);
            playButton.handleEvent(event);
            // Handle events for other buttons if created
        }

        // Clear the screen
        window.clear();

    

        for(int i = 0; i <= data.size(); ++i){
            SDL_Rect rect = {i*7, 600, 7, -data[i]};

         
            SDL_SetRenderDrawColor(window.getRenderer(), 100,180,100,0);
            SDL_RenderFillRect(window.getRenderer(), &rect);
        }
        
        //4th param is Y value. negative goes up.

        // SDL_Rect rect = {5, 599, 7, 10};
        // SDL_Rect recttwo = {12, 599, 7, -10};
        // SDL_SetRenderDrawColor(window.getRenderer(), 7,215,230,0);
        // SDL_RenderFillRect(window.getRenderer(), &rect);
        // SDL_RenderFillRect(window.getRenderer(), &recttwo);
        // Update the screen
        window.present();
    }
}

// Function to load a texture from an image file
SDL_Texture* Application::loadTexture(const char* filePath, SDL_Renderer* renderer) {
    return TextureLoader::loadTexture(filePath, renderer);
}

std::vector<int> Application::createData(const int size) {
    std::vector<int> vector(size);
    for(int i = 0; i < size; i++){
        vector[i] = (rand() % 250);
    }

    return vector;
}