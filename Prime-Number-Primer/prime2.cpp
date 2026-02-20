#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> //to use sqrt function and make it simpler than prime1
using namespace std;

class isprime {
	public:
		isprime() {v.push_back(2);}
		bool operator()(int);
	private:
//vector v stores a list of all previous prime numbers.
		vector<int> v;
		void grow(int);
};

// checks if a number is prime by checking v
bool isprime::operator()(int num) {
//If the number being checked is greater than this largest prime in v, the grow function is called
	if (num > v.back()) {
	grow(num);
	}
//determines whether or not the number is in the list of primes.
	vector<int>::iterator look = find(v.begin(), v.end(), num);
	if (look == v.end()) {
		return false;
	}	
	return true;
}

//expands the list of primes to include all primes up to the prime  whose value is greater than or equal to N.
void isprime::grow(int n) {
	bool prime = false;
	int num = v.back() + 1;
// loop goes through every number
	while (!prime || num < n) {
		prime = true;
//shows whether or not the current value of num is prime
		for (int i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) {
				prime = false;
				break;
			}
		}	
//If current number is prime it's added to v.

		if (prime) {
			v.push_back(num);
		}
		num++;
	}
}

int main() {
	isprime p;
	int num;

//checks if prime number after each user input
	while (cin >> num) {
		if (p(num)) {
		cout << num << " is a prime number" << endl;
		}
	}
return 0;
}
