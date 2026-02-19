//Lab 2
//uses bitwise operators in order to edit binary values to solve a problem
//Dai'zjon Carney
//1/25/2019
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//created class
class BITSET{
	vector<int> vect;
	public:
		BITSET(){
		vect.resize(1);}
//stated and defined the set function, created a while loop to "grow" if needed
//left shifted 1 by the index and ored the result by the original vector value in order to set the user specified index to one 
	void Set(int bit_index){

		int n=bit_index/32;//set
		int m=bit_index%32;//index
		int x= vect.size()-1;
		while(n>x){
			vect.push_back(0);
			x++;
		}
		vect[n]=((1<<m)|vect[n]);

}
//stated and defined the void clear function, left shifted 1 by the index and xored the result by the original vector value in order to set the user specified index to zero
//created a do while loop with a if else statement to "shrink" if needed
	void Clear(int bit_index){
		int n=bit_index/32;//set
		int m=bit_index%32;//index
		vect[n]=((1<<m)^vect[n]);		
		int x=0;//value used to stop loop
		do{
//used this if statement to lower the size of the vector IF the set is equal to 0 and the size of the vector isn't one(since there must be at least one set at all times)
			int i=vect.size();
			if((vect[i-1]==0)&&(i!=1)){
				vect.resize(i-1);
			}
			else{
				x=1;
			}
		}while(x!=1);
	
}
//stated and defined the bool test function, created two if statements to determine if the user specified index is either 1 or 0. returns true if 1 and false if 0.
//created an else case incase the user specified index is currently out of bounds which returns false.
	bool Test(int bit_index){
		int n= bit_index/32;//set
		int m= bit_index%32;//index

		if(((vect[n]>>m)&1)==1){
			return true;
		}
		if(((vect[n]>>m)&1)==0){
			return false;
		}
		else{
			return false;
		}
}
//
	string to_binary(int set){
		string x;
		int i = vect.size()-1;//highest current set 
		if(set>i){
			return x;//returns empty string
		}
		else{
//created a for loop in order to print out binary values to the screen
//32 bits in int so i = 31
//used an if else statement in order to add 1's or 0's to a string
//used a counter and another if statement in order to put spaces every forth time
		int counter=0;
		for (int i = 31; i >= 0; i--) { 
        int k = vect[set] >> i; 
        if (k & 1){ 
            x+="1";
			counter++;
		}
        else{
            x+="0";
			counter++;
		}
			if(counter%4==0){
				x+=" ";
			}
    } 	
			
			return x;//returns string with binary values
		}
	}

};

		
int main (){
char blah;//letter command
int num;//number command
BITSET bity;
//used a do while to continously show the user the command interface until they hit q to quit.
//might edit
	do{ 

		printf("Enter a command from the list:\n");
		printf("t <bit> - Prints 1 or 0 depending on if the given bit # is 1 or 0.\n");
		printf("s <bit> - Sets the given bit to 1.\n");
		printf("c <bit> - Clears the given bit to 0.\n");
		printf("p <set> - Prints the binary representation of the given set.\n");
		printf("q - Quits and returns to the console.\n");
//used scanf for letter command input by user
		scanf(" %c", &blah);
//used a switch to correspond functions with input from the user
	switch(blah){
		case 't':
//used more scanf for the number command input by user
			scanf("%d", &num);
			if(bity.Test(num)==true){
				printf("1\n");
			}
			else{
			printf("0\n");
			}
			break;
		case 's':
			scanf("%d", &num);
			bity.Set(num);
			break;
		case 'c':
			scanf("%d", &num);
			if(bity.Test(num)==0){ //used test funct in the clear case to avoid changing if the bit is already zero
					break;
			}
			else{
			bity.Clear(num);
			}
			break;
		case 'p':
			scanf("%d", &num);
			bity.to_binary(num);
			if(bity.to_binary(num).empty()){//checks if returned string is empty
				printf("Set #%d does not exist.\n", num);
			}
			else{//prints binary value if string was not empty
				printf("%s\n", bity.to_binary(num).c_str());
			}
			break;
	}

	}while( blah!='q');
		return 0;
}

