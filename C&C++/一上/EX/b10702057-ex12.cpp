// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-ex12.cpp
// Compiler¡GDev C++
// Date¡G2018/11/29
#include<stdio.h>
#include<stdlib.h>
#define ROW 50
#define COL 50

void array( int a[][COL], int b[], int n)
{
	b[0] = n;
	for (int i = 1; i < n * n; i++) b[i] = b[i - 1] + n;
	for ( int i = 0, k = 0; i < n; i++)
	{
		for ( int j = 0; j < n; j++)
		{
			a[i][j] = b[k++];
		}
	}
}

void print_array(int a[][COL], int n)
{
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}

int main(void)
{
	int n, i, j, a[ROW][COL], b[ROW * COL], k = 0;
 
	printf("Enter n: ");
	scanf("%d", &n);
	array(a, b, n);
	print_array(a, n);
	
	printf("Enter i, j: ");
	scanf("%d %d", &i, &j);
	if ( i > n || j > n)
	{
		printf("Not found\n");
	}
	else
	{
		printf("¦ì¸m %d i %d j = %d", i, j, a[i - 1][j- 1]);
	}
	
}
 
