#ifndef SHEET_HPP
#define SHEET_HPP

#include "SDL.h"
#include "SDL_image.h"
#include "tile.hpp"
#include <string>
#include <vector>

class Sheet
{
public:
    SDL_Surface* load_surface( std::string path );
    void load_image( std::string path  );
    void load_texture( std::string path );
    void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dst, SDL_Rect* clip = nullptr );
    SDL_Surface* getSheet( int index );
    Sheet();
    ~Sheet();
private:
    SDL_Surface* SpriteSheet;
    std::vector<Tile*> SheetVector;
    int tiles;
    int selected;
};

#endif
