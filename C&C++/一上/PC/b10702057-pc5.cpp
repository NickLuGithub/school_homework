//�Ǹ��GB10702056  Name�G����� 
//�ɦW�Gb10702057-hmk2-1.cpp
#include<stdio.h>

int main ( void )
{
	int n;
	printf("Enter n�G");
	scanf("%d",&n);
	for ( int i = 1; i <= n; i++)
	{
		for ( int j = 1; j <= n-i; j++)
		{
			printf(" "); //�Ů� 
		}
		if ( i == n)
		{
			for ( int p = 1; p <= 2 * i - 1; p++)
			{
				printf("%d",i);
			}
		}
		else
		{
			for ( int p = 1; p <= 2 * i - 1; p++)
			{
				if ( p % 2 == 1)
				{
					printf("%d",i);
				}
				else
				{
					printf(" ");
				}
			}			
		}
		printf("\n");	
	}
	
	for ( int i = n - 1; i >= 1; i--)
	{
		for ( int j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		for ( int p = 1; p <= 2 * i - 1; p++)
		{
			if ( p % 2 == 1)
			{
				printf("%d",i);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");		
	}
} 
