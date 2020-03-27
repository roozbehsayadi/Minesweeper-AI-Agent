
#include "exitevent.h"

ExitEvent::ExitEvent( bool *quit ) {
	this->quit = quit; 
}

void ExitEvent::handleEvent() { 
	*(this->quit) = true;
}

bool ExitEvent::isUserQuit() const {
	return *(this->quit);
}
