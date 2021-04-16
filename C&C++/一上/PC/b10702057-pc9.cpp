#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100


int main ( void )
{
	int n, a[SIZE];
	srand(time(0));
	printf("Enter n:");
	scanf("%d", &n);
	
	for ( int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
		for ( int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				--i;
				break;
			}
		}
	}
	for ( int i = 0; i < n; i++) printf("%d ", a[i]);
}
