// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk4-2.cpp
// Compiler：Dev C++
// Date：2018/12/28
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

void on(int you[][SIZE], int *q, int *n)
{
	int p;
	printf("請問需要購入幾張彩票:");
	scanf("%d", &*n);
	printf("請問幾張需要電腦選號:");
	scanf("%d", &p);
	for ( int i = *q; i < *q + p; i++)
	{
		int b[6] = {0};
		for ( int i = 0; i < 6; i++)
		{
			b[i] = rand() % 49 + 1;
			for ( int k = 0; k < i; k++)
			{
				if ( b[i] == b[k] && b[i] == 0)
				{
					i++;
					break;
				}
			}
		}
		
		for ( int k = 0, q = 0; k < 6; k++)
		{
			you[i][k] = b[q++];
		}
	}
	
	for ( int i = *q + p; i < *q + *n; i++)
	{
		printf("輸入一組數字(6個不一樣的數):");
		scanf("%d %d %d %d %d %d", &you[i][0], &you[i][1], &you[i][2], &you[i][3], &you[i][4], &you[i][5]);
		for (int k = 0; k < 6; k++)
		{
			if ( you[i][k] > 49 || you[i][k] < 1)
			{
				printf("輸入錯誤\n");
				i--;
				break;
			}
		}
	}
	
	printf("你的樂透\n");
	
	for ( int i = 0; i < *q + *n; i++)
	{
		printf("%2d組數字", i+1);
		for ( int k = 0; k < 6; k++)
		{
			printf(" %2d", you[i][k]);
		}
		puts("");
	}
}

void ax(int you[][SIZE], int b[], int q, int *money, int *total)
{
	for ( int i = 0; i < q; i++)
	{
		int k = 0;
		for ( int l = 0; l < 6; l++)
		{
			for ( int p = 0; p < 6; p++)
			{
				if (you[i][l] == b[p]) k++;
			}
		}
		switch (k){
			case 6:{
				*total += 1;
				*money += 100000000;
				break;
			}
			case 5:{
				*total += 1;
				*money += 10000000;
				break;
			}
			case 4:{
				*total += 1;
				*money += 5000;
				break;
			}
			case 3:{
				*total += 1;
				*money += 300;
				break;
			}
			default:{
			}
		}
	}
}

int main ( void )
{
	char go, play = 'Y';

	srand(time(0));
	
	do{
		
		int b[SIZE] = {0};
		int you[SIZE][SIZE] = {0};
		int n = 0, q = 0;
		int money = 0, total = 0;
		
		for ( int i = 0; i < 6; i++)
		{
			b[i] = rand() % 49 + 1;
			for ( int k = 0; k < i; k++)
			{
				if ( b[i] == b[k] && b[i] == 0)
				{
					i++;
					break;
				}
			}
		}
		
		printf("歡迎光臨\n");
		do
		{
			printf("是否(再次)購買彩券(Y/N):");
			scanf("%s", &go);
			if (go == 'Y' || go == 'y')
			{
				q += n;
				on(you, &q, &n);
			}
		}while ( go != 'N' && go != 'n');
		
		q += n;
		
		ax(you, b, q, &money, &total);
		printf("樂透號碼:");
		for ( int i = 0; i < 6; i++)
		{
			printf(" %d", b[i]);
		}
		puts("");
		printf("你需支付%d元\n", q * 50);
		printf("你共有%d組對中樂透\n", total);
		printf("獲得%d將金\n", money);
		printf("是否再次光臨(Y/N):");
		scanf("%s", &play);
	}while ( play != 'N' && play != 'n');
}
