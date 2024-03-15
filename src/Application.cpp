// Application.cpp

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

        // Render the buttons
        triangle.render(window.getRenderer());
        Bar.render(window.getRenderer());
        //stopButton.render(window.getRenderer());
        playButton.render(window.getRenderer());
        // Render other buttons if created

        // Update the screen
        window.present();
    }
}

// Function to load a texture from an image file
SDL_Texture* Application::loadTexture(const char* filePath, SDL_Renderer* renderer) {
    return TextureLoader::loadTexture(filePath, renderer);
}
