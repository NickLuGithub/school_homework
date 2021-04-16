// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-ex9.cpp
// Compiler¡GDev C++
// Date¡G2018/11/09
#include<stdio.h>
#include<stdlib.h>

double a( double n)
{
	double sum = 0;
	for ( double k = 1; k <= n; k++)
	{
		sum += k * k;
	}
	return sum;
}

double b( double n)
{
	double sum = 1;
	for ( double k = 1; k <= n; k++)
	{
		sum *= k;
	}
	return sum;
}

int main ( void )
{
	double n,c;
	printf("Enter n:");
	scanf("%lf", &n);
	for ( double k = 1; k <= n; k++)
	{
		c += a(k) / b(k);
	}
	printf("%.20lf\n", c);
}
