// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk3-2.cpp
// Compiler：Dev C++
// Date：2019/04/03
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;
/*
class Point {
	private:
		double x, y;               //創建私有變數 
	public:
		Point(double _x = 0, double _y = 0){            //變更斯有變數 
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
//這不知為何不能在第二個class呼叫第一個class來用 

typedef struct {      //創意點的結構 
	double x, y;
} Point;

class Line{
	private:
		Point a, b, c, r; //創建私有變數 
	public:
		Line(Point _a, Point _b, Point _c, Point _r){//變更斯有變數 
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
		
		
		double line(Point g, Point k){                    //計算兩點距離 
			return sqrt(pow(g.x - k.x, 2) + pow(g.y - k.y, 2));
		}

		double line_A() { return line(a, b);}
		double line_B() { return line(b, c);}
		double line_C() { return line(a, c);}
			
		double area(double a, double b, double c){   //計算三點圍成的面積 
			double s = ( a + b + c ) / 2;
			return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ));
		}
		
		double area_A() { area(line_A(), line_B(), line_C());}
		
		string PointInOut() {         //判斷點是否在三角形裡並扣除誤差值 
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
	Point k, q, w, r;           //設定點 
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
