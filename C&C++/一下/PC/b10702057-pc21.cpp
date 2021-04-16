#include<iostream>
#include<sstream>
using namespace std;

class Line {
private:
	double a, b, c;
public:
	Line(double _a = 0, double _b = 0, double _c = 0) {
		setLine(_a, _b, _c);
	}
	void setLine(double _a = 0, double _b = 0, double _c = 0) {
		a = _a;
		b = _b;
		c = _c;
	}
	double getA() { return a; }
	double getB() { return b; }
	double getC() { return c; }
	
	string str(){
		ostringstream out;
		out << a << "x + " << b << "y = " << c;
		return out.str(); 
	}
	double area() {
		if (a * b * c != 0) return 0.5 * c/a * c/b;
		return 0;
	}
};  

int main ( void ){
	double a ,b, c;
	cout << "Enter ax + by = c:";
	cin >> a >> b >> c;
	Line leq(a, b, c);
	double area = leq.area();
	if (area > 0) cout << "The triangle area formed by " << leq.str() << ", X-axis, and Y-asis is " << area << endl;
}
