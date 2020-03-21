
#ifndef __MINESWEEPERMONITOR_H
#define __MINESWEEPERMONITOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

class MinesweeperMonitor {

    private:

        SDL_Surface *undiscovered, *clicked, *hovered, *question, *flag, *flag_hovered, *flag_red, *bomb_safe, *bomb_exploded;
        SDL_Surface *discovereds[9];

        const static int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
        const static unsigned char backgroundColor[];

        int cellWidth; 

        SDL_Surface *screen; 

    public:

        MinesweeperMonitor( int, int );
        ~MinesweeperMonitor();

};

#endif
