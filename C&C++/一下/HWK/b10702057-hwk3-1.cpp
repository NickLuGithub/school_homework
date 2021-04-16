// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk3-1.cpp
// Compiler：Dev C++
// Date：2019/04/03
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using  namespace std;

class Circle {
	private:
		double a, b, r, c, d;               //創建私有變數 
	public:
		Circle(double _a = 0, double _b = 0, double _r = 0, double _c = 0, double _d = 0){            //變更斯有變數 
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
		
		string equation() {               //圓方程式 
			ostringstream out;
			out << "( x - " << a << " )^2 + ( y - " << b <<" )^2 = ( " << c << " )^2";
			return out.str();
		}
		
		double area() {                   //計算圓面積 
			return r * r * 3.141596;
		}
		double circumference() {
			return r * 2 * 3.141596;      //計算圓周長 
		}
		string PintInOut() {              //判斷點是否在圓裡 
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
		double x_1() {                    //與X的第一個焦點 
			return sqrt(r * r - b * b) + a;
		}
		double x_2() {                    //與X的第二個焦點 
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
