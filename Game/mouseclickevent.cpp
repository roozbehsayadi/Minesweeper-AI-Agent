
#include "mouseclickevent.h"

MouseClickEvent::MouseClickEvent( Minesweeper *minesweeper, std::pair<int, int> cor, ClickType clickType ) {
	this->cor = cor;
	this->clickType = clickType; 
	this->minesweeper = minesweeper;
} 

void MouseClickEvent::handleEvent() { 

	if ( this->minesweeper->lost )
		return; 

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
			this->revealCell( cor.first, cor.second );

}

void MouseClickEvent::revealCell( int x, int y ) {

	// int x = cor.first, y = cor.second; 
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
		int adjacentMines = this->adjacentMinesCount( x, y ); 
		minesweeper->displayGrid[y][x] = new DisplayCellNumber( CellType::NUMBER, adjacentMines );
		if ( adjacentMines == 0 ) 
			this->DFS( x, y );
	}

}

void MouseClickEvent::DFS( int x, int y ) {

	std::vector<std::pair<int, int>> adjacents = this->adjacentCors( x, y );
	
	for ( auto cellCor : adjacents ) {
		int currentX = cellCor.first, currentY = cellCor.second; 
		if ( minesweeper->displayGrid[currentY][currentX]->getCellType() == CellType::UNDISCOVERED ) {
			if ( !this->minesweeper->hasMine[currentY][currentX] ) {
				
				delete this->minesweeper->displayGrid[currentY][currentX];
				this->minesweeper->displayGrid[currentY][currentX] = new DisplayCellNumber( CellType::NUMBER, this->adjacentMinesCount( currentX, currentY ) );
				if ( minesweeper->displayGrid[currentY][currentX]->getNumber() == 0 )
					this->DFS( currentX, currentY );
			}
		}
	}

}

std::vector<std::pair<int, int>> MouseClickEvent::adjacentCors( int x, int y ) const {

	std::vector<std::pair<int, int>> returnValue;
	for ( int i = -1; i <= 1; i++ )
		for ( int j = -1; j <= 1; j++ ) {
			if ( i == 0 && j == 0 )
				continue;
			int currentX = x + i, currentY = y + j;
			if ( currentX < 0 || currentX >= minesweeper->width || currentY < 0 || currentY >= minesweeper->height )
				continue;
			returnValue.push_back( std::make_pair( currentX, currentY ) );
		}
	
	return returnValue; 

}

int MouseClickEvent::adjacentMinesCount( int x, int y ) const {
	int returnValue = 0;
	for ( int i = -1; i <= 1; i++ )
		for ( int j = -1; j <= 1; j++ ) {
			if ( i == 0 && j == 0 )
				continue;
			int currentX = x + i, currentY = y + j;
			if ( currentX < 0 || currentX >= minesweeper->width || currentY < 0 || currentY >= minesweeper->height )
					continue;
			if ( minesweeper->hasMine[currentY][currentX] )
				returnValue++; 
		}
	return returnValue; 
}
