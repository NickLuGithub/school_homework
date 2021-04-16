#include<stdio.h>

int main ( void )
{
	int n;
	printf("Enter n¡G");
	scanf("%d",&n);
	for ( int k = n; k >= 1; k--)
	{
		printf("%d", k);
	}
	
	for ( int k = 2; k <= n ; k++)
	{
		printf("%d", k);
	}
	
	printf("\n");
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		for (int p = 2 * i - 1; p >= 1; p--)
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
}
