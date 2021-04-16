#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double out_1( double a, double b, double c, double x)
{
	return a * ( x * x ) + b * x + c;
}

double x_max(double a, double b)
{
	return -b / (2 * a);
}

double y_max(double a, double b, double c)
{
	return ( 4 * a * c - b * b) / 4 * a;
}

double out_2( double a, double b, double c, double aa, double bb, double cc)
{
	double x = x_max(a, b);
	//printf("%lf\n",x);
	double y = y_max(a, b, c);
	//printf("%lf\n",y);
	double aws = 0;
	aws += aa * x + bb * y + cc;
	//printf("%lf\n",aws);
	if ( aws < 0)
	{
		aws = -aws;
	}
	aws /= sqrt(( a * a) + ( b * b));
	return aws;
}
double area( double a, double b, double c)
{
	double x = ( c/a ) * ( c/b ) * 0.5;
	if ( x < 0)
	{
		x *= -1;
	}
	return x;
}

int main ( void )
{
	double a, b, c, x;
	double aa, bb, cc;
	printf("Enter x a b c:");
	scanf("%lf %lf %lf %lf", &x, &a, &b, &c);
	printf("Enter a b c:");
	scanf("%lf %lf %lf", &aa, &bb, &cc);
	printf("The value of y = %.2lfx^2 + %.2lfx + %.2lf at x = %.2lf is %.2lf.\n", a, b, c, x, out_1(a, b, c, x));
	printf("拋物線到點距離%d\n",(int)out_2(a, b, c, aa, bb, cc));
	printf("直線與原點夠成面積%lf\n",area(aa, bb, cc));
}
