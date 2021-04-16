// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk3-2.cpp
// Compiler�GDev C++
// Date�G2019/04/03
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;
/*
class Point {
	private:
		double x, y;               //�Ыبp���ܼ� 
	public:
		Point(double _x = 0, double _y = 0){            //�ܧ󴵦��ܼ� 
			setPoint(_x, _y);
		}
		void setPoint(double _x = 0, double _y = 0){
			x = _x;
			y = _y;
		}
		double getX() { return x;}
		double getY() { return y;}
};
*/
//�o�������󤣯�b�ĤG��class�I�s�Ĥ@��class�ӥ� 

typedef struct {      //�зN�I�����c 
	double x, y;
} Point;

class Line{
	private:
		Point a, b, c, r; //�Ыبp���ܼ� 
	public:
		Line(Point _a, Point _b, Point _c, Point _r){//�ܧ󴵦��ܼ� 
			setLine(_a, _b, _c, _r);
		}
		
		void setLine(Point _a, Point _b, Point _c, Point _r){
			a = _a;
			b = _b;
			c = _c;
			r = _r;
		}
		Point getA() { return a;}
		Point getB() { return b;}
		Point getC() { return c;}
		Point getR() { return r;}
		
		
		double line(Point g, Point k){                    //�p����I�Z�� 
			return sqrt(pow(g.x - k.x, 2) + pow(g.y - k.y, 2));
		}

		double line_A() { return line(a, b);}
		double line_B() { return line(b, c);}
		double line_C() { return line(a, c);}
			
		double area(double a, double b, double c){   //�p��T�I�򦨪����n 
			double s = ( a + b + c ) / 2;
			return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ));
		}
		
		double area_A() { area(line_A(), line_B(), line_C());}
		
		string PointInOut() {         //�P�_�I�O�_�b�T���θ̨æ����~�t�� 
			ostringstream out;
			double k = area(line_A(), line(a, r), line(b, r));
			double q = area(line_B(), line(b, r), line(c, r));
			double e = area(line_C(), line(c, r), line(a, r));
			if ( fabs((k + q + e) - area(line_A(), line_B(), line_C())) < 0.000001 ){
				out << "is inside the triangle.";
			}
			else{
				out <<  "is outside the triangle.";
			}
			return out.str();
		}
};
int main ( void ) {
	double a, b, c, d, e ,f;
	double i, l;
	cout << "Enter 3 points: ";
	cin >> a >> b >> c >> d >> e >> f;
	cout << "Enter the point: ";
	cin >> i >> l;
	Point k, q, w, r;           //�]�w�I 
	k.x = a; k.y = b;
	q.x = c; q.y = d;
	w.x = e; w.y = f;
	r.x = i; r.y = l;
	Line s(k, q, w, r);
	if ( s.line_A() + s.line_B() > s.line_C() && s.line_B() + s.line_C() > s.line_A() && s.line_A() + s.line_C() > s.line_B()){
		printf("The triangle area formed by (%.2lf, %.2lf), (%.2lf, %.2lf), and (%.2lf, %.2lf) is  %.2lf.\n", k.x, k.y, q.x, q.y, w.x, w.y, s.area_A());
		cout << "(" << r.x << ", " << r.y << ")" << s.PointInOut() << endl;
	}
	else{
		printf("The triangle cannot be formed.\n");
	}
}
