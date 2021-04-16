#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double area( double x_1, double y_1,double x_2,double y_2,double x_3,double y_3)
{
	double a = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
	double b = sqrt((x_2 - x_3) * (x_2 - x_3) + (y_2 - y_3) * (y_2 - y_3));
	double c = sqrt((x_3 - x_1) * (x_3 - x_1) + (y_3 - y_1) * (y_3 - y_1));
	double s = ( a + b + c ) / 2 ;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main( void )
{
	double x_1, x_2, x_3, y_1, y_2, y_3;
	double a, b, c, s;
	double x, y;
	double a_area, b_area, c_area;
	printf("Enter there points: \n");
	scanf("%lf %lf %lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3);
	printf("%.4lfx + %.4lfy = %.4lf\n", y_1 - y_2, x_2 - x_1, y_1 * x_2 - x_1 * y_2);
	printf("%.4lfx + %.4lfy = %.4lf\n", y_3 - y_1, x_1 - x_3, y_3 * x_1 - x_3 * y_1);
	printf("%.4lfx + %.4lfy = %.4lf\n", y_2 - y_3, x_3 - x_2, y_2 * x_3 - x_2 * y_3);
	a = sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
	b = sqrt((x_2 - x_3) * (x_2 - x_3) + (y_2 - y_3) * (y_2 - y_3));
	c = sqrt((x_3 - x_1) * (x_3 - x_1) + (y_3 - y_1) * (y_3 - y_1));
	if ( a + b > c && a + c > b && b + c > a)
	{
		printf("The triangle area formed by (%.2lf,%.2lf), (%.2lf,%.2lf), and (%.2lf,%.2lf) is %.2lf\n", x_1, y_1, x_2, y_2, x_3, y_3, area(x_1, y_1, x_2, y_2, x_3, y_3));
	}
	printf("Enter a point: \n");
	scanf("%lf %lf", &x, &y);
/*	printf("%lf",area(x_1, y_1, x_2, y_2, x, y)); //a_area = area(x_1, y_1, x_2, y_2, x, y);
	printf("%lf",area(x_2, y_2, x_3, y_3, x, y)); //b_area = area(x_2, y_2, x_3, y_3, x, y);
	printf("%lf",area(x_3, y_3, x_1, y_1, x, y)); //c_area = area(x_3, y_3, x_1, y_1, x, y);*/
	double num_area = area(x_1, y_1, x_2, y_2, x, y) + area(x_2, y_2, x_3, y_3, x, y) + area(x_3, y_3, x_1, y_1, x, y);
	if ( num_area - area(x_1, y_1, x_2, y_2, x_3, y_3) < 0.0000001 || area(x_1, y_1, x_2, y_2, x_3, y_3) - num_area < 0.0000001)
	{
		printf("Y");
	}
	else
	{
		printf("N");
	}
}
