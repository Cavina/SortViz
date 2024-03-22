// Application.cpp

#include <iostream>
#include "Application.h"
#include "TextureLoader.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BAR_WIDTH 7
bool complete = false;
Application::Application()
    : window("SortViz", SCREEN_WIDTH, SCREEN_HEIGHT) {

    }


Application::~Application() {
    // Cleanup resources if needed
}


void Application::run() {
    bool quit = false;
    SDL_Event event;

    std::vector<int> data = createDataVector(114);

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                complete = false;
            } else if(event.type == SDL_KEYDOWN) {
                switch(event.key.keysym.sym) {
                    case(SDLK_q):
                        quit = true;
                        complete = false;
                        break;
                    case(SDLK_0):
                        data = createDataVector(114);
                        complete = false;
                        break;
                    case(SDLK_1):
                        if (complete) {
                            window.clear();
                            data = createDataVector(114);
                        }
                        complete = false;
                        bubbleSort(data);
                        complete = true;
                        break;
                }
            }
        }
        // Clear the screen
        window.clear();
        if (complete) {
            renderDataVisualizations(data);
        }

        window.present();
    }
}

void Application::selectAndRenderBar(int i, const std::vector<int> &data, SDL_Color color) {
        SDL_Rect rect = {i*BAR_WIDTH, SCREEN_HEIGHT, BAR_WIDTH, -data[i]};
        SDL_SetRenderDrawColor(window.getRenderer(), color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(window.getRenderer(), &rect); 
}

// Function to load a texture from an image file
SDL_Texture* Application::loadTexture(const char* filePath, SDL_Renderer* renderer) {
    return TextureLoader::loadTexture(filePath, renderer);
}

std::vector<int> Application::createDataVector(const int &size) {
    std::vector<int> vector(size);
    for(int i = 0; i < size; i++){
        vector[i] = (rand() % SCREEN_HEIGHT);
    }
    return vector;
}

void Application::renderDataVisualizations(std::vector<int> &data)
{
    auto renderer = window.getRenderer();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    for(unsigned int i = 0; i < data.size(); ++i){
        SDL_PumpEvents();
        SDL_Rect rect = {i*BAR_WIDTH, SCREEN_HEIGHT, BAR_WIDTH, -data[i]};
        SDL_SetRenderDrawColor(renderer, 100,180,100,0);
        SDL_RenderDrawRect(renderer, &rect);

    }
}

void Application::visualize(const int &firstIndex, const int &secondIndex, const int &pivotIndex, const std::vector<int> &data) {
    auto renderer = window.getRenderer();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    int j = 0;
    for (unsigned int i = 0; i < data.size(); ++i) {
        SDL_PumpEvents();

        SDL_Rect rect = {i * BAR_WIDTH, SCREEN_HEIGHT, BAR_WIDTH, -data[j]};
        if (complete) {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderDrawRect(renderer, &rect);
        } else if (j == firstIndex || j == secondIndex) {
            SDL_SetRenderDrawColor(renderer, 100, 180, 100, 0);
            SDL_RenderFillRect(renderer, &rect);
        } else if (j == pivotIndex) {
            SDL_SetRenderDrawColor(renderer, 165, 105, 189, 0);
            SDL_RenderFillRect(renderer, &rect);
        } else {
            SDL_SetRenderDrawColor(renderer, 170, 183, 184, 0);
            SDL_RenderDrawRect(renderer, &rect);
        }
        j++;
    }
    SDL_RenderPresent(renderer);
}


void Application::bubbleSort(std::vector<int> &data)
{
    int n = data.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            // Highlight elements being compared
            visualize(j+1, j, n-i, data);

            if (data[j] > data[j+1])
            {
                // Swap the elements
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }

            // Render after swapping
            visualize(j+1, j, n-i, data);
        }
    }
    // Mark sorting as complete
    complete = true;
    // Render final state
    visualize(-1, -1, -1, data);
}