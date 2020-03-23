
#ifndef __MINESWEEPERMONITOR_H
#define __MINESWEEPERMONITOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <math.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


#include "displaycell.h"
#include "mouseclickevent.h"

#include "SDLHandler.h"


class MinesweeperMonitor {

    private:

        void initGraphicStuff();
        void loadSurfaces();

        void draw( DisplayCell**, int, int );

        SDL_Surface *getSurfaceByCellType( DisplayCell ) const;

        SDL_Surface *undiscovered, *clicked, *hovered, *question, *flag, *flag_hovered, *flag_red, *bomb_safe, *bomb_exploded;
        SDL_Surface *discovereds[10];

        const static int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
        const static unsigned char backgroundColor[];

        int cellWidth, gridWidth, gridHeight; 

        SDL_Window *window = NULL; 
        SDL_Surface *screenSurface = NULL; 

    public:

        MinesweeperMonitor( int, int );
        ~MinesweeperMonitor();

        MouseClickEvent showOnScreenAndReturnClick( DisplayCell**, int, int );

};

#endif
