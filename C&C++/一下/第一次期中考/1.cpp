// Student No.¡GB10702057  Name¡G¿c¬R¹F 
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>

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
		if ( i != n){
			for ( int p = 1; p <= 2 * i - 1; p++)
			{
				if ( p == 1 || p == 2 * i - 1){
					printf("%d",w);
					w--;
				}
				else{
					printf(" ");
					w--;
				}
				
			}
			printf("\n");		
		}
		else {
			for ( int p = 1; p <= 2 * i - 1; p++)
			{
				printf("%d",w);
				w--;
			}
			printf("\n");
		}
		
	}
} 
