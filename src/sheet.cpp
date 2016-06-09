#include "sheet.hpp"
#include <ctype.h>
#include <cmath>
#include <cassert>

Sheet::Sheet()
    :tiles()
{
}

void Sheet::load_image( std::string path )
{
    // SpriteSheet = SDL_LoadBMP( path.c_str() );
    Tile* tile = new Tile;
    tile->image = SDL_LoadBMP( path.c_str() );

    //assure that the size is a power of 2
    // assert( isdigit( log2( tile->image->w ) ) );
    //assure tile is square
    assert( tile->image->w == tile->image->h );

    //16 is the default, so if the image is larger than that, it needs to be
    //fragmented
    if( tile->image->w > 16 )
    {
	int w = tile->image->w;
	// (size/default)^2 creates the correct amount of pieces
	// a 32x32 tile requires 4 pieces, for example
	// 32/16 = 2, 2*2 = 4
	tile->pieces = (w/16)*(w/16);
	std::vector<Tile*> TilePieces;
	for( int i = 0; i < tile->pieces; i++ )
	{
	    SDL_Rect frag;
	    frag.w = 16;
	    frag.h = 16;
	    frag.x = tile->image->w * i;
	    frag.y = tile->image->h * i;

	    //TODO: create a surface from this rectangle and add it to the TP vector
	    tiles += tile->pieces;
	}
    }
    else
    {
	SheetVector.push_back( tile );
	++tiles;
    }
}

void Sheet::apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dst, SDL_Rect* clip )
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( src, clip, dst, &offset );
    
}

Sheet::~Sheet()
{
    // free all surfaces, and then delete the dynamically allocated tiles themselves
    for( int i = 0; i < tiles; ++i )
    {
	SDL_FreeSurface( SheetVector[i]->image );
	delete SheetVector[i];
    }
}

SDL_Surface* Sheet::getSheet( int index  )
{
    return SheetVector[index]->image;
}
