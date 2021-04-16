// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc11.cpp
// Compiler¡GDev C++
// Date¡G2018/11/15
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ( void )
{
	int a[6], b[6], star = 0;
	srand(time(0));
	
	for ( int i = 0; i < 6; i++)
	{
		a[i] = rand() % 49 + 1;
		for ( int k = 0; k < i; k++)
		{
			if ( a[i] == a[k])
			{
				--i;
				break;
			}
		}
	}
	printf("Enter 6 numbers ( 1 - 49 ): ");
	for ( int i = 0; i < 6; i++) scanf("%d", &b[i]);
	for ( int i = 0; i < 6; i++) printf("%d ", a[i]);
	puts("");
	
	for ( int i = 0; i < 6; i++)
	{
		for ( int l = 0; l < 6; l++)
		{
			star += b[i] == a[l] ? 1 : 0;
		}
	}
	printf("You won %d stars.\n", star);
}
