#ifndef INIT_AND_CLOSE_HPP
#define INIT_AND_CLOSE_HPP

#include "SDL.h"
#include "SDL_image.h"

bool init()
{
    bool success = true;

    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	success = false;
    else
    {
	gWindow = SDL_CreateWindow( "Level Editor", SDL_WINDOWPOS_UNDEFINED,
				    SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				    SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( !gWindow )
	    success = false;
	else
	{
	    int imgFlags = IMG_INIT_PNG;
	    if( !( IMG_Init( imgFlags ) & imgFlags ) )
		success = false;
	    else
	    {
		gScreenSurface = SDL_GetWindowSurface( gWindow );
	    }
	}
    }

    return success;
}

void close()
{
    SDL_DestroyWindow( gWindow );
    SDL_Quit();
}

#endif
