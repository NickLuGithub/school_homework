// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk2-4.cpp
// Compiler�GDev C++
// Date�G2018/11/09
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char a( double a,double b)
{
	if ( a == 1 && b == 2 || a == 2 && b == 3 || a == 3 && b == 1)
	{
		return 1;
	}
	else if ( a == 1 && b == 1 || a == 2 && b == 2 || a == 3 && b == 3)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int main ( void )
{
	srand(time(0));
	int Your = 0, Comp = 0,k = 1;
	printf("===========================================\n");
	printf("Welcome to the stone-scissor-paper game!\n");
	printf("===========================================\n");
	printf("Your wager:");
	scanf("%d", &Your);
	Comp = Your;
	int n_y = 0, n_c = 0;
	while ( Your != 0 && Comp != 0 && k != 0)
	{
		int in;
		printf("Your wager: %d\n", Your);
		printf("Computer's wager: %d\n", Comp);
		printf("Your choice (1. stone 2. scissor 3. paper):");
		scanf("%d", &in);
		switch ( a(in,rand()%3+1))
		{
			case 1:{
				printf("You win once.\n");
				n_y++;
				break;
			}
			case 2:{
				printf("Computer wins once.\n");
				n_c++;
				break;
			}
			case 3:{
				printf("Try again.\n");
				break;
			}
			default:{
				printf("��J���~\n");
				break;
			}
		}
		if ( n_y == 2)
		{
			Your += 20;
			Comp -= 20;
			n_y = 0;n_c = 0;
			printf("�O�_�~��C��(�~�� 1/���} 0)\n");
			scanf("%d", &k);
		}
		else if ( n_c == 2)
		{
			Your -= 20;
			Comp += 20;
			n_y = 0;n_c = 0;
			printf("�O�_�~��C��(�~�� 1/���} 0)\n");
			scanf("%d", &k);
		}
	}
	if ( Comp == 0)
	{
		printf("�q���S�N����!\n");
		printf("Your win.\n");		
	}
	else if ( Your == 0)
	{
		printf("�A�S�N����!\n");
		printf("Computer win.\n");
	}
	else
	{
		printf("�q���Ѿl�N��%d\n", Comp);
		printf("�A�Ѿl���N��%d\n", Your);
	}
}
