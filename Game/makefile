all: run
	./main
run: main.o minesweeper.o mouseclickevent.o minesweepermonitor.o SDLHandler.o displaycell.o displaycellnumber.o exitevent.o event.o 
	g++ ./*.o -o main -Wall -g -O2 -std=c++11 -lSDL2 -lSDL2_image
main.o: main.cpp
	g++ -c main.cpp
minesweeper.o: minesweeper.h minesweeper.cpp 
	g++ -c minesweeper.cpp 
mouseclickevent.o: mouseclickevent.h mouseclickevent.cpp 
	g++ -c mouseclickevent.cpp 
minesweepermonitor.o: minesweepermonitor.h minesweepermonitor.cpp 
	g++ -c minesweepermonitor.cpp 
SDLHandler.o: SDLHandler.h SDLHandler.cpp
	g++ -c SDLHandler.cpp 
displaycell.o: displaycell.h displaycell.cpp 
	g++ -c displaycell.cpp 
displaycellnumber.o: displaycellnumber.h displaycellnumber.cpp 
	g++ -c displaycellnumber.cpp 
exitevent.o: exitevent.h exitevent.cpp 
	g++ -c exitevent.cpp 
event.o: event.h event.cpp
	g++ -c event.cpp 
clean: 
	rm -rf *.o main
