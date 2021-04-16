#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;

typedef struct{
	double x, y;
} Point;

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
};

void line_two(Line l1, Line l2){
	if( l1.getA() / l2.getA() == l1.getB() / l2.getB() && l1.getB() / l2.getB() == l1.getC() / l2.getC()){
		cout << "The intersection of " << l1.str() << " and " << l2.str() << " is (inf, inf)" << endl;
	}else if(l1.getA() / l2.getA() != l1.getB() / l2.getB() && l1.getB() / l2.getB() != l1.getC() / l2.getC() && l2.getB()){
		cout << "The intersection of " << l1.str() << " and " << l2.str() << " is (-inf, -inf)" << endl;
	}else{
		cout << "The intersection of " << l1.str() << " and " << l2.str() << " is (" << ((l1.getC() * l2.getB())- (l1.getB() * l2.getC())) / ((l1.getA() * l2.getB()) - (l1.getB() * l2.getA())) << ", " << ((l1.getA() * l2.getC()) - (l1.getC() * l2.getA())) / ((l1.getA() * l2.getB()) - (l1.getB() * l2.getA())) << ")" << endl;
	}
}

string operator * (Line a, Point k){
	ostringstream out;
	if (a.getA() * a.getB() > 0) out << "The line perpendicular to " << a.getA() << "x + " << a.getB() << "y = " << a.getC() << " and passing(" << k.x << ", " << k.y << ") is " << a.getB() << "x - " << a.getA() << "y = " << (a.getB() * k.x - a.getA() * k.y) << endl;
	else out << "The no line perpendicular to " << a.getA() << "x + " << a.getB() << "y = " << a.getC() << " and passing is (" << k.x << ", " << k.y << ")"<< endl;
	return out.str();
}

int main ( void ){
	double a, b, c, d, e, f, x, y;
	Point p;
	cout << "Enter ax + by = c, dx + ey = f, and Point(x, y):";
	cin >> a >> b >> c >> d >> e >> f >> p.x >> p.y;
	Line l1(a, b, c), l2(d, e, f);
	cout << l1 * p << l2 * p;
	line_two(l1, l2);
}
