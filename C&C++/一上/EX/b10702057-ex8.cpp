// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-ex8.cpp
// Compiler¡GDev C++
// Date¡G2018/11/05

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double s( double n)
{
	return sqrt(n);
}

double sum( double n)
{
	int sum = 0;
	for ( int k = 1; k <= n; k++)
	{
		sum += k * k;
	}
	return sum;
}
int main( void )
{
	int k;
	do
	{
		printf("===================== Menu ==================\n");
		printf(" 1. Calculate Square Root\n");
		printf(" 2. Calculate Square Sum (1 + 4 + .. + n * n)\n");
		printf(" 3. Exit\n");
		printf("=============================================\n");
		double n;
		scanf("%d", &k);
		if ( k == 1 )
		{
			printf("=> 1\n");
			printf("Enter n: ");
			scanf("%lf", &n);
			printf("%lf\n", s(n));
			printf("=============================================\n");
		}
		else if ( k == 2)
		{
			printf("=> 2\n");
			printf("Enter n: ");
			scanf("%lf", &n);
			printf("%lf\n", sum(n));
			printf("=============================================\n");
		}
	}
	while( k != 3);
	printf("=> 3\nBye!");
} 
