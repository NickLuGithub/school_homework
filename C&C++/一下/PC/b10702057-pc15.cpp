// Student No.¡GB10702057  Name¡G¿c¬R¹F 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

class Vector{
	private:
		double x, y, z;
	public:
		Vector(double _x = 0, double _y = 0, double _z = 0){
			setVector(_x, _y, _z);
		}
		void setVector(double _x, double _y, double _z){
			x = _x;
			y = _y;
			z = _z;
		}
		double getX(){return x;}
		double getY(){return y;}
		double getZ(){return z;}
		
		string str(){
			ostringstream out;
			out << "(" << x << ", " << y << ", " << z << ")";
			return out.str();
		}
};

Vector add (Vector a, Vector b){
	return Vector(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
}
Vector operator + (Vector a, Vector b) {
	return Vector(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
}

double inner_product (Vector a, Vector b){
	return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

double operator * (Vector a, Vector b){
	return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

int main (void) {
	double x1, x2, y1, y2, z1, z2;
	cout << "Enter two vectors (x, y, z): " << endl;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 ;
	Vector a(x1, y1, z1), b(x2, y2, z2), c;
	c = add(a, b);
	cout << a.str() << " + " << b.str() << " = " << c.str() << endl; 
	cout << a.str() << " + " << b.str() << " = " << add(a, b).str() << endl;
	c = a + b;
	cout << a.str() << " + " << b.str() << " = " << c.str() << endl;
	cout << a.str() << " + " << b.str() << " = " << (a + b).str() << endl;
	cout << a.str() << " . " << b.str() << " = " << inner_product(a, b) << endl;
	cout << a.str() << " . " << b.str() << " = " << (a * b) << endl;
}
