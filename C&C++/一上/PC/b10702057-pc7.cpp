// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc7.cpp
// Compiler¡GDev C++
// Date¡G2018/10/18
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ( void )
{
	int dice1 = 0, dice2 = 0, sum = 0;
	char ans = 'Y';
	
	srand(time(0));
	
	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
	sum = dice1 + dice2;
	printf("Guess dice sum > 6? (Y|N) ");
	
	if (( ans = getchar()) == 'Y' || ans == 'y')
	{
		if ( sum > 6) printf("Correct!\n");
		else printf("Wrong!\n");
	}
	else
	{
		if ( sum < 6) printf("Correct!\n");
		else printf("Wrong!\n");
	}
	printf("dice1 = %d, dice2 = %d, sum = %d\n", dice1, dice2, sum);
}
