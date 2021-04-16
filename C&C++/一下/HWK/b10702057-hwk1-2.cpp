// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk1-2.cpp
// Compiler：Dev C++
// Date：2019/03/14

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<math.h>

typedef struct {
	double x, y;
} point;

typedef struct {
	double a, b, c;
} line;

line k(point a, point b, point c) {
	line sy;
	sy.a = sqrt(pow ((a.x + b.x), 2) + pow ((a.y + b.y), 2));
	sy.b = sqrt(pow ((b.x + c.x), 2) + pow ((b.y + c.y), 2));
	sy.c = sqrt(pow ((a.x + c.x), 2) + pow ((a.y + c.y), 2));
	return sy;
}

double are(line k) {
	double s = (k.a + k.b + k.c) / 2;
	double sum = sqrt( s * ( s - k.a ) * ( s - k.b ) * ( s - k.c ) );
	return sum;
}

void are_point(point a, point b, point c, point q) {
	double a_a, b_a, c_a, q_a;
	line a_l, b_l, c_l, q_l;
	
	q_l = k(a, b, c);
	a_l = k(q, b, c);
	b_l = k(a, q, c);
	c_l = k(a, b, q);
	
	q_a = are(q_l);
	a_a = are(a_l);
	b_a = are(b_l);
	c_a = are(c_l);
	
	if ( q_a - (a_a + b_a + c_a) < 0.000001 || q_a - (a_a + b_a + c_a) > -0.000001) {
		printf("(%.2lf, %.2lf) is inside the triangle.\n", q.x, q.y);
	}
	else{
		printf("點在外面\n");
	}
}

int main ( void ) {
	line sy;
	point a, b, c, q;
	
	printf("Enter the three points of the triangle: ");
	scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
	printf("Enter the point ");
	scanf("%lf %lf", &q.x, &q.y);
	
	sy = k(a, b, c);
	
	if ( sy.a + sy.b > sy.c && sy.b + sy.c > sy.a && sy.a + sy.c > sy.b) {
		printf("The perimeter of the triangle is %.2lf\n", sy.a + sy.b + sy.c);
		printf("The area of the triangle is %.2lf\n", are(sy));
		are_point(a, b, c, q);
	}
	else{
		printf("The triangle cannot be formed.\n");
	}
}
