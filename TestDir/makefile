FLAGS = -std=c++11

all:	main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o
proj:	main.o util.o
	g++ main.o util.o -o appl
util:	util.cpp
	g++ $(FLAGS) -c util.cpp -o util.o
