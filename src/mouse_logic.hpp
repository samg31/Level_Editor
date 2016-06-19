#ifndef MOUSE_LOGIC_HPP
#define MOUSE_LOGIC_HPP

#include "SDL.h"

class LButton
{
public:
    LButton();
    void setPosition( int x, int y );
    bool handleEvent( SDL_Event* e, int &x, int &y );
    void render();
private:
    SDL_Point mPosition;
};

#endif
