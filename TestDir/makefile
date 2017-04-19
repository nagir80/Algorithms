FLAGS = -std=c++11
all:	appl

main.o:	main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o
util.o:	util.cpp
	g++ $(FLAGS) -c util.cpp -o util.o
appl:	main.o util.o
	g++ main.o util.o -o appl

