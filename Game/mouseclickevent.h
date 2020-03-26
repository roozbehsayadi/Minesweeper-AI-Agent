
#ifndef __MOUSECLICKEVENT_H
#define __MOUSECLICKEVENT_H

#include <iostream>
#include <utility>

#include "event.h"
#include "displaycell.h"
#include "displaycellnumber.h"
#include "minesweeper.h"

class Minesweeper; 

class MouseClickEvent : public Event {

	public:

		enum ClickType{ LEFT, RIGHT };

		MouseClickEvent( Minesweeper*, std::pair<int, int>, ClickType );

		virtual void handleEvent() override; 

	private:

		void revealCell();
		int adjacentMines() const; 

		Minesweeper *minesweeper; 

		// bool **hasMine; 
		// DisplayCell ***displayGrid;
		// int xCount, yCount; 

		std::pair<int, int> cor;
		MouseClickEvent::ClickType clickType; 

		// bool *lost; 
		// bool *initialized; 

};

#endif
