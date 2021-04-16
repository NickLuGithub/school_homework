#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point(double _x = 0, double _y = 0){
		setPoint(_x, _y);
	}
	void setPoint(double _x = 0, double _y = 0){
		x = _x;
		y = _y;
	}
	double getX(){return x;}
	double getY(){return y;}
	
	string str(){
		ostringstream out;
		out << "(" << x << ", " << y << ")";
		return out.str();
	}
	
	double line() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}
};

class PointSet {
private:
	Point *p;
	int n;
public:
	PointSet(int _n){
		n = _n;
		p = new Point[n];
	}
	void setPointSet(Point *_p, int n){
		for ( int i = 0; i < n; i++) p[i] = _p[i];
	}
	
	string str() {
		ostringstream out;
		out << "{";
		for ( int i = 0; i < n - 1; i++) {
			out << "(" << p[i].getX() << ", " << p[i].getY() << "), ";
		}
		out << "(" << p[n - 1].getX() << ", " << p[n - 1].getY() << ")}";
		return out.str();
	}
	
	Point min(){
		double t = p[0].line();
		Point k;
		for ( int i = 1; i < n; i++){
			if (p[i].line() < t ){
				k = p[i];
			}
		}
		return k;
	}
};

int main ( void ){
	int n;
	cout << "Enter n: ";
	cin >> n;
	Point *p = new Point[n];
	cout << "Enter " << n << " points: ";
	for (int i = 0; i < n; i++){
		double x, y;
		cin >> x >> y;
		p[i].setPoint(x, y);
	}
	PointSet in(n);
	in.setPointSet(p, n);
	cout << in.str() << endl;
	cout << in.min().str() << "is the farest point from (0.0000, 0.0000) and the distance is " << in.min().line() << endl;
}
