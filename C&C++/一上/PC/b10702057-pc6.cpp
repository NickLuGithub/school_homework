// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-pc6.cpp
// Compiler�GDev C++
// Date�G2018/10/15

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ( void )
{
	int number, guess;
	srand ( time ( 0 ));
	number = rand ( ) % 10 + 1;
	printf ("��J1~10���@�Ӽ�:\n");
	do {
		scanf("%d", &guess);
		if (guess == number) printf ("����F");
		else if (guess > number) printf ("�Ӥj�F�A�A��@��");
		else printf("�Ӥp�F�A�A��@��");
	}while ( guess != number);
}
