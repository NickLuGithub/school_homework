// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex5.cpp
// Compiler�GDev C++
// Date�G2019/04/01
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<math.h>
using namespace std;

class LE {  //LE == LineEquation
	private :
		double a, b, c; //�p���ܼ� 
	public :
		LE(double _a = 0, double _b = 0, double _c = 0) {        //�ܧ�p���ܼ� 
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
	string str() {                        //�C�L���l��� 
		ostringstream out;
		out << a << "x + " << b << "y = " << c;
		return out.str();
	}
	double are() {                    //�p�⭱�n 
		return ( c / a ) * ( c / b ) * 0.5;
	}
	double LinePoint() {              //�p���I�쪽�u�Z�� 
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
