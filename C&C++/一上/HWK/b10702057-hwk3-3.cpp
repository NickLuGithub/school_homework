// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk3-3.cpp
// Compiler�GDev C++
// Date�G2018/11/22
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
					printf("�Ʀr�O%d�q��F��!��o%d�I��\n", name, point*2);
					total += point*2;
				}
				else
				{
					printf("�Ʀr�O%d", name);
					printf("�A���A�F\n");
				}
				break;
			}
			case 'E': case 'e':{
				printf("Even number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name % 2 == 1)
				{
					printf("�Ʀr�O%d�q��F��!��o%d�I��\n", name, point*2);
					total += point*2;
				}
				else
				{
					printf("�Ʀr�O%d", name);
					printf("�A���A�F\n");
				}
				break;
			}
			case 'L': case 'l':{
				printf("Low number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name >= 1 && name <= 4 )
				{
					printf("�Ʀr�O%d�q��F��!��o%d�I��\n", name, point*3);
					total += point*3;
				}
				else
				{
					printf("�Ʀr�O%d", name);
					printf("�A���A�F\n");
				}
				break;
			}
			case 'M': case 'm':{
				printf("Medium number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name >= 5 && name <= 8 )
				{
					printf("�Ʀr�O%d�q��F��!��o%d�I��\n", name, point*3);
					total += point*3;
				}
				else
				{
					printf("�Ʀr�O%d", name);
					printf("�A���A�F\n");
				}
				break;
			} 
			case 'H': case 'h':{
				printf("High number\n");
				printf("Point at risk: ");
				scanf("%d", &point);
				if ( name >= 9 && name <= 12 )
				{
					printf("�Ʀr�O%d�q��F��!��o%d�I��\n", name, point*3);
					total += point*3;
				}
				else
				{
					printf("�Ʀr�O%d", name);
					printf("�A���A�F\n");
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
					printf("�Ʀr�O%d�q��F��!��o%d�I��\n", name, point*12);
					total += point*12;
				}
				else
				{
					printf("�Ʀr�O%d", name);
					printf("�A���A�F\n");
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
	printf("�`��o�C����%d", total);
}
