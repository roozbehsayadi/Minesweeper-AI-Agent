
#include "minesweeper.h"

Minesweeper::Minesweeper( int width, int height, int minesCount ) : width( width ), height( height ), minesCount( minesCount ) {

	if ( minesCount >= width * height )
		throw "Not enought grid cells for this amount of mines.";

	this->hasMine = new bool*[ height ];
	for ( int i = 0; i < height; i++ ){
		hasMine[i] = new bool[ width ];
		for ( int j = 0; j < width; j++ )
			hasMine[i][j] = false;
	}

	this->displayGrid = new DisplayCell**[ height ];
	for ( int i = 0; i < height; i++ ) {
		displayGrid[i] = new DisplayCell*[ width ];
		for ( int j = 0; j < width; j++ )
			displayGrid[i][j] = new DisplayCell( CellType::UNDISCOVERED );
	}

	monitor = new MinesweeperMonitor( width, height );

}

Minesweeper::~Minesweeper() {
	delete[] hasMine; 
	delete[] displayGrid;
	delete monitor; 
}

void Minesweeper::startGame() {

	bool lost = false, quit = false; 
	Event *event = monitor->showOnScreenAndReturnEvent( this->hasMine, displayGrid, width, height, &lost, &quit );
	event->handleEvent();
	monitor->draw( displayGrid, width, height );
	delete event;

	while ( !quit ) {
		event = monitor->showOnScreenAndReturnEvent( this->hasMine, displayGrid, width, height, &lost, &quit );
		event->handleEvent();
		monitor->draw( displayGrid, width, height );
		// ...
		delete event; 
	}

}

void Minesweeper::initializeRandomly( std::pair<int, int> clickPosition ) {

	std::vector<std::pair<int, int>> allCors; 
	for ( int i = 0; i < width; i++ )
		for ( int j = 0; j < height; j++ ) { 
			if ( abs(i-clickPosition.first) <= SAFE_SPACE_RADIUS_FOR_INITIALIZATION && abs(j-clickPosition.second) <= SAFE_SPACE_RADIUS_FOR_INITIALIZATION )
				continue;
			std::cout << "HERE!" << std::endl;
			allCors.push_back(std::make_pair( i, j ) );
		}

	std::random_shuffle( allCors.begin(), allCors.end() );

	for ( int i = 0; i < minesCount; i++ ) {
		auto current = allCors[i];
		hasMine[current.second][current.first] = true;
	}

}

std::string Minesweeper::toString() const { 
	std::string returnValue = "";
	for ( int i = 0; i < height; i++ ) {
		for ( int j = 0; j < width; j++ ) 
			returnValue.append( std::to_string(this->hasMine[i][j] ) );
		returnValue.append("\n");
	}
	return returnValue;
}

void Minesweeper::print() const {
	std::cout << this->toString();
}
