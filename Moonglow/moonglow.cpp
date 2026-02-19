//Dai'zjon Carney
#include <iostream>
#include <cstdio>
using namespace std;

int main(){

	string tempor, name;
	int avgn, i, z;
	double sc, tnum, avgsc;
	bool avg;
//while loop to read until end of file.
while (!cin.eof()) {
//sees if last cin failed and clears if so
		if (cin.fail()) {
			cin.clear();			
//cin to temporary variable to  use for later comparisons			
			cin >> tempor;
//adds the last calculated average to the avg score
			if (avgn > 0) {
				avgsc =avgsc/avgn;
				sc = sc+ avgsc;
			}
//when cin fails, have to reset these three variables
			avgsc = 0, avgn = 0;
			avg=false;
//gets the student's name
			if (tempor == "NAME") {
				cin.clear();
				cin >> name;
			}
//sets the avg variable to true so that the numbers are calculated in a average
			if(tempor == "AVERAGE"){
				avg=true;
			}
		}
		else {
//now come the scores. If the bool is true, then the scores are part of an average. Otherwise just a normal score
			if (avg == true) {
				avgsc = avgsc+ tnum;
				avgn++;
			}
			else{
				sc =sc+ tnum;
			}
		}

		cin >> tnum;
	}
//tried using cout but just couldn't get the answer to come out correctly for some reason so had to to use printf
	printf("%s %g\n", name.c_str(), sc);

	return 0;
}
