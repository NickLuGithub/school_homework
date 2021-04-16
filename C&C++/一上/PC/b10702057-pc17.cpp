#include<stdio.h>
#include<stdlib.h>

int rsum(int n)
{
	if ( n < 1 ) return 1;
	else return rsum(n - 1) + n;
}

int sum(int n)
{
	int sum = 1;
	for ( int i = 1; i <= n; i++) sum = sum + i;
	return sum; 
}

double fac(int n)
{
	double f = 1;
	for ( int i = 2; i <= n; i++) f = f * (i - 1);
	return f;
}

double rfac(int n)
{
	if (n < 2) return 1;
	else return rfac(n - 1) * (n - 1);
}

int main ( void )
{
	int n;
	printf("Enter n : ");
	scanf("%d", &n);
	
	printf("sum(%d) = %d\n", n, sum(n));
	printf("rsum(%d) = %d\n", n, rsum(n));
	printf("fac(%d) = %.0f\n", n, fac(n));
	printf("rfac(%d) = %.0f\n", n, rfac(n));
}
