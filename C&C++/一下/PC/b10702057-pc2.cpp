#include<stdio.h>
#include<math.h>
 
typedef struct {
	double x, y;
} Point;

typedef struct {
	Point a, b, c;
} Triangle;

Point initPoint(double x,double y) {
	Point p;
	p.x = x;
	p.y = y;
	return p;
}

Triangle initTriangle(Point a, Point b, Point c) {
	Triangle t;
	t.a = a;
	t.b = b;
	t.c = c;
	return t;
}

double dist(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double area(Triangle t) {
	double ab = dist(t.a, t.b), bc = dist(t.b, t.c), ca = dist(t.a, t.c);
	
	if (ab + bc > ca && ab + ca > bc && bc + ca > ab) {
		double s = (ab + bc + ca) / 2;
		double area = sqrt(s * (s - ab) * (s - bc) * (s - ca));
		return area;
	} else return 0;
}

int main(void) {
	double x1, y1, x2, y2, x3, y3;
	
	printf("Enter 3 points: ");
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	Point a = initPoint(x1, y1), b = initPoint(x2, y2), c = initPoint(x3, y3);
	printf("(%lf, %lf) (%lf, %lf) (%lf, %lf)\n", a.x, a.y, b.x, b.y, c.x, c.y);
	Triangle t = initTriangle(a, b, c);
	if (area(t) > 0) printf("The triangle area is %lf.\n", area(t));
	else printf("The triangle cannot be formed.\n"); 
}

