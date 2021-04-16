// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-ex5.cpp
// Compiler¡GDev C++
// Date¡G2018/10/11
#include<stdio.h>

int main ( void )
{
	int n;
	printf("Enter n¡G");
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		for (int p = 1; p <= 2 * i - 1; p++)
		{
			if ( p == 1 || p == 2 * i - 1)
			{
				printf ("%d", i);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");	
	}
	
	for (int i = n - 1; i >= 1; i--){
		for (int j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		for (int p = 2 * i - 1; p >= 1; p--){
			if ( p == 1 || p == 2 * i - 1)
			{
				printf ("%d", i);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
		
	}
} 
