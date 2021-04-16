#include<stdio.h>

double f(double n)
{
	double c = 0;
	if ( (int) n % 2 == 0)
	{
		for ( double k = 1; k <= n; k+=2)
		{
			c += ((-1) * (k - 1) * (k - 1) / k ) + ((k * k) / ( k + 1)); 
		}		
	}
	else if ( (int) n % 2 == 1)
	{
		for ( double k = 2; k <= n; k++,k++)
		{
			c += ((k - 1) * (k - 1) / k ) - ((k * k) / ( k + 1));
		}
		c += (n * n) / ( n + 1);	
	}
	return c;
}

int main (void)
{
	double n;
	printf("Enter n: ");
	scanf("%lf", &n);
	printf("%lf", f(n)); 
}
