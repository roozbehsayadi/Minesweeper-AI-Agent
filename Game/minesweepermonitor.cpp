
#include "minesweepermonitor.h"

const unsigned char MinesweeperMonitor::backgroundColor[] = { 242, 241, 240 };

MinesweeperMonitor::MinesweeperMonitor( int xCount, int yCount ) {

	if ( (double) WINDOW_WIDTH / xCount > (double) WINDOW_HEIGHT / yCount ) 
		cellWidth = WINDOW_HEIGHT / yCount;
	else cellWidth = WINDOW_WIDTH / xCount; 

	this->initGraphicStuff();

	this->loadSurfaces();
	
}

void MinesweeperMonitor::showOnScreen( DisplayCell **displayGrid ) {
	
}

void MinesweeperMonitor::loadSurfaces() {

	this->undiscovered = SDLHandler::loadIMG( "assets/undiscovered_cell.png" ); 
	this->clicked = SDLHandler::loadIMG( "assets/box_clicked.png" );
	this->hovered = SDLHandler::loadIMG( "assets/hovered_cell.png" );
	this->question = SDLHandler::loadIMG( "assets/question.png" );
	this->flag = SDLHandler::loadIMG( "assets/flag.png" );
	this->flag_hovered = SDLHandler::loadIMG( "assets/flag_hovered.png" );
	this->flag_red = SDLHandler::loadIMG( "assets/flag_red.png" );
	this->bomb_safe = SDLHandler::loadIMG( "assets/bomb_safe.png" );
	this->bomb_exploded = SDLHandler::loadIMG( "assets/bombx_exploded.png" );

	for ( int i = 0; i < 10; i++ ) {
		std::ostringstream ss;
		ss << "assets/discovered_" << i << ".png";
		this->discovereds[i] = SDLHandler::loadIMG( ss.str().c_str() );
	}

}

void MinesweeperMonitor::initGraphicStuff() {

	SDLHandler::initSDL( SDL_INIT_EVERYTHING );
	SDLHandler::initIMG( IMG_INIT_PNG );

	this->window = SDLHandler::initWindow( "Minesweeper", WINDOW_WIDTH, WINDOW_HEIGHT );
	screenSurface = SDL_GetWindowSurface( this->window );

}

MinesweeperMonitor::~MinesweeperMonitor() {

	SDL_FreeSurface( this->undiscovered );
	SDL_FreeSurface( this->hovered );
	SDL_FreeSurface( this->question );
	SDL_FreeSurface( this->flag );
	SDL_FreeSurface( this->flag_hovered );
	SDL_FreeSurface( this->flag_red );
	SDL_FreeSurface( this->bomb_safe );
	SDL_FreeSurface( this->bomb_exploded );
	for ( int i = 0; i < 10; i++ ) 
	    SDL_FreeSurface( discovereds[i] );

	SDL_DestroyWindow( this->window );

	SDL_Quit();

}