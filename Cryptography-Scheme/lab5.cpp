//lab6.cpp
//COSC130
//Dai'zjon Carney
//2/22/2019
//This program reads an encrypted file, decrypts it, and prints the contents to the screen.
#include <cstdio>
using namespace std;

int main(int argc, char* argv[]){
	char dkey, data;
	int nkey, index, filesize,totalchar;
	char* m;
	FILE *fin;
//checks to make sure there are four arguments and fails if not
	if(argc != 4){
		printf("wrong number of arguments");
		return -1;
	}
//opens and reads the binary file at argv[1], and error checks if the file wasn't opened 
	fin = fopen(argv[1], "rb");
	if(fin == nullptr){
		printf("error, file did not open");
		return -1;
	}
//sets the data key and indexkey equal to the specified command line arguments
	dkey= argv[2][0];
	sscanf(argv[3],"%d", &nkey);
//gets the file size by seeking to the end and then divides that by 8 to get the total number of characters
	fseek(fin, 0, SEEK_END);
	filesize = ftell(fin);
	totalchar= filesize/8;
//sets the array of char m equal to the total number of characters -1 in order to have the array filled, returned file back to beginning position.
	m = new char[totalchar-1];
	fseek(fin, 0, SEEK_SET);

//for loop that goes a number of totalchar times that reads from the file to data and index, also have a fseek to skip padding
	for(int i=0; i<totalchar; i++){
		fread(&data, 1, 1,fin);
		fseek(fin, 3, SEEK_CUR);
		fread(&index, 1, 4,fin);
	
//use the XOR to decrypt the index and data.
		index ^= nkey;
		data ^= dkey;
//checks to see if index is within bounds before using before using the index
		if(index <0 || index >(totalchar-1)){
		printf("error, index is out of bounds");
		}

		m[index] = data;

	}
//prints the message to the screen, then deallocates the message and closes the file
	printf("%s", m);
	delete[]m;
	fclose(fin);
	return 0;
}

