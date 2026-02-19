//Dai'zjon Carney:
//Bit Matrices / Lab 5 cs140
//Description: This lab involves bit matrices and various functions to modify them.
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include "bitmatrix.hpp"
using namespace std;
//The hash function that was given in lecture notes
unsigned int djb_hash(string key){
	unsigned int h=5381;
	for(size_t i=0; i<key.size(); i++){
			h = (h << 5) + h + key[i];
	}
	return h;
}
//Creates an empty bit matrix by resizing to the specified size.
//if the rows and cols are less than or = 0 throws the respective bad strings.
Bitmatrix::Bitmatrix(int rows, int cols)
{ 
	if (rows <= 0){ 
		throw((string) "Bad rows");
	}
    if (cols <= 0){ 
		throw((string) "Bad cols");
	}
	
		M.resize(rows);
		for( int i = 0; i < rows; i++){
			M[i].resize(cols, '0');
		}
}
//Reads bit matrix from file. throws string if file can't be opened
//used while getline statement to read into string s
//throws string if encounter errors ie file isn't just 1's, 0's or white space
Bitmatrix::Bitmatrix(const string &fn)
{
	ifstream fin;
	size_t i;
	string row, s;

	fin.open(fn.c_str());
	if (fin.fail()){
		throw((string) "Can't open file");
	}

	while(getline(fin,s)){
		row.clear();
		for(i=0; i<s.size(); i++){
			if(s[i]=='1' or s[i]=='0') row.push_back(s[i]);
			else if(s[i] !=' '){
				throw((string) "Bad file format");
			}
		}
		if (s.size() > 0) M.push_back(row);		
	}
	fin.close();
} 
//makes a copy of the current bit matrix
//sets new bit matrix to size of old bit matrix and fills in every value from the old bit matrix into the new bm.
Bitmatrix *Bitmatrix::Copy() const
{
	Bitmatrix *bm;
	bm = new Bitmatrix(M.size(), M[0].size());

	for (size_t r = 0; r < M.size(); r++) {
		for (size_t c = 0; c < M[r].size(); c++) {
			bm->Set(r, c, M[r][c]);
		}
	}

	return bm;
}
//writes to a file
//error check to see if file failed
//for loop to put every row/column into file. moves to next line after row is complete.
bool Bitmatrix::Write(const string &fn) const
{
	ofstream fout;
	fout.open(fn.c_str());
	if (fout.fail()) return false;

	for (size_t r = 0; r < M.size(); r++) {
		for (size_t c = 0; c < M[r].size(); c++) {
			fout << (M[r][c] - '0');
		}
		fout << "\n";
	}
	fout.close();
	return true;
}
//prints the bit matrix 
void Bitmatrix::Print(size_t w) const
{
	size_t r, c;
	
//used first if statment to print blank line after every w rows
//second if statement to print bit matrix with no spaces if w<=0
//else statement to print bit matrix with space after every w characters if w>0
	for(r=0; r<M.size(); r++){
		if(w>0 and r!=0 and r%w==0) cout<<endl;
		if (w<=0){
			cout <<M[r] <<endl;
		} 
		else{
			for(c=0; c<M[r].size(); c++){
				if(c%w ==0 and c!=0) cout<<" ";
				printf("%c", M[r][c]);
			}
		cout <<endl;
		}
	}
}
//creates a pgm file               
bool Bitmatrix::PGM(const string &fn, int p, int border) const
{
 	
	
	FILE * pgm;
	int r = 0, c = 0, newr = 0, newc = 0;
	r = M.size();
	c = M[0].size();
	// size of the border
	newr = (r * p) + ((r + 1) * border);
	newc = (c * p) + ((c + 1) * border);

	pgm = fopen(fn.c_str(), "w");
//	if (pgm==NULL) return false;
//	if( (p<=0) or (border <= 0)) return false;


	//required non-pixel values for the PGM file
	fprintf(pgm, "P2\n%d %d\n255\n", newc, newr);

	// Print the beginning border rows
	for (int i = 0; i < border; i++) {
		for (int j = 0; j < newc; j++) {
			fprintf(pgm, "0 ");
		}
		fprintf(pgm, "\n");
	}

	for (int i = 0; i < r; i++) {
		for (int r1 = 0; r1 < p; r1++) {
			for (int j = 0; j < c; j++) {
				for (int b = 0; b < border; b++) {
					fprintf(pgm, "0 ");
				}
				for (int k = 0; k < p; k++) {
					//actual pixel
					if (M[i][j] == '0') fprintf(pgm, "255 ");
					else fprintf(pgm, "100 ");
				}
			}
			// border at the end
			for (int b = 0; b < border; b++) {
				fprintf(pgm, "0 ");
			}
			fprintf(pgm, "\n");
		}
		for (int i = 0; i < border; i++) {
			for (int j = 0; j < newc; j++) {
				fprintf(pgm, "0 ");
			}
			fprintf(pgm, "\n");
		}
	}

	fclose(pgm);
	return true;
}
//returns number of rows in M
int Bitmatrix::Rows() const
{
  return M.size();
}
//returns number of cols in M                            
int Bitmatrix::Cols() const
{
  return M[0].size();
}
//returns the value of the specified element
//error checked to return 'x' if the element is bad
char Bitmatrix::Val(int row, int col) const
{
	size_t r=row, c=col;
	if ( row <0 or col <0) return 'x';
	if (r >= M.size() or c >= M[0].size()) return 'x';
	return (M[row][col]);
}
//sets the specified bit matrix entry to the given value of 1 or 0
//error checked to return false if unsuccessful
bool Bitmatrix::Set(int row, int col, char val)
{
	size_t r=row, c=col;
	if(row<0 or col<0) return false;
	if(r >= M.size() or c >= M[0].size()) return false;
	if(val=='0' or val=='1'){
		M[row][col]=val;
		return true;
	}
	return false;
}
//swaps the specified rows
//error checked to return false if unsuccessful
//created i to be temporary value in order to switch rows
bool Bitmatrix::Swap_Rows(int r1, int r2)
{
	int i=0;
	size_t z=0, row1=r1, row2=r2;
	if (r1<0 or r2<0) return false;
	if (row1 >=M.size() or row2>=M.size()) return false;
	for (z=0; z<M[0].size(); z++){
		i=M[r1][z];
		M[r1][z]=M[r2][z];
		M[r2][z]=i;
	}
	return true;
}
//sets row 1 to the sum of row 1 and row 2
//error checked to return false if unsuccessful
//practically incorporated xor to get the sum
bool Bitmatrix::R1_Plus_Equals_R2(int r1, int r2)
{
	size_t c=0, row1=r1, row2=r2;
	if( r1<0 or r2<0) return false;
	if( row1 >=M.size() or row2 >= M.size()) return false;
	for (c = 0; c < M[r1].size(); c++) {
		if((M[r1][c] == '0' and M[r2][c] == '0') or (M[r1][c] == '1' and M[r2][c] == '1'))
			M[r1][c] = '0';
		else M[r1][c] = '1';
	}
	return true;
}
      
