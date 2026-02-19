//Dai'zjon Carney
//This program reads in a pgm file and outputs it horizontal reflection
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

//created struct to hold variables needed
struct pgm_file {
    vector<int>pix;
    string p2;
    int r, c, num, totpix;
//0 arg constructor
    pgm_file();
//created void function to flip image
    void flip();
};
//define class values
pgm_file::pgm_file()
        : r(0), c(0), num(0), totpix(0) {}

//defines void funct
void pgm_file::flip() {
    int z, x, flipix = 0, i;

//prints the required beginning of the file
    printf("%s\n%d %d\n%d\n", p2.c_str(), c, r, num);

//prints each pixel's starting from far right    
	for (z = 0; z < r; z++) {
		for (x=c; x>0; x--){
			i=((z*c)+x-1);
			flipix = pix[i];
        	printf("%d ", flipix);
   		 }
		printf("\n");
	}
}


int main(){
    pgm_file pgm;
    string extra;
    int curpix, valpix=0;

//checks if first word is p2 and fails if not
    cin >> pgm.p2;
    if (pgm.p2 != "P2") {
        fprintf(stderr, "Bad PGM file -- first word is not P2\n");
        return 0;
    }

//Reads in number of colums and fails if not specified
    cin >> pgm.c;
    if (pgm.c < 1) {
        fprintf(stderr, "Bad PGM file -- No column specification\n");
        return 0;
    }

//Reads in number of rows and fails if not specified
    cin >> pgm.r;
    if (pgm.r < 1) {
        fprintf(stderr, "Bad PGM file -- No row specification\n");
        return 0;
    }

//Reads in the number 255 and fails if the number isn't 255
    cin >> pgm.num;
    if (pgm.num != 255) {
        fprintf(stderr, "Bad PGM file -- No 255 following the rows and columns\n");
        return 0;
	}

//Sets the total number of pixels
    pgm.totpix= pgm.c * pgm.r;

//Reads in all pixels and stores them in vector 
    for (curpix = 0; curpix < pgm.totpix; curpix++) {
                cin >> valpix;
                if (valpix < 0 or valpix > 255 or cin.fail()) {
                    fprintf(stderr, "Bad PGM file -- pixel %d is not a number between 0 and 255\n", curpix);
                    return 0;
                }
                    pgm.pix.push_back(valpix);
    }

//Checks if there's extra stuff in the PGM file
    if (cin >> extra){
        fprintf(stderr, "Bad PGM file -- Extra stuff after the pixels\n");
        return 0;
    }

	pgm.flip();

	return 0;
}
