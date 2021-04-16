// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex10.cpp
// Compiler�GDev C++
// Date�G2019/05/06

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<sstream>

using namespace std;

class Line {
	private:
		double a, b, c; // ax + by = c
	public:
		Line(double _a = 0, double _b = 0, double _c = 0) {             
			setLine(_a, _b, _c);
	}
	void setLine(double _a, double _b, double _c){
		a = _a;
		b = _b;
		c = _c;
	}
	double getA(){return a;}
	double getB(){return b;}
	double getC(){return c;}
	
	string Line_print(){     //�u��{�� 
		ostringstream out;
		out << "(" << a << "x + " << b << "y = " << c << ")";
		return out.str();
	}
};

void operator * (Line a, Line b) {
	if (a.getA() / b.getA() == a.getB() / b.getB() && a.getB() / b.getB() != a.getC() / b.getC()){  // ���� 
		cout << a.Line_print() << " and "<< b.Line_print() << " overlap.\n"; 		
	}
	else if (a.getA() / b.getA() == a.getB() / b.getB() && a.getB() / b.getB() == a.getC() / b.getC()){ // ���| 
		cout << a.Line_print() << " and "<< b.Line_print() << " parallel.\n";
	}
	else { // �J�I 
		cout << "The intersection of " << a.Line_print() << " and " << b.Line_print() << " is (" << (a.getC() * b.getB() - a.getB() * b.getC()) / (a.getA() * b.getB() - a.getB() * b.getA()) << " ," <<  (a.getA() * b.getC() - a.getC() * b.getA()) / (a.getA() * b.getB() - a.getB() * b.getA())<< ")\n";
	}
}

int main ( void ){
	double a, b, c, d, e, f;
	cout << "ax + by = c, dx + ey = f: ";
	cin >> a >> b >> c >> d >> e >> f;
	Line la(a, b, c), lb(d, e, f);
	la * lb;
}
