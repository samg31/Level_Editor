#include "SDL.h"
#include "sheet.hpp"
#include "globals.hpp"
#include "init_and_close.hpp"
#include "mouse_logic.hpp"
#include <iostream>
#include <cmath>

int main()
{
    if( init() )
    {
	LButton L;
	bool quit = false;
	SDL_Event e;

	SDL_Rect BlitRect;
	while( !quit )
	{
	    while( SDL_PollEvent( &e ) )
	    {
		bool blit = false;
		if( e.type == SDL_QUIT )
		    quit = true;
		else
		{
		    int x, y;
		    blit = L.handleEvent( &e, x, y );
		    if( blit )
		    {
			BlitRect.x = x - (x % 16);
			BlitRect.y = y - (y % 16);
			BlitRect.w = 16;
			BlitRect.h = 16;
			std::cout << "click at: " << BlitRect.x << ", " << BlitRect.y << "\n";
			
		    }
		    
		}
		Sheet sheet;
		sheet.load_image( "../img/tile.bmp"  );
		if( blit )
		{
		    SDL_BlitSurface( sheet.getSheet( 0 ), nullptr, gScreenSurface, &BlitRect );
		}
		SDL_UpdateWindowSurface( gWindow );
	    }
	}
    }
    close();
    return 0;
}
