all: run
	./main
run: main.o
	g++ ./*.o -o main -Wall -g -O2 -std=c++11 -lSDL -lSDL_image -lSDL_ttf 
main.o: minesweeper.o main.cpp
	g++ -c main.cpp
minesweeper.o: minesweepermonitor.o displaycell.o minesweeper.h minesweeper.cpp
	g++ -c minesweeper.cpp 
minesweepermonitor.o: minesweepermonitor.h minesweepermonitor.cpp
	g++ -c minesweepermonitor.cpp 
displaycell.o: celltype.o displaycell.h displaycell.cpp 
	g++ -c displaycell.cpp 
celltype.o: celltype.h
	g++ -c celltype.h 
clean: 
	rm -rf *.o main