
#include "displaycell.h"

DisplayCell::DisplayCell( CellType cellType ) {

	this->setCellType( cellType );

}

int DisplayCell::getNumber() const { 
	return -1;
}

const CellType &DisplayCell::getCellType() const {
	return cellType;
}

void DisplayCell::setCellType( const CellType &cellType ) {
	this->cellType = cellType;
}
