
#ifndef __MOUSECLICKEVENT_H
#define __MOUSECLICKEVENT_H

#include <utility>

class MouseClickEvent {

	public:

		enum ClickType{ Left, Right };

		MouseClickEvent( std::pair<int, int>, MouseClickEvent::ClickType );

		std::pair<int, int> getCor() const;
		MouseClickEvent::ClickType getClickType() const;


	private:

		std::pair<int, int> cor;
		MouseClickEvent::ClickType clickType;

};

#endif
