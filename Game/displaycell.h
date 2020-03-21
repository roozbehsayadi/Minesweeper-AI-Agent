
#ifndef __DISPLAYCELL_H
#define __DISPLAYCELL_H

#include "celltype.h"

class DisplayCell { 

	private:

		CellType cellType;

	public:

		const CellType &getCellType() const {
			return cellType;
		}

		void setCellType( const CellType &cellType ) {
			this->cellType = cellType;
		}

};

#endif
