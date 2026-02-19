//Dai'zjon Carney
//cs140
//lab4
//This file creates an interactive black jack game.

#include "CardDeck.h"   // class definition for CardDeck used below
using namespace std;

int main() {
  int dealw=0; //dealer wins
  int userw=0; //user wins
  int usum =0; // sum of user cards
  int ucom = 0; // temp sum of user cards that compares in the stay option
  int dsum =0; //sum of dealer cards
  char ans; //user answer choice

  CardDeck Cdeck; //main carddeck
  CardDeck sto; //clean deck used for reassignment

  vector <int> userd; //player current cards
  vector <int> dealerd;//dealer current card

game: //jumps here to continue game
  
//game conversation, explains to the user how to input answers
  cout<< "Time to play BlackJack!" << endl <<endl; 
  cout <<"Size of deck is " << Cdeck.getSize()<< endl <<endl;
  Cdeck.shuffle(); //shuffles initially
  cout << "Okay first deal, here's your card";
	userd.push_back(Cdeck.deal()); //adds to user hand
	cout <<" "<< userd[0] << endl<<endl;
  cout << "type h for hit or s for stay" <<endl;

  cin>> ans;
  
  if(ans == 'h') {
	while(ans =='h') {
	if(Cdeck.getSize() == 15) {Cdeck = sto; Cdeck.shuffle();} // new deck if current deck 15, shuffles
	userd.push_back(Cdeck.deal()); //adds to user hand
	cout << endl << "Your card is " << userd.back() <<endl <<endl;
	for(unsigned int z =0; z < userd.size(); z++) { //check if over 21
		usum += userd[z];
	}
	
	//user reached 21
	if(usum == 21) { userw++; cout<< "you won, play again  y or n?" <<endl<<endl; cout<<"dealer " <<dealw << "    user " <<userw <<endl;
		cin >>ans;

		if(ans == 'y') { //continues game reset user and dealer hands
		    userd.clear();
			dealerd.clear();
			usum = 0;
			goto game;
		}


		if(ans == 'n') { //ends game
			goto end;
		}
	} 

  //user busted
	if(usum > 21) { dealw++; cout<< "you lost, play again  y or n?" <<endl <<endl; cout << "dealer " <<dealw << "   user " << userw <<endl;
		cin >> ans; 

		
		if(ans == 'y') { 
		    userd.clear();
			dealerd.clear();
			usum =0;
			goto game;
		}


		if(ans == 'n') { 
			goto end;
		}
	}

  //user can keep hit again or stay if satisfied	
	cout << "type h for hit or s for stay" <<endl;
	cin >> ans;
	ucom = usum;
	usum=0;
 } 
 }
 

//user stays so now dealer's turn	//user wins on ties
  if(ans == 's') {
	cout << endl << "So you stayed... now it's my turn pal" <<endl<<endl;
	while(dsum <17) { //dealer hits unless they're at 17 or higher	
	   if(Cdeck.getSize() == 15) {Cdeck = sto; Cdeck.shuffle();} // new deck if 15 shuffles
		dealerd.push_back(Cdeck.deal()); // Adds card to dealers hand
		cout <<"My card is " << dealerd.back()<<endl<< endl;
		dsum=0;
		for(unsigned int z=0; z < dealerd.size(); z++) {
			dsum += dealerd[z];
		}

	//dealer reached 21
		if(dsum == 21) { dealw++; cout << "I won, play again? y or n" <<endl <<endl; cout <<"dealer " <<dealw << "   user " <<userw <<endl;
			cin >>ans;
			

			if(ans == 'y') { //continues game resets hands
			    userd.clear();
				dealerd.clear();
				dsum =0;
				goto game;
			}


			if(ans == 'n') { //ends game
				goto end;
			}

		}

     //dealer busted 		
	    if(dsum > 21) { userw++; cout<< "you won, play again?  y or n" <<endl<<endl; cout<<"dealer " <<dealw << "    user " <<userw <<endl;
			cin >>ans;
			
			if(ans == 'y') { 
				userd.clear();
				dealerd.clear();
				dsum =0;
				goto game;
			}


			if(ans == 'n') { 
				goto end;
			}
		
		}
	
	}// ends while which means dealer was able to stop without busting or hitting 21

//If neither dealer or user busted takes the higher card	
	if(dsum > ucom) { dealw++; cout<< "I won, play again?  y or n" <<endl<<endl; cout<<"dealer " <<dealw << "    user " <<userw <<endl;
		cin >>ans;

		if(ans == 'y') { 
		    userd.clear();
			dealerd.clear();
			dsum =0;
			ucom=0;
			goto game;
		}


		if(ans == 'n') { 
			goto end;
		}
	} 


//If neither busted takes the higher card or awards win to user if tie
	if(dsum <= ucom) { userw++; cout<< "you won, play again?  y or n" <<endl<<endl; cout<<"dealer " <<dealw << "    user " <<userw <<endl;
		cin >>ans;


		if(ans == 'y') { 
		    userd.clear();
			dealerd.clear();
			ucom =0;
			dsum =0;
			goto game;
		}


		if(ans == 'n') { 
			goto end;
		}
	} 
	
	
	dsum=0;
  }

end:
  
//user hits n so ends game
 cout << endl <<"Thanks for playing bye" <<endl; 
 return 0;


}
