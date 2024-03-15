#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <tuple>
#include <SDL2/SDL.h>

class Triangle {

    public:
        Triangle(const std::tuple<int, int>& v1, const std::tuple<int, int>& v2,
        const std::tuple<int, int>& v3);

        void render(SDL_Renderer* renderer) const;

    protected:
        std::tuple<int, int> points[4];
        
};


#endif