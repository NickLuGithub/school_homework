// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex9.cpp
// Compiler�GDev C++
// Date�G2019/04/29
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

class Point{          //�I������ 
	private:
		double a, b;   
	public:
		Point(double _a = 0, double _b = 0){
			setPoint(_a, _b);
		}
		void setPoint(double _a, double _b){
			a = _a;
			b = _b;
		}
		
		double getA() { return a;}
		double getB() { return b;}
};

class Rectangle {  //����Ϊ��� 
	private:
		Point p;
		double w, h;
	public:
		Rectangle(Point _p, double _w, double _h){
			setRectangle(_p, _w, _h);
		}
		void setRectangle(Point _p, double _w, double _h){
			p = _p;
			w = _w;
			h = _h;
		}
		
		Point getP(){ return p;}
		double getW(){ return w;}
		double getH(){ return h;}
		
		double area(){ //���n 
			return w * h;
		}
		double perimeter(){ //�P�� 
			return (w + h) * 2;
		}
};

int main ( void ) {
	
	double a, b, w, h;
	
	cout << "Enter the rectangle (x, y), w, h: ";
	cin >> a >> b >> w >> h;
	Point p(a, b);
	Rectangle k(p, w, h);
	cout << "The rectangle has the left bottom point at (" << p.getA() << ", " << p.getB() 
		<< ") with the width " << k.getW() << " and the height " << k.getH() << ". \n";
	cout << "The area of the rectangle is " << k.area() << endl;
	cout << "The perimeter of the rectangle is " << k.perimeter() << endl;
}
