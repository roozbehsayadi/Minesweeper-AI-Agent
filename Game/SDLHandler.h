
#ifndef __SDLHANDLER_H
#define __SDLHANDLER_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SDLHandler {

    public:

        static void initSDL( int );
        static void initIMG( int );
        static SDL_Window* initWindow( std::string, int, int );

        static SDL_Surface* loadIMG( const char* );
        static SDL_Surface* loadIMGOptimized( const char*, SDL_Surface* );

};

#endif
