
#include <iostream>
#include <utility>
#include <cstdlib>
#include <time.h>

#include "minesweeper.h"

int main( int argc, char **argv ) {

	srand( time( NULL ) );

	std::pair<int, int> gridSize;
    int minesCount = 0;
    if ( argc == 1 )
        std::cin >> gridSize.first >> gridSize.second >> minesCount;
    else {
        gridSize = std::make_pair( std::stoi(argv[1]), std::stoi(argv[2]) );
        minesCount = std::stoi( argv[3] );
    }
    
	Minesweeper *minesweeper = NULL; 
	try {
		minesweeper = new Minesweeper( gridSize.first, gridSize.second, minesCount );
		// Minesweeper minesweeper( gridSize.first, gridSize.second, minesCount );
	} catch ( const std::exception& e ) {
		std::cout << "Faild to create the game with error \"" << e.what() << "\"." << std::endl;
	}

	minesweeper->print();

    return 0;

}
