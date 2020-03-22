
#include "SDLHandler.h"

void SDLHandler::initSDL( int flag ) {
    if ( SDL_Init( flag ) < 0 ) 
        throw std::string( "Could not initialize SDL due to error \"") + SDL_GetError() + "\"";
}

void SDLHandler::initIMG( int flag ) {
    if ( !( IMG_Init( flag ) & flag) )
        throw std::string( "Could not initialize IMG due to error \"") + IMG_GetError() + "\"";
}

SDL_Window* SDLHandler::initWindow( std::string caption, int width, int height ) {

    SDL_Window *window = SDL_CreateWindow( caption.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    if ( window == NULL )
        throw std::string( "Could not create window due to error \"" ) + SDL_GetError() + "\"";
        
    return window;

}

SDL_Surface* SDLHandler::loadIMG( const char *address ) {
    
    SDL_Surface *surface = IMG_Load( address );
    if ( surface == NULL ) 
        throw std::string( "Could not load image with address\"") + std::string( address ) + std::string( "\" due to error \"" ) + SDL_GetError() + "\"";
    
    return surface;

}

SDL_Surface* SDLHandler::loadIMGOptimized( const char *address, SDL_Surface *screen ) {

    SDL_Surface *surface = SDLHandler::loadIMG( address );
    surface = SDL_ConvertSurface( surface, screen->format, 0 );
    if ( surface == NULL )
        throw std::string( "Could not optimally load image with address \"" ) + std::string( address ) + std::string( "\" due to error \"" ) + SDL_GetError() + "\"";

    return surface;

}