//creates new bit matrix which is the sum of a1 and a2
//the rows and cols of a1 and a2 are stored in 4 ints with the help of the rows() cols() methods
//returns null if a1 and a2 don't have same number of rows and cols
//the values from a1 and a2 are stored in 2 chars with the help of the val() method
//now the addition of the two chars, is the new value of the new bitmatrix
Bitmatrix *Sum(const Bitmatrix *a1, const Bitmatrix *a2)
{
	Bitmatrix *bm;
	char a1val, a2val, nval;
	int a1rows = 0, a1cols = 0, a2rows = 0, a2cols = 0;
	a1rows = a1->Rows(); a1cols = a1->Cols();
	a2rows = a2->Rows(); a2cols = a2->Cols();

	if (a1rows != a2rows or a1cols != a2cols) return NULL;

	bm = new Bitmatrix(a1rows, a1cols);
	for (int r = 0; r < a1rows; r++) {
		for (int c = 0; c < a1cols; c++) {
			a1val = a1->Val(r, c) + '0'; a2val = a2->Val(r, c) + '0';//+'0'
			nval = (((a1val-'0') + (a2val-'0')) % 2) + '0';//-'0
//			cout<<nval<<" ";
			bm->Set(r, c, nval); 
		}
	}

	return bm;	
}
//multiplies two bit matrixes together
//checks if first cols is equal to second's rows and returns NULL if not
//if the row of the first matrix doesn't equal the column of the second, then multiplication isn't possible
Bitmatrix *Product(const Bitmatrix *a1, const Bitmatrix *a2)
{
	Bitmatrix *bm;
	char a1val, a2val, nval;
	int a1rows = 0, a1cols = 0, a2rows = 0, a2cols = 0, total = 0;
	int r = 0, c = 0, c1 = 0;
	a1rows = a1->Rows(); a1cols = a1->Cols();
	a2rows = a2->Rows(); a2cols = a2->Cols();

	if (a1cols != a2rows) return NULL;

	bm = new Bitmatrix(a1rows, a2cols);
	for (r = 0; r < a1rows; r++) {
		for (c = 0; c < a2cols; c++) {
			for (c1 = 0; c1 < a1cols; c1++) {
				a1val = a1->Val(r, c1)+'0'; 
				a2val = a2->Val(c1, c)+'0';
				total += (a1val-'0') * (a2val-'0');
			}
			nval = (total % 2) + '0';
			bm->Set(r, c, nval);
			total = 0;
		}
	}

	return bm;	
}
//This creates a new bit-matrix composed of the specified rows of the given bit-matrix.
Bitmatrix *Sub_Matrix(const Bitmatrix *a1, const vector <int> &rows)
{

	Bitmatrix *bm;
	char a1val;
	unsigned int a1rows = 0;
	int a1cols = 0;
	int wtf;


	a1rows = a1->Rows(); a1cols = a1->Cols();
	// If  more rows than existing in the bitmatrix, or no rows return null
	if (rows.size() > a1rows || rows.size() <= 0) return NULL;

	bm = new Bitmatrix(rows.size(), a1cols);
	for (unsigned int r = 0; r < rows.size(); r++) {
		for (int c = 0; c < a1cols; c++) {
			wtf=rows[r];
			a1val = a1->Val(wtf, c);
			bm->Set(r, c, a1val);
		}
	}

	return bm;
}
//Returns a bitmatrix's inverse
Bitmatrix *Inverse(const Bitmatrix *m)
{
	(void) m;
	return NULL;
}


