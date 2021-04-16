// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-pc6.cpp
// Compiler：Dev C++
// Date：2018/10/15

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ( void )
{
	int number, guess;
	srand ( time ( 0 ));
	number = rand ( ) % 10 + 1;
	printf ("輸入1~10中一個數:\n");
	do {
		scanf("%d", &guess);
		if (guess == number) printf ("答對了");
		else if (guess > number) printf ("太大了，再輸一次");
		else printf("太小了，再輸一次");
	}while ( guess != number);
}
