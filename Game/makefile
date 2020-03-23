all: run
	gdb -q main
run: main.o
	g++ ./*.o -o main -Wall -g -O2 -std=c++11 -lSDL2 -lSDL2_image
main.o: minesweeper.o main.cpp
	g++ -c main.cpp
minesweeper.o: minesweepermonitor.o displaycell.o mouseclickevent.o minesweeper.h minesweeper.cpp
	g++ -c minesweeper.cpp 
mouseclickevent.o: event.o displaycell.o displaycellnumber.o mouseclickevent.h mouseclickevent.cpp
	g++ -c mouseclickevent.cpp 
minesweepermonitor.o: displaycell.o mouseclickevent.o SDLHandler.o minesweepermonitor.h minesweepermonitor.cpp
	g++ -c minesweepermonitor.cpp 
SDLHandler.o: SDLHandler.h SDLHandler.cpp
	g++ -c SDLHandler.cpp 
displaycell.o: celltype.o displaycell.h displaycell.cpp 
	g++ -c displaycell.cpp 
displaycellnumber.o: displaycell.o displaycellnumber.h displaycellnumber.cpp
	g++ -c displaycellnumber.cpp 
celltype.o: celltype.h
	g++ -c celltype.h 
exitevent.o: event.o exitevent.h exitevent.cpp 
	g++ -c exitevent.cpp 
event.o: event.h event.cpp
	g++ -c event.cpp 
clean: 
	rm -rf *.o main