//Dai'zjon Carney
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
//input
	int x=0;
//outputs
	int read=0;
	int sum=0;
	int min=0;
	int max=0;
//read values from input and then output the needed values
	while(cin>>x){
		sum+=x;
		read++;
		if (read ==1){
			min=x;
			max=x;
		}
		else {
			if (min>x) {
				min=x;
			}
			if (max<x) {
				max=x;
			}
		}
	}
	cout<<"N = "<<read<<endl;
	cout<<"sum = "<<sum<<endl;
	cout<<"min = "<<min<<endl;
	cout<<"max = "<<max<<endl;
return 0;
}
