// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-pc10.cpp
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
double sum ( double a[], int n)
{
	int sum = 0; 
	for ( int i = 0; i < n; i++) sum += a[i];
	return sum; 
}
double avg ( double a[], int n)
{
	int sum = 0; 
	for ( int i = 0; i < n; i++) sum += a[i];
	return sum/n; 
}

int main ( void )
{
	int n;
	double a[SIZE];
	printf("Enter n:");
	scanf("%d", &n);
	read_a(a, n);
	printf_a(a, n);
	printf("總和%.2lf", sum(a, n));
	printf("平均%.2lf", avg(a, n));
}
