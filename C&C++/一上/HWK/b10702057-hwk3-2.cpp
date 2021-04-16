// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk3-2.cpp
// Compiler：Dev C++
// Date：2018/11/22
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void out(int n)
{
	switch ( n )
	{
		case 1 : case 10:{
			printf("獲得100元\n\n");
			break;
		}
		case 2 : case 8: {
			printf("再玩一次\n\n");
			int a = rand() % 10 + 1;
			printf("你的號碼%d\n", a);
			out(a);
			break;
		}
		case 3 : case 4: case 6: case 7: case 9:{
			printf("銘謝惠顧\n\n");
			break;
		}
		case 5:{
			printf("獲得300元\n\n");
			break;
		}
	}
}

int main ( void )
{
	srand(time(0));
	
	int n,a;
	char in;
	printf("歡迎來到nick遊戲機\n");
	printf("開始遊戲(Y/N)\n");
	scanf("%s", &in);
	while ( in == 'Y' || in == 'y')
	{
		printf("請投幣(100一次)");
		scanf("%d", &n);
		n /= 100;
		for ( int i = 0; i < n; i++)
		{
			a = rand() % 10 + 1;
			printf("你的號碼%d\n", a);
			out(a);
		}
	printf("再開始遊戲一次?(Y/N)\n");
	scanf("%s", &in);
	}
	

}
