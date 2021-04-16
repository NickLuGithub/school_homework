#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double a( double n)
{
	double sum = 0;
	for ( double q = 1,k = 1; q <= n; q++ ,k = -k)
	{
		sum += k * ( 2 * ( q * q ) - 1 ) / ( ( q * q ) + 1);
	}
	return sum;
}

int main ( void )
{
	double n;
	printf("Enter n: ");
	scanf("%lf", &n);
	printf("%.20lf", a(n));
	return 0;
	
}
