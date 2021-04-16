#include<iostream>
#include<cmath>
using namespace std;

class Point {
	private:
		double x, y;
	public:
	Point(double _x = 0, double _y = 0) {
		setPoint(_x, _y);
	}
	void setPoint(double _x = 0, double _y = 0) {
		x = _x;
		y = _y;
	}
	double getX() { return x; }
	double getY() { return y; }
};

double dist(Point a, Point b) {
	return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

class Triangle {
	private :
		Point a, b, c;
	public:
		Triangle (Point _a, Point _b, Point _c) {
			setTriangle(_a, _b, _c);
		}
		void setTriangle(Point _a, Point _b, Point _c) {
			a = _a;
			b = _b;
			c = _c;
		}
		Point getA() { return a; }
		Point getB() { return b; }
		Point getC() { return c; }
};

double triangle_area(Triangle t) {
	double a = dist(t.getA(), t.getB()), b = dist(t.getB() , t.getC()), c = dist(t.getA(), t.getC());
	if ( a + b > c && a + c > b && b + c > a) {
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	} else return 0;
}

int main ( void ) {
	double x1, y1, x2, y2, x3, y3;
	cout << "Enter 3 point:";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point a(x1, y1), b(x2, y2), c(x3, y3);
	Triangle t(a, b, c);
	double area = triangle_area(t);
	if ( area > 0) cout << "The triangle area is " << area;
	else cout << "The triangle cannot be formed.\n"; 
}
