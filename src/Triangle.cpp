#include "Triangle.h"

Triangle::Triangle(const std::tuple<int, int>& v1, const std::tuple<int, int>& v2, 
const std::tuple<int, int>& v3)
: points {v1, v2, v3 }  {}

void Triangle::render(SDL_Renderer* renderer) const {
    
    SDL_Point sdlpoints[4] = {
        {std::get<0>(points[0]), std::get<1>(points[0])},
        {std::get<0>(points[1]), std::get<1>(points[1])},
        {std::get<0>(points[2]), std::get<1>(points[2])},
        {std::get<0>(points[0]), std::get<1>(points[0])}
    };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLines(renderer, sdlpoints, 4);
}