#include<iostream>
#include<sstream>
using namespace std;

typedef struct {
	double x, y;
} Point;

class PointSet {
private:
	Point *p;
	int n;
public:
	PointSet(int _n = 1){
		n = _n;
		p = new Point[n];
	}
	void setPoint(Point *_p, int n){
		for ( int i = 0; i < n; i++) p[i] = _p[i];
	}
	string str() {
		ostringstream out;
		out << "{";
		for (int i = 0; i < n - 1; i++) out << "(" << p[i].x << ", " << p[i].y << "), ";
		out <<"(" << p[n - 1].x << ", " << p[n - 1].y << ")}";
		return out.str();
	}
};

int main ( void ){
	int n;
	cout << "Enter n: ";
	cin >> n;
	Point *p = new Point[n];
	cout << "Enter " << n << " points: ";
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	PointSet ps(n);
	ps.setPoint(p, n);
	cout << "The point set is " << ps.str() << "." << endl;
}
