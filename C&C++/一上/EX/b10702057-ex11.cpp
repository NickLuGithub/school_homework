// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex11.cpp
// Compiler�GDev C++
// Date�G2018/11/22
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void in( int a[], int b[], int n) //Ū�Ʀr 
{
	for ( int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		switch(a[i] / 10)       // ���� 
		{
			case 10:{
				b[9]++;
				break;
			}
			case 9:{
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
}

void out(int b[]) // ��X 
{
	for ( int i = 0; i < 10; i++)
	{
		if ( i != 9 ) printf("%2d ~ %2d %2d ", i * 10, i * 10 + 9, b[i]);
		else printf("%2d ~ %3d %2d ", i * 10, i * 10 + 10, b[i]);
		for ( int j = 0; j < b[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main ( void )
{
	int a[SIZE] = {0}, b[10] = {0}, n;
	
	printf("��Jn: ");
	scanf("%d", &n);
	in(a, b, n);
	out(b);
} 
