// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-ex6.cpp
// Compiler¡GDev C++
// Date¡G2018/10/18
#include<stdio.h>
#include<stdlib.h>

int main ( void )
{
	int a, b, i, s, c, d, e, f, count = 0;
	printf("Enter the range ( 0 ~ 9999 ) :");
	scanf("%d%d", &i , &s);
	for ( int a = i; a <= s; a++)
	{
		c = a / 1000;
		d = ( a - c * 1000 ) / 100;
		e = ( a - c * 1000 - d * 100) / 10;
		f = ( a - c * 1000 - d * 100 - e * 10 );
		if ( c == 4 || d == 4 || e == 4 || f == 4)
		{
			count++;
		}
	}
	printf("There are %d plates without 4 in this range", s - i + 1 - count);
} 
