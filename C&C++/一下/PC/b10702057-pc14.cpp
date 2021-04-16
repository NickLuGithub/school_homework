// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc14.cpp
// Compiler¡GDev C++
// Date¡G2019/04/29
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

typedef struct { 
	double x, y;
} Point;

class Line{
	private:
		Point a, b;
	public:
		Line(Point _a, Point _b){
			setLine(_a, _b);
		}
		
		void setLine(Point _a, Point _b){
			a = _a;
			b = _b;
		}
		Point getA() { return a;}
		Point getB() { return b;}
		
		string equation() {         
			ostringstream out;
			double A = a.x, B = a.y, C = b.x, D = b.y;
			out << (B - D) << "x + " << (C - A) << "y = " <<(B * C - A * D);
			return out.str();
		}
};

double distance(Point p, Line l){
	double a = l.getA().x, b = l.getA().y, c = l.getB().x, d = l.getB().y;
	double A = b - d, B = c - a, C = b * c - a * d;
	return fabs(p.x * A + p.y * b - c) / sqrt(A * A + B * B);
}
int main ( void ) {
	Point a, b;
	
	cout << "Enter two points: ";
	cin >> a.x >> a.y >> b.x >> b.y;
	Line l(a, b);
	cout << "The line equation is " << l.equation() << endl;
	cout << "Enter a point: ";
	cin >> a.x >> a.y;
	cout << "he distance from (" << a.x <<", " << a.y << ") is " << distance(a, l) << endl;                                               
}
