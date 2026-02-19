//Dai'zjon Carney
//cs140
//This defines the card deck class which stores the cards as a vector and setups a game of blackjack
#ifndef CardDeck_H
#define CardDeck_H

#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;


class CardDeck {
 public:
	CardDeck( int = 52); //non default constructor
	CardDeck(const CardDeck &); //copy constructor	
	~CardDeck(); //destructor
	const CardDeck &operator= ( const CardDeck &); //assignment operator

	int getSize() const; // to return the size
	void shuffle(); // shuffles deck
	int deal();//deals one card and takes one card away from deck

 private:
	int *deck; //pointer array that holds cards
	int size; //size variable for array



};
#endif
