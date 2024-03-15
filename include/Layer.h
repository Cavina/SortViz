#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Window.h"
#include "EventReceiver.h"

class Layer {
    public:
        bool HandleEvent(const SDL_Event* Event);
        void SubscribeToEvents(EventReceiver* Receiver);

    private:
    std::vector<EventReceiver*> Subscribers;

};