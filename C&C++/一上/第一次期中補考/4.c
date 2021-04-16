#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
	int a[4], n, num = 0, b[5] = {0}, point = 0;
	char w;
	srand(time(0));
	for ( int k = 0; k < 4; k++)
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

	while ( num != 4)
	{
		for ( int q = 0; q < 4; q++)
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
		
		printf("Select one: ");
		int n;
		scanf("%d", &n);
		
		if ( b[ n - 1] == 1)
		{
			printf("此位子以猜過\n");
		}
		else if ( n > 4)
		{
			printf("輸入錯誤\n");
		}
		else
		{
			printf("Enter a number between 1 and 10:");
			int number;
			scanf("%d", &number);
			if ( number >= 1 && number <= 10 )
			{
				if ( number < a[ n - 1])
				{
					if ( ( a[ n - 1] + number) % 2 == 0)
					{
						point += a[ n - 1] + number; 
						printf("%d is larger than %d. The sum of %d and %d is %d. The player wins %d point.\n", a[ n - 1], number, a[ n - 1], number,  a[ n - 1] + number, a[ n - 1] + number);
					}
					else
					{
						printf("%d is larger than %d. The sum of %d and %d is %d. The player wins 0 point.\n", a[ n - 1], number, a[ n - 1], number,a[ n - 1] + number);
					}
				}
				else 
				{
					printf("%d is larger than %d. The sum of %d and %d is %d. The player wins 0 point.\n", a[ n - 1], number, a[ n - 1], number,a[ n - 1] + number);
				}
				b[n-1] = 1;
				num++;
			}
			else
			{
				printf("輸入錯誤\n");
			}
		}
	}
	for ( int q = 0; q < 4; q++)
	{
		printf("%d ", a[q]);
	}
	printf("You win %d points", point);
}
