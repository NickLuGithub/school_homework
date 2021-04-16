#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double point_lin(double a, double b, double c, double d)
{
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

double xy_point(double a, double b)
{
	return (a + b) / 2;
}


double are(double r)
{
	return r*r*3.14; 
}

double cir(double r)
{
	return 2*r*3.14;
}

int main (void)
{
	double x1,y1,x2,y2,a,b,r,x,y;
	
	printf("Enter 3 points:");
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &a, &b);
	
	r = point_lin(x1, y1, x2, y2) / 2;
	x = xy_point(x1,x2);
	y = xy_point(y1,y2);
	printf("���(%.2lf,%.2lf)�b�|%.2lf\n", x, y, r);
	printf("���n%.2lf\n", are(r));
	printf("�P��%.2lf\n", cir(r));
	if (point_lin(x, y, a, b) / 2 > r)
	{
		printf("�I(%.2lf,%.2lf)�b��~��\n", a, b);
	}
	else
	{
		printf("�I(%.2lf,%.2lf)�b��̭�\n", a, b);
	}
}
