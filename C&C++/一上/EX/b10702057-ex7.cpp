// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex7.cpp
// Compiler：Dev C++
// Date：2018/10/25
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ( void )
{
	int out = 0, sum = 0, in_n;
	
	srand(time(0));
	printf("Enter n : ");
	scanf("%d", &in_n);
	for ( int k = 1; k <= in_n; k++)
	{
		out = rand() % 100 + 1;
		sum += out;
		printf("%d = %d\n", k, out);
	}
	printf("亂數總和平均 : %d\n", sum / in_n);
}
