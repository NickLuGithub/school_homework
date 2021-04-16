// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk3-3.cpp
// Compiler：Dev C++
// Date：2018/11/22
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int name = 0, point = 0, total = 0;
	char option, go;
	srand(time(0));

	do
	{
		
		printf("=======================================================\n");
		printf("Guesses Choice:\n");
		printf("O-Odd E-Even L-Low M-Medium H-High N-Number\n");
		printf("=======================================================\n");
		printf("Enter your choice: ");
		scanf("%c", &option);
		getchar();  // get the carriage return "\n"
		name = rand() % 12 + 1;
		
		switch (option)
		{

			case 'O': case 'o':{
				printf("Odd number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name % 2 == 0)
				{
					printf("數字是%d猜對了喔!獲得%d點數\n", name, point*2);
					total += point*2;
				}
				else
				{
					printf("數字是%d", name);
					printf("再接再厲\n");
				}
				break;
			}
			case 'E': case 'e':{
				printf("Even number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name % 2 == 1)
				{
					printf("數字是%d猜對了喔!獲得%d點數\n", name, point*2);
					total += point*2;
				}
				else
				{
					printf("數字是%d", name);
					printf("再接再厲\n");
				}
				break;
			}
			case 'L': case 'l':{
				printf("Low number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name >= 1 && name <= 4 )
				{
					printf("數字是%d猜對了喔!獲得%d點數\n", name, point*3);
					total += point*3;
				}
				else
				{
					printf("數字是%d", name);
					printf("再接再厲\n");
				}
				break;
			}
			case 'M': case 'm':{
				printf("Medium number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name >= 5 && name <= 8 )
				{
					printf("數字是%d猜對了喔!獲得%d點數\n", name, point*3);
					total += point*3;
				}
				else
				{
					printf("數字是%d", name);
					printf("再接再厲\n");
				}
				break;
			} 
			case 'H': case 'h':{
				printf("High number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name >= 9 && name <= 12 )
				{
					printf("數字是%d猜對了喔!獲得%d點數\n", name, point*3);
					total += point*3;
				}
				else
				{
					printf("數字是%d", name);
					printf("再接再厲\n");
				}
				break;
			}
			case 'N': case 'n':{
				printf("A number\n");
				int number;
				scanf("%d", &number);
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( number == name)
				{
					printf("數字是%d猜對了喔!獲得%d點數\n", name, point*12);
					total += point*12;
				}
				else
				{
					printf("數字是%d", name);
					printf("再接再厲\n");
				}
				break;
			}
			default:{
				printf("Try again!\n");
			}
        
    	}
	printf("Continue (Y/N)? ");
	scanf("%s", &go);
	getchar();  // get the carriage return "\n"
	}while (go == 'Y' || go == 'y');
	printf("總獲得遊戲幣%d", total);
}
