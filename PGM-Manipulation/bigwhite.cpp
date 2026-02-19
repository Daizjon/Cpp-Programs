//This program takes in two numbers as its command line arguments, then writes a pgm file to standard output.
#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int main( int argc, char **argv){
   	 istringstream ss;
	 int r, c, i;

//checks for right amount of command line arguments
	if (argc != 3) {
		fprintf(stderr, "usage: bigwhite rows cols\n");
		return 0;
	}
//reads in argv[1] in string stream, and stores it in rows. error checks as well
	ss.clear();
	ss.str(argv[1]);
	if (!(ss >> r)) {
		fprintf(stderr, "usage: bigwhite rows cols\n", argv[1]);
		return 0;
	}
//reads in argv[2] in string stream, and stores it in columns. error checks as well
	ss.clear();
	ss.str(argv[2]);
	if (!(ss >> c)) {
		fprintf(stderr, "usage: bigwhite rows cols\n", argv[2]);
		return 0;
	}

//makes sure the number of rows and columns are 1 or above and fails if not
	if (r < 1 or c < 1) {
		fprintf(stderr, "usage: bigwhite rows cols\n");
		return 0;
	}

//gets the total number of pixels


//prints out the required beginning of the file
	printf("P2\n%d %d\n255\n", c, r);

//then prints out each white pixel
  for(int q =0; q < r; q++) {
	for (i = 0; i < c; i++) {
		printf("255 ");
	}
	printf("\n");
  } 

	return 0;
}
