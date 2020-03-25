
#ifndef __EXITEVENT_H
#define __EXITEVENT_H

#include "event.h"

class ExitEvent : public Event {

    private:

        bool *quit; 

    public:

        ExitEvent( bool* ); 

        virtual void handleEvent() override; 

        bool isUserQuit() const; 

};

#endif
