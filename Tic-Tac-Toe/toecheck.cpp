//Dai'zjon Carney
//lab 1
//This lab takes tic tac toe input and determines the winner
#include <iostream>
#include <cstdio>

using namespace std;

int main () {
	int grid;
	char val;
	char hold[50];
	char box[10][10];
	cin >> grid;
	for(int i =0; i < (grid *grid); i++) {
		cin >> val;
		hold[i] = val;
	}
	for (int z =0; z < grid; z++) {
        for(int q =0; q < grid; q++) {
//stores values in new array
        	box[z][q] = hold[i];
			cout << box[z][q] << endl;   
        }
    }
}
