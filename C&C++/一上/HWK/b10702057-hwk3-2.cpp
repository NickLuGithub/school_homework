// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk3-2.cpp
// Compiler�GDev C++
// Date�G2018/11/22
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void out(int n)
{
	switch ( n )
	{
		case 1 : case 10:{
			printf("��o100��\n\n");
			break;
		}
		case 2 : case 8: {
			printf("�A���@��\n\n");
			int a = rand() % 10 + 1;
			printf("�A�����X%d\n", a);
			out(a);
			break;
		}
		case 3 : case 4: case 6: case 7: case 9:{
			printf("���´f�U\n\n");
			break;
		}
		case 5:{
			printf("��o300��\n\n");
			break;
		}
	}
}

int main ( void )
{
	srand(time(0));
	
	int n,a;
	char in;
	printf("�w��Ө�nick�C����\n");
	printf("�}�l�C��(Y/N)\n");
	scanf("%s", &in);
	while ( in == 'Y' || in == 'y')
	{
		printf("�Ч��(100�@��)");
		scanf("%d", &n);
		n /= 100;
		for ( int i = 0; i < n; i++)
		{
			a = rand() % 10 + 1;
			printf("�A�����X%d\n", a);
			out(a);
		}
	printf("�A�}�l�C���@��?(Y/N)\n");
	scanf("%s", &in);
	}
	

}
