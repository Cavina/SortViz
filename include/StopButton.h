// StopButton.h
#ifndef STOPBUTTON_H
#define STOPBUTTON_H

#include "Button.h"

class StopButton : public Button {
public:
    StopButton(int x, int y, int width, int height, SDL_Texture* texture);
    ~StopButton() override;

    void onClick() override;
    void render(SDL_Renderer* renderer) const override;

private:
    SDL_Texture* texture;
};

#endif // STOPBUTTON_H
