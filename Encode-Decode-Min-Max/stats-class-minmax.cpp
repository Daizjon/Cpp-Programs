//Dai'zjon Carney
#include <iostream>
#include <cstdio>
using namespace std;

class stats {
	public:
	int x=0;
	int read=0;
	int min=0;
	int max=0;
	int sum=0;
	void push(int z){
		x=z;
		read++;
		sum+=x;
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

	void print(){
		cout<<"N = "<<read<<endl;
    	cout<<"sum = "<<sum<<endl;
    	cout<<"min = "<<min<<endl;
    	cout<<"max = "<<max<<endl;
	}
};
int main() {
	stats op;
	int i;
	while (cin>>i){
		op.push(i);
	}
	op.print();

return 0;
}
