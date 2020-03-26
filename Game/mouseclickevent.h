
#ifndef __MOUSECLICKEVENT_H
#define __MOUSECLICKEVENT_H

#include <iostream>
#include <utility>
#include <vector>

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

		void revealCell( int, int );
		void DFS( int, int );
		std::vector<std::pair<int, int>> adjacentCors( int, int ) const; 
		int adjacentMinesCount( int, int ) const; 

		Minesweeper *minesweeper; 

		std::pair<int, int> cor;
		MouseClickEvent::ClickType clickType; 

};

#endif
