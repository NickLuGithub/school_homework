// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk3-1.cpp
// Compiler�GDev C++
// Date�G2019/04/03
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using  namespace std;

class Circle {
	private:
		double a, b, r, c, d;               //�Ыبp���ܼ� 
	public:
		Circle(double _a = 0, double _b = 0, double _r = 0, double _c = 0, double _d = 0){            //�ܧ󴵦��ܼ� 
			setCircle(_a, _b, _r, _c, _d);
		}
		void setCircle(double _a = 0, double _b = 0, double _r = 0, double _c = 0, double _d = 0){
			a = _a;
			b = _b;
			r = _r;
			c = _c;
			d = _d;
		}
		double getA() { return a;}
		double getB() { return b;}
		double getR() { return r;}
		double getC() { return c;}
		double getD() { return d;}
		
		string equation() {               //���{�� 
			ostringstream out;
			out << "( x - " << a << " )^2 + ( y - " << b <<" )^2 = ( " << c << " )^2";
			return out.str();
		}
		
		double area() {                   //�p��ꭱ�n 
			return r * r * 3.141596;
		}
		double circumference() {
			return r * 2 * 3.141596;      //�p���P�� 
		}
		string PintInOut() {              //�P�_�I�O�_�b��� 
			ostringstream out;
			if ( sqrt(pow((a - c), 2) + pow((b - d), 2)) <= r * r){
				out << "Ture";
				return out.str();
			}
			else {
				out << "Flase";
				return out.str();
			}
		}
		double x_1() {                    //�PX���Ĥ@�ӵJ�I 
			return sqrt(r * r - b * b) + a;
		}
		double x_2() {                    //�PX���ĤG�ӵJ�I 
			return -1 * sqrt(r * r - b * b) + a;
		}
};

int main ( void ) {
	double a, b, r, c, d;
	
	cout << "Enter the equation of (x - a)^2 + (y - b)^2 = r^2 and a point (c, d)  (a, b, r, c, d): ";
	cin >> a >> b >> r >> c >> d;
	Circle k(a, b, r, c, d);
	cout << "The circle equation is " << k.equation() << endl;
	cout << "The area of the circle is " << k.area() << endl;
	cout << "The circumference of the circle is " << k.circumference() << endl;
	cout << "(" << c << ", " << d << ") is the point inside ? " << k.PintInOut() << endl;
	cout << "The intersection points are (" << k.x_1() << ", 0) and (" << k.x_2() <<", 0)" << endl;
}
