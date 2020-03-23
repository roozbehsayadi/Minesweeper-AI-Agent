
#ifndef __MOUSECLICKEVENT_H
#define __MOUSECLICKEVENT_H

#include <utility>

#include "event.h"
#include "displaycell.h"
#include "displaycellnumber.h"

class MouseClickEvent : public Event {

	public:

		enum ClickType{ LEFT, RIGHT };

		MouseClickEvent( bool**, DisplayCell**, int, int, std::pair<int, int>, ClickType, bool* );

		virtual void handleEvent() override; 

	private:

		void revealCell();
		int adjacentMines() const; 

		bool **hasMine; 
		DisplayCell **displayGrid;
		int xCount, yCount; 

		std::pair<int, int> cor;
		MouseClickEvent::ClickType clickType; 

		bool *lost; 

};

// #include <utility>

// class MouseClickEvent {

// 	public:

// 		enum ClickType{ Left, Right };

// 		MouseClickEvent( std::pair<int, int>, MouseClickEvent::ClickType );

// 		std::pair<int, int> getCor() const;
// 		MouseClickEvent::ClickType getClickType() const;


// 	private:

// 		std::pair<int, int> cor;
// 		MouseClickEvent::ClickType clickType;

// };

#endif
