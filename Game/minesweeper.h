
#ifndef __MINESWEEPER_H
#define __MINESWEEPER_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

class Minesweeper {

    private:
        bool **grid;
        int width, height, minesCount;

    public:
        Minesweeper( int, int, int );

        void initializeRandomly();

        std::string toString() const;
        void print() const;

};

#endif
