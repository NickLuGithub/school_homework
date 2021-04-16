// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-hmk2-1.cpp
// Compiler¡GDev C++
// Date¡G2018/10/16
#include<stdio.h>

int main ( void )
{
	int n;
	printf("Enter n¡G");
	scanf("%d",&n);
	for ( int i = 1; i <= n; i++)
	{
		for ( int j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		int w = n + ( i - 1);
		for ( int p = 1; p <= 2 * i - 1; p++)
		{
			printf("%d",w);
			w--;
		}
		printf("\n");	
	}
	
	for ( int i = n - 1; i >= 1; i--)
	{
		for ( int j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		int w = n + ( i - 1);
		for (int p = 2 * i - 1; p >= 1; p--)
		{
			printf("%d",w);
			w--;
		}
		printf("\n");
		
	}
} 
