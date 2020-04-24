#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class fraction {
public:

	int numerator;
	int denominator;
	fraction(int x, int y) {
		numerator = x;
		denominator = y;
	}
	fraction() {
		numerator = 0;
		denominator = 0;
	}
	
	void reduction() {
		if (numerator % 2 == 0 && denominator % 2 == 0) {
			
			numerator = numerator / 2;
			denominator = denominator / 2;
		
		}
		else if (numerator % 3 == 0 && denominator % 3 == 0) {
			
			numerator = numerator / 3;
			denominator = denominator / 3;

		};
	};
	
	fraction operator+(fraction);
	fraction operator-(fraction);
	fraction operator*(fraction);
	fraction operator/(fraction);
	bool operator==(fraction);
	bool operator!=(fraction);
	bool operator>(fraction);
	bool operator<(fraction);
	bool operator>=(fraction);
	bool operator<=(fraction);
};
fraction fraction::operator+(fraction a) {
	fraction temp;
	temp.numerator = temp.numerator + a.numerator;
	return temp;
};
fraction fraction::operator-(fraction a) {
	fraction temp;
	temp.numerator = temp.numerator - a.numerator;
	temp.denominator = a.denominator;
	return temp;

}
fraction fraction::operator*(fraction a){
	fraction temp;
	temp.numerator = temp.numerator*a.numerator;
	temp.denominator = temp.denominator*a.denominator;
	return temp;
}
fraction fraction::operator/(fraction a) {
	fraction temp;
	temp.numerator = temp.numerator*a.denominator;
	temp.denominator = temp.denominator*a.numerator;
	return temp;
}
bool fraction::operator==(fraction a) {
	fraction temp;
	if (temp.numerator == a.numerator&&temp.denominator == a.denominator) {
		return true;
	}
	else {return false;}
}
bool fraction::operator!=(fraction a) {
	fraction temp;
	if (temp.numerator != a.numerator||temp.denominator != a.denominator) {
		return true;
	}
	else { return false; }
}
bool fraction::operator>(fraction a) {
	fraction temp;
	if (temp.numerator > a.numerator&&temp.denominator > a.denominator) {
		return true;
	}
	else { return false; }
}
bool fraction::operator<(fraction a) {
	fraction temp;
	if (temp.numerator < a.numerator&&temp.denominator < a.denominator) {
		return true;
	}
	else { return false; }
}
bool fraction::operator>=(fraction a) {
	fraction temp;
	if (temp.numerator >= a.numerator&&temp.denominator >= a.denominator) {
		return true;
	}
	else { return false; }
}
bool fraction::operator<=(fraction a){
	fraction temp;
	if (temp.numerator <= a.numerator&&temp.denominator <= a.denominator) {
		return true;
	}
	else { return false; }
}



class reader {
public:
	string filename;
	ifstream file;
	reader(string x) {
		filename = x;
		file.open(x);
	}
	~reader() {
		file.close();
	};
	reader(const reader &c) { 
		filename = c.filename;
	}
	reader& operator=(const reader &p) {
		return *this;
	}
	reader(reader&& m) {
		filename = m.filename;	
	}
	reader& operator=(reader&& m) {
		return *this;
	}


};

