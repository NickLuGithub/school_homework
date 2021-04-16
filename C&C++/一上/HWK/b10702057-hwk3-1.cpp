// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-hwk3-1.cpp
// Compiler¡GDev C++
// Date¡G2018/11/22
#include<stdio.h>
#include<stdlib.h>

int f(int n)
{
	return n ? 2 * (2 * n - 1) * f(n - 1) / (1 + n) : 1;
}

int main ()
{
	int n;
	printf("Enter n : ");
	scanf("%d", &n);
	for ( int i = 0; i <= n; i++)
	{
		printf("%d ", f(i));
	}
}
