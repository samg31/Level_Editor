#include "SDL.h"
#include "sheet.hpp"
#include "globals.hpp"
#include "init_and_close.hpp"

int main()
{
    if( init() )
    {
	Sheet sheet;
	sheet.load_image( "../img/tile.bmp"  );
	SDL_BlitSurface( sheet.getSheet( 0 ), nullptr, gScreenSurface, nullptr );
	SDL_UpdateWindowSurface( gWindow );
	SDL_Delay( 2000 );
    }
    close();
    return 0;
}
