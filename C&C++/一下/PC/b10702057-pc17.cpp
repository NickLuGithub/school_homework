#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Point {                                   // ���O�O���󪺭쫬/�ҫ�/���󪺶��X���A 
private:                                        // �M�ݩ����O 
	double x, y;                                  // �p�����O�ܼ�/�ݩ� 
public:
	Point(double _x = 0, double _y = 0) {         // Constructor (�غc�l): �غc���� 
		setPoint(_x, _y);
	}	
	void setPoint(double _x = 0, double _y = 0) { // Mutator (�ܲ��l): ���ܪ���p���ܼƭ� 
		x = _x;
		y = _y;
	}
  	double getX() { return x; }                   // Accessor (�s���l): �s������p���ܼƭ� 
  	double getY() { return y; }                   // Accessor (�s���l): �s������p���ܼƭ�  
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
		Polygon(){}
		Polygon(int _n){
			n = _n < 3 ? 3 : _n;
			p = new Point[n];
		}
		void setPolygon(Point *_p){
			for (int i = 0; i < n ; i++) p[i] = _p[i];
		}
		Point getPoint(int i){
			return i >= 0 && i < n ? p[i] : Point();
		}
};

class Triangle : public Polygon {
	public:
		Triangle(Point a, Point b, Point c){
			n = 3;
			p = new Point[n];
			p[0] = a;
			p[1] = b;
			p[2] = c; 
		}
		void setTriangle(Point *_p) {
			setPolygon(_p);
		}
		double area() {
			double a = dist(p[0], p[1]), b = dist(p[1], p[2]), c = dist(p[2], p[0]);
			if (a + b > c && b + c > a && c + a > b){
				double s = (a + b + c)/2;
				return sqrt(s * (s - a) * (s - b) * (s - c));
			}
			else return 0;
		}
		string str() {
			ostringstream out;
			out << p[0].str() << " " << p[1].str() << " " << p[2].str();
			return out.str();
		}
};

int main ( void ){
	double x1, y1, x2, y2, x3, y3;
	cout << "Enter 3 points ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point a(x1, y1), b(x2, y2), c(x3, y3);
	Triangle t(a, b, c);
	cout << "The area of the triangle " << t.str() << " is " << t.area() << endl;
}
