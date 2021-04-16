// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-ex14.cpp
// Compiler¡GDev C++
// Date¡G2018/11/29
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

void array(char a[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		a[i] = rand() % 26 + (rand() % 2 ? 'a' : 'A');
	}
	a[n] = '\0'; 
}
 
void print_array(char a[])
{
	printf("%s \n", a);
}

void pinrt_ABC(char a[], int b[], int n)
{
	for ( int l = 0; l < n; l++) if (a[l] >= 65 && a[l] <= 90) a[l] += 32;
	for ( int i = 0; i < n; i++)
	{
		b[a[i]]++;
	}
	for ( int i = 97; i < 123; i++)
	{
		printf("%c = %d\n", (char)i, b[i]);
	}
}

int main ( void )
{
	int n, b[1000] = {0};
	char a[100];
	srand(time(0));
	printf("Enter n ");
	scanf("%d", &n);
	array(a, n);
	print_array(a);
	pinrt_ABC(a, b, n);
}
