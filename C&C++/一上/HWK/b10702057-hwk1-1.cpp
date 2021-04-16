// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk1-1.cpp
// Compiler：Dev C++
// Date：2018/10/04

#include<stdio.h>

int main ( void )
{
	char in;
	int in_mid;
	do
	{
		printf("    尋找金黃冠\n");
		printf("請問是否進行遊戲(Y/N)\n");
		in_mid = getchar();	
		while( in != 'N' && in != 'n')
		{
			printf("請選擇一條路(1/2/3)\n");
			scanf("%d",&in_mid);
			if ( in_mid == 1)
			{
				printf("銘謝惠顧\n");
				break;
			}
			else if ( in_mid == 2)
			{
				printf("請再選擇一條路(1/2/3)\n");
				scanf("%d",&in_mid);
				if ( in_mid == 1)
				{
					printf("恭喜獲得皇冠\n");
					break;
				}
				else if ( in_mid == 3)
				{
					printf("請再選擇一條路(1/2/3)\n");
					scanf("%d",&in_mid);
					if ( in_mid == 1)
					{
						printf("銘謝惠顧\n");
						break;
					}
					else if ( in_mid == 2)
					{
						printf("恭喜獲得皇冠\n");
						break;
					}
					else if ( in_mid == 3)
					{
						printf("請再選擇一條路(1/2)\n");
						scanf("%d",&in_mid);
						if ( in_mid == 1)
						{
							printf("銘謝惠顧\n");
							break;
						}
						else if ( in_mid == 2)
						{
							printf("恭喜獲得金皇冠\n");
							break;
						}
						else
						{
							printf("輸入錯誤\n");
							break;
						}
					}
					else
					{
						printf("輸入錯誤\n");
						break;
					}
				}
				else if ( in_mid == 2)
				{
					printf("恭喜獲得皇冠\n");
					break;
				}
				else
				{
					printf("輸入錯誤\n");
					break;
				}
			}
			else if ( in_mid == 3)
			{
				printf("恭喜獲得皇冠\n");
				break;
			}
			else
			{
				printf("輸入錯誤\n");
				break;
			}
		}		
	}while( in != 'N' && in != 'n');
}
