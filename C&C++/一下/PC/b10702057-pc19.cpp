#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
class Point {
private:
	double x, y;
public:
	Point (double _x = 0, double _y = 0) {
		setPoint(_x, _y);
	}
	void setPoint(double _x = 0, double _y = 0) {
		x = _x;
		y = _y;
   }
   double getX() { return x; }
   double getY() { return y; }
   string str() {
   	 ostringstream out;
   	 out << "(" << x << ", " << y << ")";
   	 return out.str();
   }
};
double dist(Point a, Point b) {
  return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}
class Polygon {
protected:
  Point *p;
  int n;
public:
  Polygon(int _n = 3) {
  	n = _n;
  	p = new Point[n];
  }
  void setPolygon(Point *pa) {
  	for (int i = 0; i < n; i++) p[i] = pa[i];
  }
  Point getPoint(int i) {
  	return p[i];
  }
   string str() {
   	 ostringstream out;
   	 for (int i = 0; i < n; i++) cout << p[i].str() << " ";
   	 return out.str();
   }
   virtual double area() { return 0; }
};

class Triangle : public Polygon {
public:
	Triangle (Point a, Point b, Point c) : Polygon(3) {
		setTriangle(a, b, c);
	}
	void setTriangle(Point a, Point b, Point c){
		p[0] = a;
		p[1] = b;
		p[2] = c;
	}
	Point getA() {return getPoint(0);}
	Point getB() {return getPoint(1);}
	Point getC() {return getPoint(2);}
	
	double area(){
		double a = dist(p[0], p[1]), b = dist(p[1], p[2]), c = dist(p[2], p[0]);
		if (a + b > c && b + c > a && c + a > b){
			double s = (a + b + c) / 2;
			return sqrt(s * (s - a) * (s - b) * (s - c));
		} else return 0;
	}
};

class ConvexQuaderilateral : public Polygon {
public:
	ConvexQuaderilateral (Point a, Point b, Point c, Point d) : Polygon(4) {
		setConvexQuaderilateral(a, b, c, d);
	}
	void setConvexQuaderilateral(Point a, Point b, Point c, Point d){
		p[0] = a;
		p[1] = b;
		p[2] = c;
		p[3] = d;
	}
	Point getA() {return getPoint(0);}
	Point getB() {return getPoint(1);}
	Point getC() {return getPoint(2);}
	Point getD() {return getPoint(3);}
	
	double triangle_area(double a, double b, double c){
		if(a + b > c && b + c > a && c + a > b){
			double s = (a + b + c) / 2;
			return sqrt(s * (s - a) * (s - b) * (s - c));
		} else return 0;
	}
	
	double area() {
		double a = dist(p[0], p[1]), b = dist(p[1], p[2]), c = dist(p[2], p[3]), d = dist(p[3], p[0]), e = dist(p[1], p[3]);
		double area1 = triangle_area(a, e, d), area2 = triangle_area(b, c, e);
		if (area1 > 0 && area2 > 0) return area1 + area2;
		else return 0;
	}
};

int main ( void ){
	double x1, y1, x2 ,y2, x3, y3, x4, y4;
	cout << "Enter 4 points: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	Point a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
	Triangle t(a, b, c);
	Polygon *poly = &t;
	if (poly->area() > 0) cout << "The triangle area is " << poly->area() << endl;
	else cout << "The trangle cannot be formed.\n";
	ConvexQuaderilateral cq(a, b, c, d);
	poly = &cq;
	if (poly->area() > 0) cout << "The convex quadrilateral area is " << poly->area() << endl;
	else cout << "The convex quaduilateral cannot be formed.\n";
}