int main() {

	reader example("list.csv");
	fraction f1;
	fraction f2;
	fraction final1;
	string signer("?");
	int signs;
	int pause;
	int check=0;
	do {
		example.file >> f1.numerator >> f1.denominator >> signer >> f2.numerator >> f2.denominator;
		if (signer == "+") {
			signs = 1;
		}
		else
			if (signer == "-") {
				signs = 2;
			}
			else
				if (signer == "*") {
					signs = 3;
				}
				else
					if (signer == "/") {
						signs = 4;
					}
					else
						if (signer == "==") {
							signs = 5;
						}
						else
							if (signer == "!=") {
								signs = 6;
							}
							else
								if (signer == ">") {
									signs = 7;
								}
								else
									if (signer == "<") {
										signs = 8;
									}
									else
										if (signer == ">=") {
											signs = 9;
										}
										else
											if (signer == "<=") {
												signs = 10;
											}
		do {
			if (f1.denominator < f2.denominator) {
				check = f2.denominator;
				f2.reduction();

			}
		} while (f1.denominator < f2.denominator || check == f2.denominator);
		switch (signs) {
		case 1:
			final1.numerator = f1.numerator + f2.numerator;
			final1.denominator = f1.denominator;
			do {
				check = final1.denominator;
				final1.reduction();
			} while (check != final1.denominator);
			cout << final1.numerator << endl << "-" << endl << final1.denominator << endl;
			break;
		case 2:
			final1.numerator = f1.numerator - f2.numerator;
			final1.denominator = f1.denominator;
			do {
				check = final1.denominator;
				final1.reduction();
			} while (check != final1.denominator);
			cout << final1.numerator << endl << "-" << endl << final1.denominator << endl;
			break;
		case 3:
			final1.numerator = f1.numerator*f2.numerator;
			final1.denominator = f1.denominator*f2.denominator;
			do {
				check = final1.denominator;
				final1.reduction();
			} while (check != final1.denominator);
			cout << final1.numerator << endl << "-" << endl << final1.denominator << endl;
			break;
		case 4:
			final1.numerator = f1.numerator*f2.denominator;
			final1.denominator = f1.denominator*f2.numerator;
			do {
				check = final1.denominator;
				final1.reduction();
			} while (check != final1.denominator);
			cout << final1.numerator << endl << "-" << endl << final1.denominator << endl;
			break;
		case 5:
			cout << f1.numerator << endl << "-" << endl << f1.denominator << endl;
			cout << f2.numerator << endl << "-" << endl << f2.denominator << endl;
			if (f1.numerator == f2.numerator&&f1.denominator == f2.denominator) {
				cout << "similar" << endl;
			}
			else {
				cout << "not similar" << endl;
			}
			break;
		case 6:
			cout << f1.numerator << endl << "-" << endl << f1.denominator << endl;
			cout << f2.numerator << endl << "-" << endl << f2.denominator << endl;
			if (f1.numerator != f2.numerator&&f1.denominator != f2.denominator) {
				cout << "not similar" << endl;
			}
			else {
				cout << "similar" << endl;
			}
			break;
		case 7:
			cout << f1.numerator << endl << "-" << endl << f1.denominator << endl;
			cout << f2.numerator << endl << "-" << endl << f2.denominator << endl;
			if (f1.numerator > f2.numerator&&f1.denominator > f2.denominator) {
				cout << "first is greater than second" << endl;
			}
			else {
				cout << "first is not greater than second" << endl;
			}
			break;
		case 8:
			cout << f1.numerator << endl << "-" << endl << f1.denominator << endl;
			cout << f2.numerator << endl << "-" << endl << f2.denominator << endl;
			if (f1.numerator < f2.numerator&&f1.denominator < f2.denominator) {
				cout << "first is less than second" << endl;
			}
			else {
				cout << "first is not less than second" << endl;
			}
			break;
		case 9:
			cout << f1.numerator << endl << "-" << endl << f1.denominator << endl;
			cout << f2.numerator << endl << "-" << endl << f2.denominator << endl;
			if (f1.numerator >= f2.numerator&&f1.denominator >= f2.denominator) {
				cout << "first is greater than or equal to second" << endl;
			}
			else {
				cout << "first is not great than or equal to second" << endl;
			}
			break;
		case 10:
			cout << f1.numerator << endl << "-" << endl << f1.denominator << endl;
			cout << f2.numerator << endl << "-" << endl << f2.denominator << endl;
			if (f1.numerator <= f2.numerator&&f1.denominator <= f2.denominator) {
				cout << "first is less than or equal to second" << endl;
			}
			else {
				cout << "first is not less than or equal to second" << endl;
			}
			break;
		}
		

		cin>>pause;
		cout<<endl;
		system("cls");
	} while (pause!=1);

	return 0;
}
