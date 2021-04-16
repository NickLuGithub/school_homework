#include<iostream>
#include<sstream>

using namespace std;

class Complex {
private:
	double x, y;
public:
	Complex(double _x = 0, double _y = 0) {
		setComplex(_x, _y);
	}
	void setComplex(double _x, double _y) {
		x = _x;
		y = _y;
	}
	double getX() { return x; }
	double getY() { return y; }

	string str() {
		ostringstream out;
		out << "(" << x << " + " << y << "i)";
		return out.str();
	}
	Complex operator + (Complex b) {
		return Complex(getX() + b.getX(), getY() + b.getY());
	}
};

Complex operator - (Complex a, Complex b) {
	return Complex(a.getX() - b.getX(), a.getY() - b.getY());
}

int main(void) {
	char ch;
	double a, b, c, d;
	cout << "Enter 2 complex numbers (a, bi) (c + di): ";
	cin >> ch >> a >> ch >> b >> ch >> ch;
	cin >> ch >> c >> ch >> d >> ch >> ch;
	Complex ca(a, b), cb(c, d);
	cout << ca.str() << " + " << cb.str() << " = " << (ca + cb).str() << endl;
	cout << ca.str() << " - " << cb.str() << " = " << (ca - cb).str() << endl;
	system("pause");
}