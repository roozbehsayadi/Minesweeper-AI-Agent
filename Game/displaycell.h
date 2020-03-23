
#ifndef __DISPLAYCELL_H
#define __DISPLAYCELL_H

#include "celltype.h"

class DisplayCell { 

	private:

		CellType cellType;

	public:

		DisplayCell( CellType = CellType::UNDISCOVERED );

		virtual int getNumber() const;

		const CellType &getCellType() const;

		void setCellType( const CellType &cellType );

};

#endif
