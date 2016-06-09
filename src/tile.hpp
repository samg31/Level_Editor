#include "SDL.h"

class Tile
{
public:
    Tile();
    int getWidth() const;
    int Width;
    SDL_Surface* image;

    // tiles larger than default split into pieces
    // thus loading a 32x32 into a 16x16 default would
    // have 4 pieces.
    int pieces;
};
