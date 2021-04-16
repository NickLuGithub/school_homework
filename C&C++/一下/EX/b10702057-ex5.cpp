// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex5.cpp
// Compiler：Dev C++
// Date：2019/04/01
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<math.h>
using namespace std;

class LE {  //LE == LineEquation
	private :
		double a, b, c; //私有變數 
	public :
		LE(double _a = 0, double _b = 0, double _c = 0) {        //變更私有變數 
			setLE(_a, _b, _c);
		}
		void setLE(double _a = 0, double _b = 0, double _c = 0){
			a = _a;
			b = _b;
			c = _c;
		}
	double getA() {
		return a;
	}
	double getB() {
		return b;
	}
	double getC() {
		return c;
	}
	string str() {                        //列印式子函數 
		ostringstream out;
		out << a << "x + " << b << "y = " << c;
		return out.str();
	}
	double are() {                    //計算面積 
		return ( c / a ) * ( c / b ) * 0.5;
	}
	double LinePoint() {              //計算點到直線距離 
		return fabs(c) / sqrt(pow(a, 2) + pow(b, 2));
	}
};

int main ( void ) {
	double a, b, c;
	cout << "Enter ax + by = c (a, b, c)\n";
	cin >> a >> b >> c;
	LE k(a, b, c);
	cout << k.str() << endl;
	printf("The area formed by %.2lfx + %.2lfy = %.2lf, x-axis, and y-axis is %.2lf\n", a, b, c, k.are());
	// == cout << "The area formed by " << k.str() << ", x-axis, and y-axis is " << k.are() << endl;
	printf("The distance from (0.00, 0.00) to %.2lfx + %.2lfy = %.2lf is %.2lf.\n", a, b, c, k.LinePoint());
	// == cout << "The distance from (0.00, 0.00) to " << k.str() << " is " << k.LinePoint() << endl;
}
