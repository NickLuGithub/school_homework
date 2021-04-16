// Student No.：B10702057  Name：盧昱達 
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;


typedef struct {      //創意點的結構 
	double x, y;
} Point;

typedef struct {
	double a, b, c;
} LineABC;

double line(Point g, Point k){                    //計算兩點距離 
	return sqrt(pow(g.x - k.x, 2) + pow(g.y - k.y, 2));
}

double area(double a, double b, double c){   //計算三點圍成的面積 
	double s = ( a + b + c ) / 2;
	return sqrt( s * ( s - a ) * ( s - b ) * ( s - c ));
}
double area_A(LineABC a){ 
	return area(a.a, a.b, a.c);
}
double perimeter_A(LineABC a) {
	return a.a + a.b + a.c;
}

void PointInOut(Point a, Point b, Point c, Point r) {         //判斷點是否在三角形裡並扣除誤差值 
	double k = area(line(a, b), line(a, r), line(b, r));
	double q = area(line(b, c), line(b, r), line(c, r));
	double e = area(line(a, c), line(c, r), line(a, r));
	if ( fabs((k + q + e) - area(line(a, b), line(b, c), line(a, c))) < 0.000001 ){
		cout << "is inside the triangle.";
	}
	else{
		cout <<  "is outside the triangle.";
	}
}

/*class Line{
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
		double perimeter_A() { return line_A() + line_B() + line_C();}
		
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
};*/

void line_passing(Point a, Point b){
	printf("The line passing (%.2lf, %.2lf) and (%.2lf, %.2lf) is (%.2lf)x + (%.2lf)y = %.2lf\n", a.x, a.y, b.x, b.y, a.y - b.y, b.x - a.x, a.y * b.x - a.x * b.y);
}

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
	
	LineABC aser;
	aser.a = line(k, q);
	aser.b = line(q, w);
	aser.c = line(k, w);
	
	if ( aser.a + aser.b > aser.c && aser.b + aser.c > aser.a && aser.a + aser.c > aser.b){
		line_passing(k, q);
		line_passing(k, w);
		line_passing(q, w);
		printf("The perimeter of the triangle is %.2lf\n", perimeter_A(aser));
		printf("The area of the triangle is %.2lf.\n", area_A(aser));
		cout << "(" << r.x << ", " << r.y << ")" ;
		PointInOut(k, q, w, r);
		cout << endl;
	}
	else{
		printf("The triangle cannot be formed.\n");
	}
}
