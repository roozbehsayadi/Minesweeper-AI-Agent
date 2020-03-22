all: run
	./main
run: main.o
	g++ ./*.o -o main -Wall -g -O2 -std=c++11 -lSDL2 -lSDL2_image
main.o: minesweeper.o main.cpp
	g++ -c main.cpp
minesweeper.o: minesweepermonitor.o displaycell.o minesweeper.h minesweeper.cpp
	g++ -c minesweeper.cpp 
minesweepermonitor.o: SDLHandler.o minesweepermonitor.h minesweepermonitor.cpp
	g++ -c minesweepermonitor.cpp 
SDLHandler.o: SDLHandler.h SDLHandler.cpp
	g++ -c SDLHandler.cpp 
displaycell.o: celltype.o displaycell.h displaycell.cpp 
	g++ -c displaycell.cpp 
celltype.o: celltype.h
	g++ -c celltype.h 
clean: 
	rm -rf *.o main