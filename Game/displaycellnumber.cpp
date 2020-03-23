
#include "displaycellnumber.h"

DisplayCellNumber::DisplayCellNumber( CellType cellType, int number ) : DisplayCell( cellType ) {
	this->number = number;
}

int DisplayCellNumber::getNumber() const {
	return this->number;
}
