all: run
	./main
run: main.o
	g++ ./*.o -o main -Wall -g -O2 -std=c++11 -lSDL -lSDL_image -lSDL_ttf 
main.o: minesweeper.o main.cpp
	g++ -c main.cpp
minesweeper.o: minesweepermonitor.o minesweeper.h minesweeper.cpp
	g++ -c minesweeper.cpp 
minesweepermonitor.o: minesweeper.h minesweeper.cpp
	g++ -c minesweepermonitor.cpp 
clean: 
	rm -rf *.o main