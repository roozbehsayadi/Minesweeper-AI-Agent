
#include "minesweeper.h"

Minesweeper::Minesweeper( int width, int height, int minesCount ) : width( width ), height( height ), minesCount( minesCount ) {

    if ( minesCount >= width * height )
        throw "Not enought grid cells for this amount of mines.";

    this->grid = new bool*[ height ];
    for ( int i = 0; i < height; i++ ){
        grid[i] = new bool[ width ];
        for ( int j = 0; j < width; j++ )
            grid[i][j] = false;
    }

    this->initializeRandomly();

}

void Minesweeper::initializeRandomly() {

    std::pair<int, int> *allCors = new std::pair<int, int>[width * height];
    for ( int i = 0; i < width; i++ )
        for ( int j = 0; j < height; j++ ) { 
            allCors[j*width + i] = std::make_pair( i, j );
        }

    std::random_shuffle( allCors, allCors + width * height );

    for ( int i = 0; i < minesCount; i++ ) {
        auto current = allCors[i];
        grid[current.second][current.first] = true;
    }

    delete[] allCors;

}

std::string Minesweeper::toString() const { 
    std::string returnValue = "";
    for ( int i = 0; i < height; i++ ) {
        for ( int j = 0; j < width; j++ ) 
            returnValue.append( std::to_string(this->grid[i][j] ) );
        returnValue.append("\n");
    }
    return returnValue;
}

void Minesweeper::print() const {
    std::cout << this->toString();
}
