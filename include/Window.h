// Window.h
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    SDL_Renderer* getRenderer() const;
    void clear() const;
    void present() const;

private:
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer {nullptr };
};

#endif // WINDOW_H
