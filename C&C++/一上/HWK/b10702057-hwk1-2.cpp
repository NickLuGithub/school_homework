// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk1-2.cpp
// Compiler：Dev C++
// Date：2018/10/05

#include <stdio.h>

int main ( void )
{
	char in;
	int money = 0,h,in_1,money_1 = 0;
	do{
		printf("歡迎來到疊字販賣機\n我們的商品有：\n");
		printf("01 - 哭哭 $100 02 - 顆顆 $100 03 - 廠廠 $100 04 - 聒聒 $100 05 - 喵喵 $100\n06 - 旺旺 $200 07 - 啾啾 $200 08 - 尻尻 $200 09 - 哈哈 $200 10 - 雞雞 $200\n");
		printf("請問是否需要購物(Y/N)\n");
		scanf("%s",&in);
		if ( in == 'Y' || in == 'y' || in == 'N' || in == 'n')
		{
			while ( in != 'N' && in != 'n')
			{
				printf("請投幣\n");
				scanf("%d",&money_1);
				money += money_1;
				if ( money < 100 )
				{
				}
				else if ( money < 200 )
				{
					printf("可購買：01 - 哭哭 $100 02 - 顆顆 $100 03 - 廠廠 $100 04 - 聒聒 $100 05 - 喵喵 $100\n");
					printf("再投幣請先輸入 0 \n離開請輸入11\n");
					scanf("%d",&h);
					switch ( h )
					{
						case 0: {
							break;
						}
						case 1: {
							money -= 100;
							printf("獲得 哭哭 二字\n找零： %d \n",money);
							break;
						}
						case 2: {
							money -= 100;
							printf("獲得 顆顆 二字\n找零： %d \n",money);						
							break;
						}
						case 3: {
							money -= 100;
							printf("獲得 廠廠 二字\n找零： %d \n",money);						
							break;
						}
						case 4: {
							money -= 100;
							printf("獲得 聒聒 二字\n找零： %d \n",money);
							break;
						}
						case 5: {
							money -= 100;
							printf("獲得 喵喵 二字\n找零： %d \n",money);
							break;
						}
						case 11: {
							in = 'N';
							printf("找零： %d \n",money);
							break;
						}
					}
				}
				else if ( money >= 200)
				{
					printf("可購買：01 - 哭哭 $100 02 - 顆顆 $100 03 - 廠廠 $100 04 - 聒聒 $100 05 - 喵喵 $100\n        06 - 旺旺 $200 07 - 啾啾 $200 08 - 尻尻 $200 09 - 哈哈 $200 10 - 雞雞 $200\n");
					printf("再投幣請先輸入 0 \n離開請輸入11\n");
					scanf("%d",&h);
					switch ( h )
					{
						case 0: {
							break;
						}
						case 1: {
							money -= 100;
							printf("獲得 哭哭 二字\n找零： %d \n",money);
							break;
						}
						case 2: {
							money -= 100;
							printf("獲得 顆顆 二字\n找零： %d \n",money);						
							break;
						}
						case 3: {
							money -= 100;
							printf("獲得 廠廠 二字\n找零： %d \n",money);						
							break;
						}
						case 4: {
							money -= 100;
							printf("獲得 聒聒 二字\n找零： %d \n",money);
							break;
						}
						case 5: {
							money -= 100;
							printf("獲得 喵喵 二字\n找零： %d \n",money);
							break;
						}
						case 6: {
							money -= 200;
							printf("獲得 旺旺 二字\n找零： %d \n",money);
							break;
						}
						case 7: {
							money -= 200;
							printf("獲得 啾啾 二字\n找零： %d \n",money);
							break;
						}
						case 8: {
							money -= 200;
							printf("獲得 尻尻 二字\n找零： %d \n",money);
							break;
						}
						case 9: {
							money -= 200;
							printf("獲得 哈哈 二字\n找零： %d \n",money);
							break;
						}
						case 10: {
							money -= 200;
							printf("獲得 雞雞 二字\n找零： %d \n",money);
							break;
						}
						case 11: {
							in = 'N';
							printf("找零： %d \n",money);
							break;
						}
					}
				}
			}			
		}
		else
		{
			break;
		}
	}while( in != 'N' && in != 'n');
}
