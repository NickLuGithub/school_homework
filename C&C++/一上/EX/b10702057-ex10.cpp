// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex10.cpp
// Compiler：Dev C++
// Date：2018/11/12
#include<stdio.h>
#define SIZE 100 

void read_a ( double a[], int n)
{
	for ( int i = 0; i < n; i++) scanf("%lf", &a[i]);
}
void printf_a ( double a[], int n)
{
	for ( int i = 0; i < n; i++) printf("%.2lf ", a[i]);
}
double max ( double a[], int n)
{
	int max = a[0]; 
	for ( int i = 1; i < n; i++) if ( max < a[i]) max = a[i];
	return max; 
}
double min ( double a[], int n)
{
	int min = a[0]; 
	for ( int i = 1; i < n; i++) if ( min > a[i]) min = a[i];
	return min; 
}

int main ( void )
{
	int n;
	double a[SIZE];
	printf("Enter n:");
	scanf("%d", &n);
	read_a(a, n);
	printf_a(a, n);
	printf("最大值%.2lf", max(a, n));
	printf("最小值%.2lf", min(a, n));
}
