main.out: main.o SortingAlgorythms.o
	g++ -Wall -pedantic -std=c++0x -o main SortingAlgorythms.o main.o -lpanel -lcurses

SortingAlgorythms.o: SortingAlgorythms.cpp SortingAlgorythms.hh
	g++ -Wall -pedantic -std=c++0x -c -o SortingAlgorythms.o SortingAlgorythms.cpp

main.o: main.cpp 
	g++ -Wall -pedantic -std=c++0x -c -o main.o main.cpp

clean:
	rm -f *.o 
