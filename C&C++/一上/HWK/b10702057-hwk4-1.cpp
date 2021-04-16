// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-hwk4-1.cpp
// Compiler¡GDev C++
// Date¡G2018/12/28
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 1000

void array(int a[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}
}

int max(int a[], int n)
{
	int t = a[0];
	for (int i = 1; i < n; i++)
	{
		if ( t < a[i]) t = a[i]; 
	}
	return t;
}

int min(int a[], int n)
{
	int t = a[0];
	for (int i = 1; i < n; i++)
	{
		if ( t > a[i]) t = a[i]; 
	}
	return t;
}

void percentage(int a[], double b[], int n)
{
	for ( int i = 0; i < n; i++)
	{
		switch (a[i] % 10){
			case 10:case 9:{
				b[9]++;
				break;
			}
			case 8:{
				b[8]++;
				break;
			}
			case 7:{
				b[7]++;
				break;
			}
			case 6:{
				b[6]++;
				break;
			}
			case 5:{
				b[5]++;
				break;
			}
			case 4:{
				b[4]++;
				break;
			}
			case 3:{
				b[3]++;
				break;
			}
			case 2:{
				b[2]++;
				break;
			}
			case 1:{
				b[1]++;
				break;
			}
			default:{
				b[0]++;
			}	
		}

	}
	
	printf("The value distributes are shown as follows:\n");
	printf("   Range     Percentage\n");
	
	for (int i = 0; i < 10; i++)
	{
		if ( i != 9) printf("%3d - %3d   ", i*10, i*10+9);
		else printf("%3d - %3d   ", i*10, i*10+10);
		
		printf("%3.0lf%%      ", b[i] / n * 100);
		
		for ( int k = 0; k < b[i] / n * 100; k++) printf("*");
		puts("");
	}

}

void print_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if ((i) % 10 == 0 && i != 0) printf("\n%3d ", a[i]);
		else printf("%3d ", a[i]);
	}
	puts("");
}

int main ( void )
{
	int n, a[SIZE];
	double b[SIZE];
	
	srand(time(0));
	
	printf("Enter n:");
	scanf("%d", &n);
	
	array(a, n);
	print_array(a, n);
	printf("mix = %d\n", max(a, n));
	printf("min = %d\n", min(a, n));
	
	percentage(a, b, n);
	
  }  
