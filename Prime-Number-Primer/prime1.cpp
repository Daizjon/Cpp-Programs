#include <iostream>
#include <cstdio>
using namespace std;

bool isprime(int x){
	int c;
	 for ( c = 2 ; c <= x - 1 ; c++ )
   { 
      if ( x%c == 0 )
     return 0;
   }
   return 1;

}

int main (){
	int x=0;
	while(cin>>x){
		if(isprime(x)==1){
			if((x!=1)&(x!=0)){cout<< x << " is a prime number"<<endl;}
		}

	}


return 0;
}
