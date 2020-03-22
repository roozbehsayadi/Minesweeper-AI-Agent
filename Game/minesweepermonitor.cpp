
#include "minesweepermonitor.h"

const unsigned char MinesweeperMonitor::backgroundColor[] = { 232, 231, 230 };

MinesweeperMonitor::MinesweeperMonitor( int xCount, int yCount ) {

	if ( (double) WINDOW_WIDTH / xCount > (double) WINDOW_HEIGHT / yCount ) 
		this->cellWidth = WINDOW_HEIGHT / yCount;
	else this->cellWidth = WINDOW_WIDTH / xCount; 

	this->gridWidth = cellWidth * xCount;
	this->gridHeight = cellWidth * yCount; 

	this->initGraphicStuff();

	this->loadSurfaces();
	
}

void MinesweeperMonitor::showOnScreen( DisplayCell **displayGrid, int xCount, int yCount ) {

	SDL_FillRect( this->screenSurface, NULL, SDL_MapRGB( this->screenSurface->format, backgroundColor[0], backgroundColor[1], backgroundColor[2] ) );

	SDL_Rect initialRect;
	initialRect.x = (screenSurface->w - this->gridWidth) / 2;
	initialRect.y = (screenSurface->h - this->gridHeight) / 2;
	initialRect.w = this->cellWidth;
	initialRect.h = this->cellWidth;
	for ( int i = 0; i < xCount; i++ ) {
		for ( int j = 0; j < yCount; j++ ) {
			SDL_Rect currentRect;
			currentRect.x = initialRect.x + i*cellWidth;
			currentRect.y = initialRect.y + j*cellWidth;
			currentRect.w = currentRect.h = cellWidth;
			// std::cout << currentRect.x << ' ' << currentRect.y << ' ' << currentRect.w << ' ' << currentRect.h << std::endl;
			SDL_BlitScaled( this->undiscovered, NULL, this->screenSurface, &currentRect );
		}
	}
	SDL_UpdateWindowSurface( this->window );

}

void MinesweeperMonitor::loadSurfaces() {

	this->undiscovered = SDLHandler::loadIMGOptimized( "assets/undiscovered_cell.png", screenSurface ); 
	this->clicked = SDLHandler::loadIMGOptimized( "assets/box_clicked.png", screenSurface );
	this->hovered = SDLHandler::loadIMGOptimized( "assets/hovered_cell.png", screenSurface );
	this->question = SDLHandler::loadIMGOptimized( "assets/question.png", screenSurface );
	this->flag = SDLHandler::loadIMGOptimized( "assets/flag.png", screenSurface );
	this->flag_hovered = SDLHandler::loadIMGOptimized( "assets/flag_hovered.png", screenSurface );
	this->flag_red = SDLHandler::loadIMGOptimized( "assets/flag_red.png", screenSurface );
	this->bomb_safe = SDLHandler::loadIMGOptimized( "assets/bomb_safe.png", screenSurface );
	this->bomb_exploded = SDLHandler::loadIMGOptimized( "assets/bomb_exploded.png", screenSurface );

	for ( int i = 0; i < 10; i++ ) {
		std::ostringstream ss;
		ss << "assets/discovered_" << i << ".png";
		this->discovereds[i] = SDLHandler::loadIMGOptimized( ss.str().c_str(), screenSurface );
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