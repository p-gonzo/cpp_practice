//Using SDL and standard IO
#include<SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

const int SCREEN_WIDTH {640};
const int SCREEN_HEIGHT {480};

int main( int argc, char* args[] )
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL; //The surface contained by the window

    // Attempt to init SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout <<  "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Attempt to create window object
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    screenSurface = SDL_GetWindowSurface( window );
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0x00, 0xFF ) );
    SDL_UpdateWindowSurface( window );
    SDL_Delay( 2000 );

    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}