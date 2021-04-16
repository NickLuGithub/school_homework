#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
	int a[5], n, num = 6, b[5] = {0}, point = 0;
	char w;
	srand(time(0));
	for ( int k = 0; k < 5; k++)
	{
		a[k] = rand() % 10 + 1;
		for ( int q = 0; q < k; q++)
		{
			if ( a[k] == a[q])
			{
				k--;
				break;
			}
		}
	}

	while ( num != 1)
	{
		for ( int q = 0; q < 5; q++)
		{
			if ( b[q] == 0)
			{
				printf("* ");	
			}
			else
			{
				printf("%d ", a[q]);
			}
		}
		printf("\n");
		printf("Pick a number: ");
		scanf("%d", &n);
		b[n-1] = 1;
		printf("Even or Odd (E|O): ");
		scanf("%s", &w);
		if ( a[n-1] % 2 == 1 && w == 'E' || a[n-1] % 2 == 0 && w == 'O')
		{
			point += a[n-1];
		}
		num--;
	}
	for ( int q = 0; q < 5; q++)
	{
		printf("%d ", a[q]);
	}
	printf("You win %d points", point);
}
