go: comp link run clean

comp:
	clear;
	g++ -c main.cpp library.cpp

link:
	g++ -o main main.o library.o

run:
	./main

clean:
	rm -f *.o main