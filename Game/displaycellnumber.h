
#ifndef __DISPLAYCELLNUMBER_H
#define __DISPLAYCELLNUMBER_H

#include "displaycell.h"

class DisplayCellNumber : public DisplayCell {

	private:

		int number;

	public:

		DisplayCellNumber( CellType, int );

		virtual int getNumber() const override;

};

#endif
