// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex13.cpp
// Compiler�GDev C++
// Date�G2019/06/10
#include<iostream>
#include<sstream>
using namespace std;

class line {
private:
	double a, b, c;
public:
	line(double _a, double _b, double _c){
		setline(_a, _b, _c);
	}
	void setline(double _a, double _b, double _c){
		a = _a;
		b = _b;
		c = _c;
	}
	double getA() {return a;}
	double getB() {return b;}
	double getC() {return c;}
	
	string str(){           //��{�� 
		ostringstream out;
		out << a << " x + "<< b << "y = " << c ;
		return out.str();
	}
	
	string YesOrNo(){       //�P�_ 
		ostringstream out;
		if((int)b % (int)c == 0){
			out << " is vertical to the x-axis." << endl;
		}
		else if ((int)a % (int)c == 0){
			out << " is parallel to the x-axis." << endl;
		}else{
			out << " is neither parallel nor vertical to the x-axis." << endl;
		}
		return out.str();
	}
};

int main ( void ){
	double a, b, c;
	cout << "Enter ax + by = c: ";
	cin >> a >> b >> c;
	line in(a, b, c);
	cout << in.str() << in.YesOrNo();
}
