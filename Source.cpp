#include <iostream>
#include <fstream>
using namespace std;
class ratfraction {
public:

	int numerator;
	int denominator;
	ratfraction(int x, int y) {
		numerator = x;
		denominator = y;
	}
	
	void reduction(int numer, int denomer) {
		if (numer % 2 == 0 && denomer % 2 == 0) {
			
			numerator = numer / 2;
			denominator = denomer / 2;
		
		}
		else if (numer % 3 == 0 && denomer % 3 == 0) {
			
			numerator = numer / 3;
			denominator = denomer / 3;

		};
	};
	
	

};
class reader {
public:
	reader(string x) {
		ifstream f(x);
	}
};