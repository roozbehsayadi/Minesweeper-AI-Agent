
#include "mouseclickevent.h"

MouseClickEvent::MouseClickEvent( bool **hasMine, DisplayCell ***displayGrid, int xCount, int yCount, std::pair<int, int> cor, ClickType clickType, bool *lost ) {
	this->hasMine = hasMine;
	this->displayGrid = displayGrid;
	this->xCount = xCount;
	this->yCount = yCount; 
	this->cor = cor;
	this->clickType = clickType; 
	this->lost = lost; 
} 

void MouseClickEvent::handleEvent() { 

	int x = cor.first, y = cor.second;
	CellType cellType = displayGrid[y][x]->getCellType();

	if ( clickType == ClickType::RIGHT ) {
		if ( cellType == CellType::FLAG ) 
			displayGrid[y][x]->setCellType( CellType::QUESTION );
		else if ( cellType == CellType::QUESTION ) 
			displayGrid[y][x]->setCellType( CellType::UNDISCOVERED );
		else if ( cellType == CellType::UNDISCOVERED )
			displayGrid[y][x]->setCellType( CellType::FLAG );
	}
	else if ( clickType == ClickType::LEFT ) 
		if ( cellType == CellType::UNDISCOVERED || cellType == CellType::QUESTION )
			this->revealCell();

}

void MouseClickEvent::revealCell() {

	int x = cor.first, y = cor.second; 
	if ( hasMine[y][x] ) {
		displayGrid[y][x]->setCellType( CellType::EXPLODED_MINE );
		for ( int i = 0; i < xCount; i++ )
			for ( int j = 0; j < yCount; j++ ) 
				if ( displayGrid[j][i]->getCellType() == CellType::FLAG && hasMine[j][i] )
					displayGrid[j][i]->setCellType( CellType::RED_FLAG );
		*lost = true;
	}
	else {
		delete displayGrid[y][x];
		displayGrid[y][x] = new DisplayCellNumber( CellType::NUMBER, this->adjacentMines() );
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
			if ( currentX < 0 || currentX >= xCount || currentY < 0 || currentY >= yCount )
					continue;
			if ( hasMine[currentY][currentX] )
				returnValue++; 
		}
	return returnValue; 
}
