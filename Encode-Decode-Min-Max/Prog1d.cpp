#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



void encode(string &oldstring,int x){
	string newstring="";
	for(int i=0; i < (oldstring.size()); i++){ //for loop to go through whole string
		if(isalnum(oldstring[i])){	//checks if alphanumeric 
			
			
			if(isupper(oldstring[i])){	//checks if upper
				if((oldstring[i]+x) > 90){ //if added with x is greater than 90, -26 to start back at beggining of upper 
					newstring[i] = (oldstring[i] + x -26);
					cout<<newstring[i];
				}
				else {	//otherwise string is good so just add x
					newstring[i] = (oldstring[i] + x);
					cout<<newstring[i];
				}
			}
			
			
			if(islower(oldstring[i])){   //checks if lower
                if((oldstring[i]+x) > 122){ //if added with x is greater than 122, -26 to start back at beggining of lower
                    newstring[i] = (oldstring[i] + x -26);
                    cout<<newstring[i];
                }
                else {  //otherwise string is good so just add x
                    newstring[i] = (oldstring[i] + x);
                    cout<<newstring[i];
                }
            }

		}
		else {
			newstring[i] = oldstring[i];//if not alphanumeric no need to change
			cout<<newstring[i];
		}

  			
	}
}

void decode(string &oldstring,int x) {
	 string newstring="";
     for(int i=0; i < (oldstring.size()); i++){ //for loop to go through whole string
    	 if(isalnum(oldstring[i])){  //checks if alphanumeric


            if(isupper(oldstring[i])){   //checks if upper
                if((oldstring[i]-x) < 65){ //if subtracted with x is lesser than 65, +26 to start back at end of upper
                    newstring[i] = (oldstring[i] - x + 26);
                    cout<<newstring[i];
                }
                else {  //otherwise string is good so just subtract x
                    newstring[i] = (oldstring[i] - x);
                    cout<<newstring[i];
                }
            }


            if(islower(oldstring[i])){   //checks if lower
                if((oldstring[i]-x) < 97){ //if subtracted with x is lesser than 97, +26 to start back at end of lower
                    newstring[i] = (oldstring[i] - x + 26);
                    cout<<newstring[i];
                }
                else {  //otherwise string is good so just subtract x
                    newstring[i] = (oldstring[i] - x);
                    cout<<newstring[i];
				}
			}
		}
		else{
		newstring[i]=oldstring[i];//means not alphanumeric so stays the same
		cout<<newstring[i];
		}
	}
}

int main (int argc, char* argv[]) {
	string line="";
	string num= argv[2];
	string code= argv[1];
	if (argc !=3) {
		fprintf(stderr, "Incorrect number of command line arguments, exiting.\n");
		return 0;
	}
	if ((num< "0") or (num > "9")) {
		  fprintf(stderr, "Incorrect value for argv[2], exiting\n");
        return 0;
	}
	if (code == "-encode") {
	    while(cin) {
        getline(cin, line);
		encode(line, atoi(argv[2]));
    	}
	}
	if (code == "-decode") {
		while(cin) {
        getline(cin, line);
        decode(line, atoi(argv[2]));
        }	
	}
	fprintf(stderr, "argv[1] should be -encode or -decode, exiting\n");
}
