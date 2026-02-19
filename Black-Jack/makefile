CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		main 

main:	main.o CardDeck.o
	$(CXX) $(CXXFLAGS) main.o CardDeck.o -o main

main.o:	main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

CardDeck.o:	CardDeck.cpp CardDeck.h
	$(CXX) $(CXXFLAGS) -c CardDeck.cpp

clean:
	rm -f *.o main
