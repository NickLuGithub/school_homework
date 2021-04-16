// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc14.cpp
// Compiler¡GDev C++
// Date¡G2018/11/29
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 30
#define COL 30

void random_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n + 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				--i;
				break;			
			}
		}
	}
}
void even_random_array(int a[], int n)
{
	random_array(a, n);
	for (int i = 0; i < n; i++) a[i] *= 2;
}

void odd_random_array(int a[], int n)
{
	random_array(a, n);
	for (int i = 0; i < n; i++) a[i] = a[i] * 2 - 1;
}

void convert_to_2darray(int a[], int b[][COL], int m, int n) {
	for (int i = 0, k = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) b[i][j] = a[k++];
	}
}

void random_2darray(int a[], int b[][COL], int m, int n)
{
	random_array(a, m * n);
	for ( int i = 0, k = 0; i < m; i++)
	{
		for ( int j = 0; j < n; j++) b[i][j] = a[k++];
	}
}

void even_random_2darray(int a[], int b[][COL], int m, int n)
{
	even_random_array(a, m * n);
	for ( int i = 0, k = 0; i < m; i++)
	{
		for ( int j = 0; j < n; j++) b[i][j] = a[k++];
	}
}

void odd_random_2darray(int a[], int b[][COL], int m, int n)
{
	odd_random_array(a, m * n);
	for ( int i = 0, k = 0; i < m; i++)
	{
		for ( int j = 0; j < n; j++) b[i][j] = a[k++];
	}
}

void print_array(int a[], int n)
{
	for ( int i = 0; i < n; i++) printf("%d ", a[i]);
	puts("");
}

void print_2darray(int b[][COL], int m, int n)
{
	for ( int i = 0; i < m; i++)
	{
		for ( int j = 0; j < n; j++) printf("%5d ", b[i][j]);
		puts("");
	}
	puts("");
}
int main(void)
{
	int a[ROW * COL], b[ROW][COL], m, n;
	
	srand(time(0));
	printf("Enter m, n: ");
	scanf("%d %d", &m, &n);
	
	random_array(a, m * n);
	print_array(a, m * n);
	even_random_array(a, m * n);
	print_array(a, m * n);
	odd_random_array(a, m * n);
	print_array(a, m * n);
	
	random_2darray(a, b, m, n);
	print_2darray(b, m, n);
	even_random_2darray(a, b, m, n);
	print_2darray(b, m, n);
	odd_random_2darray(a, b, m, n);
	print_2darray(b, m, n);
}
