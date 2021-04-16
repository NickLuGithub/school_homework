// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex15.cpp
// Compiler：Dev C++
// Date：2018/12/27
#include<stdio.h>
#include<stdlib.h>

void sumq(double *a, double *b, double *sum)
{
	*sum = *a + *b;
}

void print(double sum)
{
	printf("整數 = %d\n",(int)sum);
	printf("小數 = %lf\n", sum - (int)sum);
}

int main ( void )
{
	double a, b, sum = 0;
	
	printf("Enter a,b ");
	scanf("%lf %lf", &a, &b);
	sumq(&a, &b, &sum);
	print(sum);
 }
