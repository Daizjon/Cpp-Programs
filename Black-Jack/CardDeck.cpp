//Dai'zjon Carney
//cs140
//Lab4
//This file defines the CardDeck class functions
#include "CardDeck.h"

#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>       
#include <ctime>    
#include <cstdlib> 

//non default constructor 
//creates card deck
CardDeck::CardDeck(int n) {
	srand(time(NULL));
	size = n;
	deck = new int[size];
	int z = 2;
	for(int i =0; i <size; i++) {
		deck[i]=z;
		z++;
		if(z == 12) {
			i++;
			deck[i] = 10; i++;
			deck[i] =10; i++;
			deck[i] = 10;
			z=2;
		} // makes aces the max value then adds 3 10s for jack, queen, king)
	}
}

//copy constructor
CardDeck::CardDeck(const CardDeck &CardDeckToCopy)  : size(CardDeckToCopy.size)  {

  deck = new int[size]; // create space for pointer-based array

  for (int i = 0; i < size; i++)
    deck[i] = CardDeckToCopy.deck[i]; // copy into object

}


//assignment operator
const CardDeck &CardDeck::operator=( const CardDeck &right ) {

  if ( &right != this ) { // avoid self-assignment

    if ( size != right.size ) {
      
      delete [] deck; // release space
      size = right.size; // resize this object
      deck = new int[ size ]; // create space for array copy
    
    } // end inner if

    for ( int i = 0; i < size; i++ )	
      deck[ i ] = right.deck[i]; // copy array into object
  
  } 

  return (*this); 

} 


//destructor
CardDeck::~CardDeck() {
	delete [] deck;
}


//gets size (number of cards in deck)
int CardDeck::getSize() const {
	return size;
}


//deals card (removes card from deck and gives to user or dealer
int CardDeck::deal() {
	int a = deck[size-1];
	size--;
	return a;

}
//shuffle deck
void CardDeck::shuffle() {
	vector <int> holder;
	holder.clear();
	cout << "deck before shuffle" << endl;
	for(int i=0; i < size; i++){
		cout << deck[i] << " ";
		holder.push_back(deck[i]);
	}

	cout<<endl<<endl;

	random_shuffle ( holder.begin(), holder.end() );
	cout << "deck after shuffle" <<endl;
	for( int i=0; i < size; i++) {
		deck[i] = holder[i];
		cout << deck[i] << " ";
	}

	cout<<endl <<endl;


}
