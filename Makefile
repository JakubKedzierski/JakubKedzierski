SortingAlgorythms.out: obj/SortingAlgorythms.o 
	g++ -Wall -pedantic -std=c++0x -o SortingAlgorythms obj/SortingAlgorythms.o -lpanel -lcurses

obj:
	mkdir obj

obj/SortingAlgorythms.o: SortingAlgorythms.hh SortingAlgorythms.cpp 
	g++ -Wall -pedantic -std=c++0x -c -o obj/SortingAlgorythms.o SortingAlgorythms.cpp

clean:
	rm -f *.o 
