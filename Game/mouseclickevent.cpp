
#include "mouseclickevent.h"

MouseClickEvent::MouseClickEvent( std::pair<int, int> cor, MouseClickEvent::ClickType clickType ){
	this->cor = cor;
	this->clickType = clickType;
}

MouseClickEvent::ClickType MouseClickEvent::getClickType() const {
	return this->clickType;
}

std::pair<int, int> MouseClickEvent::getCor() const {
	return this->cor;
}
