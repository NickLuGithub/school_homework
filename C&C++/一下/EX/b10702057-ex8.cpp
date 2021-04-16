// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex8.cpp
// Compiler�GDev C++
// Date�G2019/04/25
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using  namespace std;

class Vector {
	private:
		double a, b, c;               //�Ыبp���ܼ� 
	public:
		Vector(double _a = 0, double _b = 0, double _c = 0){            //�ܧ󴵦��ܼ� 
			setVector(_a, _b, _c);
		}
		void setVector(double _a = 0, double _b = 0, double _c = 0){
			a = _a;
			b = _b;
			c = _c;
		}
		double getA() { return a;}
		double getB() { return b;}
		double getC() { return c;}
		
		string strA(Vector a) {  //��X�V�q 
			ostringstream out;
			out << "(" << a.a << ", " << a.b << ", " << a.c << ")";
			return out.str();
		}
		Vector sum( Vector a, Vector b) {  //�ۥ[ 
			Vector c;
			c.a = a.a + b.a;
			c.b = a.b + b.b;
			c.c = a.c + b.c;
			return c;
		}
		
		string YN(Vector a, Vector b) {  //�P�_�O�_�ۦP 
			ostringstream out;
			
			if ( a.a == 0 && b.a == 0 && a.b == 0 && b.b == 0){
				out << " == ";
			}
			else if ( a.b == 0 && b.b == 0 && a.c == 0 && b.c == 0){
				out << " == ";
			}
			else if ( a.a == 0 && b.a == 0 && a.c == 0 && b.c == 0){
				out << " == ";
			}
			
			else if ( a.a == 0 && b.a == 0 && a.b / b.b == a.c / b.c){
				out << " == ";
			}
			else if ( a.b == 0 && b.b == 0 && a.a / b.a == a.c / b.c){
				out << " == ";
			}
			else if ( a.c == 0 && b.c == 0 && a.a / b.a == a.b / b.b){
				out << " == ";
			}
			
			else if ( a.a / b.a == a.b / b.b && a.b / b.b == a.c / b.c ){
				out << " == ";
			}
			
			else {
				out << " != ";
			}
			return out.str();
		}
		
		double internal (Vector a, Vector b){  //���� 
			return a.a * b.a + a.b * b.b + a.c * a.c;
		}
};

int main ( void ){
	double x, y, z;
	
	cout << "Enter first vector: ";
	cin >> x >> y >> z;
	Vector a(x, y, z);
	cout << "Enter second vector: ";
	cin >> x >> y >> z;
	Vector b(x, y, z);
	Vector c;
	cout << a.strA(a) << a.YN(a, b) << b.strA(b) << endl;
	cout << "The sum vector is " << c.strA(a.sum(a, b)) << endl;
	cout << "The internal product is " << a.internal(a, b) << endl;
}
