all: run
	./main
run: main.o
	g++ ./*.o -o main -Wall -g -O2 -std=c++11
main.o: minesweeper.o main.cpp
	g++ -c main.cpp
minesweeper.o: minesweeper.h minesweeper.cpp
	g++ -c minesweeper.cpp 
clean: 
	rm -rf *.o main