
#ifndef __MINESWEEPER_H
#define __MINESWEEPER_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#include "minesweepermonitor.h"
#include "displaycell.h"
#include "mouseclickevent.h"

class Minesweeper {

    private:

		const static int SAFE_SPACE_RADIUS_FOR_INITIALIZATION = 1;

        bool **hasMine;
        DisplayCell ***displayGrid; 
        int width, height, minesCount;

        MinesweeperMonitor *monitor; 

        void initializeRandomly( std::pair<int, int> = std::make_pair(-50, -50) );


    public:
        Minesweeper( int, int, int );
        ~Minesweeper();

        std::string toString() const;   // TODO: must edit toString so it returns the shown grid, not the answers
        void print() const;

		void startGame();

};

#endif
