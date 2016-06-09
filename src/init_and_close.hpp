#include "SDL.h"

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
	    gScreenSurface = SDL_GetWindowSurface( gWindow );
	}
    }

    return success;
}

void close()
{
    SDL_DestroyWindow( gWindow );
    SDL_Quit();
}
