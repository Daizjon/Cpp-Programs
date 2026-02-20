//Dai'zjon Carney
//Lab 1
//This lab creates an interactive tic tac toe game
//user enters coordinates and their marker will be placed
#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int grid = 0;
	int grid2 = 0;
	int count=0;
	int xcount, xxcount, xdicount =0;
	int ocount, oocount, odicount= 0;
	vector <string> lines;
	string x="X";
	string o= "O";
	string un= "_";
	int tie= 0;
	int row;
	int col;
	char oldb[10][10];
	char newb[10][10];
	cout << "Enter grid size:" <<endl;
	cin >> grid;
//sets up default board
	for(int z =0; z < grid; z++) {
		for(int i =0; i < grid; i++) {
			cout << un << " ";
//stores value in original and new array
			oldb[z][i]='_';
			newb[z][i]='_';
		}
		cout<<endl;
	}
	grid2= grid*grid;
//game loop logic
	while(tie< grid2){
		cout << "Player 1 (X) pick cell, (row, column) EX: 1 2" <<endl;
		cin >> row >> col;
		if((row<1) or (row>grid)) { 
			while((row<1) or (row>grid)) {cout << "Invalid parameter, try again"<<endl; cin >>row >>col; }
		}
		if((col<1) or (col>grid)) { 
			while((col<1) or (col >grid)){cout <<"Invalid parameter, try again"<<endl; cin >> row >>col;}
		}
		row--;
		col--;
		newb[row][col] = 'X';
		if(oldb[row][col]!='_'){
			while(oldb[row][col]!='_') {cout<< "can't change parameter, try again"<<endl; cin>>row >> col; }
		}
		oldb[row][col] = newb[row][col];
//output updated gameboard

		for(int p =0; p < grid; p++) {
			for(int q =0; q < grid; q++) {
			cout << oldb[p][q] << " ";
		
			}
			cout<<endl;
		}
//		cout<< xdicount << " " <<odicount;
//check if winner

		for(int h =0; h < grid; h++) {
			for(int j =0; j < grid; j++) {
				if(oldb[h][j] == 'X') {xcount++;} //row win
				if(oldb[h][j] == 'O') {ocount++;}
				if(newb[j][h] == 'X') { xxcount++;} //col win
				if(newb[j][h] == 'O') {oocount++;}
//check diagnal
				if(grid == 2) {
					//left diag
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j]  == 'X')) {cout << "X wins" <<endl; return 0;} 
					//right diag

					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j]  == 'X')) {cout << "X wins" <<endl; return 0;} 
				}


				if(grid == 3) {
					//left
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j] == oldb[h+2][j+2]) and (oldb[h][j] == 'X')) {cout << "X wins" <<endl; return 0;} 
					//right

					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j] == oldb[h-2][j+2]) and (oldb[h][j] == 'X')) {cout << "X wins" <<endl; return 0;} 
				}
			
				if(grid == 4) {
					//left
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j] == oldb[h+2][j+2]) and (oldb[h][j] == oldb[h+3][j+3])and oldb[h][j] == 'X') 
					{cout << "X wins" <<endl; return 0;}
					//right
					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j] == oldb[h-2][j+2]) and (oldb[h][j] == oldb[h-3][j+3])and oldb[h][j] == 'X') 
					{cout << "X wins" <<endl; return 0;}

				}

				if(grid == 5) {
					//left
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j]  == oldb[h+2][j+2]) and (oldb[h][j] == oldb[h+3][j+3]) and (oldb[h][j] == oldb[h+4][j+4]) and (oldb[h][j] =='X')) 
					{cout << "X wins" <<endl; return 0;} 
					//right

					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j]  == oldb[h-2][j+2]) and (oldb[h][j] == oldb[h-3][j+3]) and (oldb[h][j] == oldb[h-4][j+4]) and (oldb[h][j] =='X')) 
					{cout << "X wins" <<endl; return 0;} 
				
				}

			}

			if( (xcount == grid) or (xxcount == grid) or (xdicount == grid)){ cout << "X Wins" <<endl; return 0;}

			if( (ocount == grid) or (oocount == grid) or (odicount == grid)){ cout << "O Wins" <<endl; return 0;}
			xcount=0; xxcount=0; ocount=0; oocount = 0, xdicount= 0;
		}

		tie++;
		if(tie == grid2) {break;}

