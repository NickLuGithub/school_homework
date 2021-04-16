#include<iostream>
#include<sstream>
using namespace std;

class Fraction{
private:
	int n, d;
public:
	Fraction(int _n = 0, int _d = 1){
		setFraction(_n, _d);
	}
	void setFraction(int _n, int _d){
		n = _n;
		d = _d;
	}
	int getN(){return n;}
	int getD(){return d;}
	string str(){
		ostringstream out;
		out << n << "/" << d;
		return out.str();
	}
};

Fraction operator + (Fraction a, Fraction b){
	return Fraction(a.getN() * b.getD() + a.getD() * b.getN(), a.getD() * b.getN());
}

int main( void ){
	int a, b, c, d;
	char sh;
	cout << "Enter 2 fractions";
	cin >> a >> sh >> b >> c >> sh >> d;
	Fraction fa(a, b), fb(c, d);
	cout << fa.str() << " + " << fb.str() << " = " << (fa + fb).str() << endl; 
}
