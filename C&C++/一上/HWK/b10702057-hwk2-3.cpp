// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-hwk2-3.cpp
// Compiler¡GDev C++
// Date¡G2018/10/16
#include<stdio.h>
#include<math.h>

double f(double x)
{
	return cos(x) + sqrt(x);
}

int main ( void )
{
	double a, b, c;
	printf("Enter a,b,c: \n");
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("                                        Y-axis\n       ");
	for ( double y = 0; y <= b; y += c)
	{
		printf("%.1f  ",y);
	}
	printf("\nX-axis  ");
	for ( double y = 0; y <= b; y += c)
	{
		if ( y < 10 - c)
		{
			printf("+----");
		}
		else 
		{
			printf("+-----");
		}
	}
	printf("\n");
	for ( double y = a; y <= b; y += c)
	{
		if ( y <= 10 - c)
		{
			printf("  %.1f  +",y);
		}
		else 
		{
			printf("  %.1f +",y);
		}
		for ( double k = 0; k < f(y); k += 0.1)
		{
			printf(" ");
		}
		printf("*\n");
		printf("       |");
		for ( double k = 0; k < f( y + (c / 2)); k += 0.1)
		{
			printf(" ");
		}
		printf("*\n");
	}
}
