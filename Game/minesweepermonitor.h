
#ifndef __MINESWEEPERMONITOR_H
#define __MINESWEEPERMONITOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <math.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


#include "minesweeper.h"
#include "displaycell.h"
#include "event.h"
#include "mouseclickevent.h"
#include "exitevent.h"

#include "SDLHandler.h"

class Minesweeper; 

class MinesweeperMonitor {

    private:

        void initGraphicStuff();
        void loadSurfaces();

        SDL_Surface *getSurfaceByCellType( DisplayCell* ) const;

        std::pair<int, int> getCellCorFromClick( int, int ) const; 

        SDL_Surface *undiscovered, *clicked, *hovered, *question, *flag, *flag_hovered, *flag_red, *bomb_safe, *bomb_exploded;
        SDL_Surface *discovereds[10];

        const static int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
        const static unsigned char backgroundColor[];

        int cellWidth, gridWidth, gridHeight; 

        SDL_Window *window = NULL; 
        SDL_Surface *screenSurface = NULL; 

        std::pair<int, int> boardTopLeftCor; 

    public:

        MinesweeperMonitor( int, int );
        ~MinesweeperMonitor();

        Event* showOnScreenAndReturnEvent( Minesweeper* );
        void draw( DisplayCell***, int, int );

};

#endif
