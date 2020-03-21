
#include "minesweepermonitor.h"

const unsigned char MinesweeperMonitor::backgroundColor[] = { 242, 241, 240 };

// SDL_Surface *const undiscovered, hovered, question, flag, flag_hovered, flag_red, bomb_safe, bomb_exploded;
// SDL_Surface *const discovereds[9];

MinesweeperMonitor::MinesweeperMonitor() {

    SDL_Init( SDL_INIT_EVERYTHING );
    screen = SDL_SetVideoMode( MinesweeperMonitor::WINDOW_WIDTH, MinesweeperMonitor::WINDOW_HEIGHT, 32, SDL_HWSURFACE );
    SDL_FillRect(screen, NULL, SDL_MapRGB( screen->format, backgroundColor[0], backgroundColor[1], backgroundColor[2]) );

    this->undiscovered = IMG_Load( "assets/undiscovered_cell.png" );
    assert( this->undiscovered != NULL );
    this->hovered = IMG_Load( "assets/hovered_cell.png" );
    assert( this->hovered != NULL );
    this->question = IMG_Load( "assets/question.png" );
    assert( this->question != NULL );
    this->flag = IMG_Load( "assets/flag.png" );
    assert( this->flag != NULL );
    this->flag_hovered = IMG_Load( "assets/flag_hovered.png" );
    assert( this->flag_hovered != NULL );
    this->flag_red = IMG_Load( "assets/flag_red.png" );
    assert( this->flag_red != NULL );
    this->bomb_safe = IMG_Load( "assets/bomb_safe.png" );
    assert( this->bomb_safe != NULL );
    this->bomb_exploded = IMG_Load( "assets/bomb_exploded.png" );
    assert( this->bomb_exploded != NULL );
    
    for ( int i = 0; i < 10; i++ ) {
        std::ostringstream ss;
        ss << "assets/discovered_" << i << ".png";
        this->discovereds[i] = IMG_Load( ss.str().c_str() );
        assert( this->discovereds[i] != NULL );
    }

    SDL_Flip( screen );
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

    SDL_Quit();

}