//player 2
		cout<< "Player 2 (O) pick cell, (row, column) EX: 1 2" <<endl;
		
		cin >> row >> col;
		if((row<1) or (row>grid)) { 
			while((row<1) or (row > grid)) {cout << "Invalid parameter, try again" <<endl; cin >> row >> col;}
		}
		if((col<1) or (col>grid)) { 
			while ((col<1) or (col>grid)){cout <<"Invalid parameter, try again" <<endl; cin >>row >> col;}
		}
		row--;
		col--;
		newb[row][col] = 'O';
		if(oldb[row][col]!='_'){
			while(oldb[row][col] != '_') {cout<< "can't change parameter, try again" <<endl; cin >> row >> col; }
		}
		oldb[row][col] = newb[row][col];
//output updated gameboard

		for(int p =0; p < grid; p++) {
			for(int q =0; q < grid; q++) {
			cout << oldb[p][q] << " ";
		
			}
			cout<<endl;
		}
	//	cout << xdicount<< odicount;
//check if winner

		for(int h =0; h < grid; h++) {
			for(int j =0; j < grid; j++) {
				if(oldb[h][j] == 'X') {xcount++;} //row win
				if(oldb[h][j] == 'O') {ocount++;}	
				if(newb[j][h] == 'X') {xxcount++;} //col win
				if(newb[j][h] == 'O') {oocount++;}


//diagonal win				
				if(grid == 2) {
					//left diag
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j]  == 'O')) {cout << "O wins" <<endl; return 0;}
					//right diag

					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j]  == 'O')) {cout << "O wins" <<endl; return 0;}
				}

				if(grid == 3) {
			//left
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j] == oldb[h+2][j+2]) and (oldb[h][j] == 'O')) {cout << "O wins" <<endl; return 0;} 
			//right
			
					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j] == oldb[h-2][j+2]) and (oldb[h][j] == 'O')) {cout << "O wins" <<endl; return 0;} 
				}
			
				if(grid == 4) {
					//left
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j] == oldb[h+2][j+2]) and (oldb[h][j] == oldb[h+3][j+3])and (oldb[h][j] == 'O')) 
					{cout << "O wins" <<endl; return 0;} 
					//right

					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j] == oldb[h-2][j+2]) and (oldb[h][j] == oldb[h-3][j+3])and (oldb[h][j] == 'O')) 
					{cout << "O wins" <<endl; return 0;} 
				}

				if(grid == 5) {
					//left
					if((oldb[h][j] == oldb[h+1][j+1]) and (oldb[h][j]  == oldb[h+2][j+2]) and (oldb[h][j] == oldb[h+3][j+3]) and (oldb[h][j] == oldb[h+4][j+4]) and (oldb[h][j] =='O')) 
					{cout << "O wins" <<endl; return 0;} 
					//right

					if((oldb[h][j] == oldb[h-1][j+1]) and (oldb[h][j]  == oldb[h-2][j+2]) and (oldb[h][j] == oldb[h-3][j+3]) and (oldb[h][j] == oldb[h-4][j+4]) and (oldb[h][j] =='O')) 
					{cout << "O wins" <<endl; return 0;} 

				}

			}

			if( (xcount == grid) or (xxcount == grid) or (xdicount == grid)){ cout << "X Wins" <<endl; return 0;}

			if( (ocount == grid) or (oocount ==grid) or (odicount == grid)){ cout << "O Wins" <<endl; return 0;}
			xcount=0; xxcount=0;  ocount=0; oocount = 0, odicount=0;
		}
		tie++;
	}
	cout << "Tie" <<endl;
}
