//Lab 1A
//COSC130
//Lab synopsis
//Dai'zjon Carney
//8/30/2018
#include <iostream>
#include <string>
using namespace std;

//Prototypes for the functions that you will write
int CharToInt(char v);
char IntToChar(int v);
int  CharToInt(char v){
	return v - '0';
}
char IntToChar(int v){
	return v + '0';
}
int StringToInt(string val);
string IntToString(int val);


// this whole function checks if the int val is 0 or below. if it's not goes into a while loop that converts to string. if original value was negative, places negative sign before string
string IntToString(int val){
	int fun = 0, son= val;
	string buy = "";
	if (val<0) { 
		val*= -1;
	}
	if(val ==0){
		buy = "0";
	}

	while(val!=0) {
		fun = (val %10);
		buy= IntToChar(fun) +buy;
			val/=10;
	}
	if(son<0) {
		buy="-"+buy;
	}
	return buy;
}
int StringToInt(string val){
// set varibles used val.length to get numerical value of items in the char array
int valut=0,numb=1,totallength= val.length(),sub=0;
//erased value to not skew data
	if((val[0])== ('-')){
			sub +=1;
			val.erase(val[0]);
				}
//used a for loop to return the char array value at certain points
		for(int j = totallength - 1; j>=0; j--){

		valut+= CharToInt(val[j])*numb;
		numb*=10;
		}
	if(sub==1){
	valut*=-1;
	}
	return valut;
}
	



int main(int argc, char *argv[])
{
        string sresult;
        int left;
        int right;
        char op;

        if (4 != argc) {
                printf("Usage: %s <left> <op> <right>\n", argv[0]);
                return -1;
        }
        //Notice that this calls your StringToInt. So, make sure you debug
        //StringToInt() to make sure that left and right get a proper
        //value.
        left = StringToInt(argv[1]);
        right = StringToInt(argv[3]);
        op = argv[2][0];
        //Calculate based on the op. Notice that this calls IntToString,
        //so debug your IntToString() function to make sure that sresult
        //is given the proper result. This assumes your StringToInt already
        //works.
        switch (op)
        {
                case 'x':
                        sresult = IntToString(left * right);
                        break;
                case '/':
                        sresult = IntToString(left / right);
                        break;
                case '+':
                        sresult = IntToString(left + right);
                        break;
                case '-':
                        sresult = IntToString(left - right);
                        break;
                case '%':
                        sresult = IntToString(left % right);
                        break;
                default:
                        sresult = IntToString(left);
                        break;
        }

        //Remember, printf is the only output function you may use for this lab!
        //The format string is %d %c %d = %s. This means that the first argument
        //is %d (decimal / integer), %c (character), %d (decimal /integer),
        //%s (string). Notice that because printf() is a C-style function, you
        //must pass strings as character arrays. We can convert a C++ string
        //to a character array (C-style string) by using the c_str() member function.
        printf("%d %c %d = %s\n", left, op, right, sresult.c_str());
        return 0; 
}
