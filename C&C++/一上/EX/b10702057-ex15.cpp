// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex15.cpp
// Compiler�GDev C++
// Date�G2018/12/27
#include<stdio.h>
#include<stdlib.h>

void sumq(double *a, double *b, double *sum)
{
	*sum = *a + *b;
}

void print(double sum)
{
	printf("��� = %d\n",(int)sum);
	printf("�p�� = %lf\n", sum - (int)sum);
}

int main ( void )
{
	double a, b, sum = 0;
	
	printf("Enter a,b ");
	scanf("%lf %lf", &a, &b);
	sumq(&a, &b, &sum);
	print(sum);
 }
