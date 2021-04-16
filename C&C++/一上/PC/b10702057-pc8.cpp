// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc8.cpp
// Compiler¡GDev C++
// Date¡G2018/10/18
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sum() {
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	return dice1 + dice2;
}

int main ( void )
{
	int comp = 0, play = 0;
	srand(time(0));
	
	printf("Roll the dices? ");
	getchar();
	comp = sum();
	play = sum();
	
	if ( play > comp ) printf("The player wins.\n");
	else if ( play < comp )printf("The computer wins.\n");
	else printf("The play and the computer draw the game.\n");
}
