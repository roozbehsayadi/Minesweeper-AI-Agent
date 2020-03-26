
#include "mouseclickevent.h"

MouseClickEvent::MouseClickEvent( Minesweeper *minesweeper, std::pair<int, int> cor, ClickType clickType ) {
	// this->hasMine = minesweeper->hasMine;
	// this->displayGrid = minesweeper->displayGrid;
	// this->xCount = minesweeper->width;
	// this->yCount = minesweeper->height; 
	this->cor = cor;
	this->clickType = clickType; 
	// this->lost = minesweeper->lost; 
	// this->initialized = minesweeper->initialized;

	this->minesweeper = minesweeper;

} 

void MouseClickEvent::handleEvent() { 

	int x = cor.first, y = cor.second;

	if ( ! this->minesweeper->initialized )
		minesweeper->initializeRandomly( cor );

	CellType cellType = minesweeper->displayGrid[y][x]->getCellType();

	if ( clickType == ClickType::RIGHT ) {
		if ( cellType == CellType::FLAG ) 
			minesweeper->displayGrid[y][x]->setCellType( CellType::QUESTION );
		else if ( cellType == CellType::QUESTION ) 
			minesweeper->displayGrid[y][x]->setCellType( CellType::UNDISCOVERED );
		else if ( cellType == CellType::UNDISCOVERED )
			minesweeper->displayGrid[y][x]->setCellType( CellType::FLAG );
	}
	else if ( clickType == ClickType::LEFT ) 
		if ( cellType == CellType::UNDISCOVERED || cellType == CellType::QUESTION )
			this->revealCell();

}

void MouseClickEvent::revealCell() {

	int x = cor.first, y = cor.second; 
	if ( minesweeper->hasMine[y][x] ) {
		minesweeper->displayGrid[y][x]->setCellType( CellType::EXPLODED_MINE );
		for ( int i = 0; i < minesweeper->width; i++ )
			for ( int j = 0; j < minesweeper->height; j++ ) 
				if ( minesweeper->displayGrid[j][i]->getCellType() == CellType::FLAG && !minesweeper->hasMine[j][i] )
					minesweeper->displayGrid[j][i]->setCellType( CellType::RED_FLAG );
		minesweeper->lost = true; 
	}
	else {
		delete (minesweeper->displayGrid[y][x]);
		minesweeper->displayGrid[y][x] = new DisplayCellNumber( CellType::NUMBER, this->adjacentMines() );
	}
		// I calculate the number here, instead of somewhere that makes more sense. It is only temporary I will fix this later lol.

}

int MouseClickEvent::adjacentMines() const {
	int returnValue = 0;
	for ( int i = -1; i <= 1; i++ )
		for ( int j = -1; j <= 1; j++ ) {
			if ( i == 0 && j == 0 )
				continue;
			int currentX = cor.first + i, currentY = cor.second + j;
			if ( currentX < 0 || currentX >= minesweeper->width || currentY < 0 || currentY >= minesweeper->height )
					continue;
			if ( minesweeper->hasMine[currentY][currentX] )
				returnValue++; 
		}
	return returnValue; 
}
