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

int main ( void ) {
	double x1, y1, x2, y2;
	cout << "Enter 2 point:";
	cin >> x1 >> y1 >> x2 >> y2;
	Point a(x1, y1), b(x2, y2);
	cout << "The distance between (" << a.getX() << ", " << a.getY() << ") and "
		 << "(" << b.getX() << ", " << b.getY() << ") is " << dist(a, b) << ".\n";
}
