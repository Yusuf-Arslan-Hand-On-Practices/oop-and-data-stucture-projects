target: compile link run clean

compile:
	g++ -std=c++11 -c *.cpp

link:
	g++ -std=c++11 -o main *.o

run: compile link
	clear;
	./main

clean:
	rm *.o main
