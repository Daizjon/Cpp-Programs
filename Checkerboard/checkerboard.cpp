//Dai'zjon Carney
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
//standard inputs to be read in from user (excluding i z t and b)
	int R, C, CS, W, i, b, z, t;
	char SC;
	cin>> R>> C>> SC>> CS>> W;
//Error Checking
//silent return
	if(R <= 0 or C <= 0 or CS <= 0 or W <= 0) {
		return 0;
	}
	if(SC+CS > 127) {
		return 0;
	}

	if(cin.fail()){
		cerr<< "usage: checkerboard - stdin should contain R, C, SC, CS, and W";
		return 0;
	}

//used for loop for R to get row size
	for(i=0; i<R; i++){
//used for loop for width to get real row size		
		for(b=0; b<W; b++){
//used for loop to get correct number of columns		
			for(z=0; z<C; z++){
//used for loop to print a character W times
				for(t=0; t<W; t++){
//prints result
					cout<<char((SC+ (i+z) % CS));
					
				}
		
			} 
//new line once columns are filled
			cout<<endl;
		}

	}	
			
}
