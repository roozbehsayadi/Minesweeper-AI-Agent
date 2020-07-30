Here are the codes and some description for the game part.

The most important files in this folder are: 

-   **Makefile**: Compiles the codes and runs the result for you. Run `make` in your terminal.

-   **main.cpp**: Gets properties of the game, creates a *Minesweeper* object and starts it. 

-	**minesweeper.h**: It has a *startGame* function. In a while loop, we

	-	Show the game state to user in a graphical interface using *Monitor* class.

	-	The interface waits until an event happens. It can be a mouse click or quit. 

	-	The event is returned to the Minesweeper class. It's type is *Event*. Two classes *ExitEvent* and *MouseClickEvent* are derived from this class. 

	-	Event is handled with polymorphism. It means that depending on the event's type, different works will be done. 

	-	Since an event is occured, the screen is updated.

	-	We check if the user won the game. Losing is checked inside handleEvent. 

	-	*event* variable is deleted since it was created in heap memory.

-	**SDLHandler.h**: Initializations of SDL stuff are done with the static functions in this class. These are done automatically when *Minesweeper* create a new monitor. 