//intializies hash table size to the given sizen
BM_Hash::BM_Hash(int size)
{
 	if(size<=0) throw((string) "Bad size");
	Table.resize(size);
}
//stores key and bit matrix into hash table
//used a bool update to determine two cases, if the entry already exists and if it doesn't
bool BM_Hash::Store(const string &key, Bitmatrix *bm)
{
 	bool update = true;
	int hash;
	HTE *entry;

	hash = djb_hash(key) % Table.size();

	for (unsigned int j = 0; j < Table[hash].size(); j++) {
		if (Table[hash][j].key == key) {
			Table[hash][j].bm = bm;
			update = false;
			return true;
		}
	}

	if (update == true) {
		entry = new HTE;
		entry->key = key;
		entry->bm = bm;

		Table[hash].push_back(*entry);
		return true;
	} 
	return false;
	
}
//retrieves a bit matrix with the given key    
Bitmatrix *BM_Hash::Recall(const string &key) const
{
	int hash;

	hash = djb_hash(key) % Table.size();

	for (unsigned int j = 0; j < Table[hash].size(); j++) {
		if (Table[hash][j].key == key) return Table[hash][j].bm;
	}

	return NULL;	
}
//prints all of the hashtable entries      
vector <HTE> BM_Hash::All() const
{

	vector <HTE> rv;
	int rows, cols;
	for (unsigned int i = 0; i < Table.size(); i++) {
		for (unsigned int j = 0; j < Table[i].size(); j++) {
			rows = Table[i][j].bm->Rows();
			cols = Table[i][j].bm->Cols();
			printf("%-31s %2d X  %2d\n", Table[i][j].key.c_str(), rows, cols);
		}
	}	
	return rv;
}
