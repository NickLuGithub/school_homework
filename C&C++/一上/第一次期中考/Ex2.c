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
		for ( int p = 1; p <= (2 * i - 1)/2; p++)
		{	
			printf("%d", p);
		}
		for ( int k = (2 * i - 1)/2 ; k >= 1; k--)
		{
			printf("%d", k);
		}
		printf("\n");	
	}
	
	for ( int i = n - 1; i >= 1; i--)
	{
		for ( int j = 1; j <= n - 1; j++)
		{
			printf(" ");
		}
		printf("%d", i);
		printf("\n");
		
	}
} 
