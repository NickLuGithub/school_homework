#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 52

typedef struct {
	int rank, suit;
} PokerCard;

void random_array(int a[], int n) {
	for ( int i = 0; i < n; i++) {
		a[i] = rand() % n;
		for ( int j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				--i;
				break;
			}
		}
	}
}

int main ( void ) {
	int a[SIZE];
	PokerCard poker[SIZE];
	char rank[] = "23456789tjqka", suit[] = "cdhs";
	
	srand(time(0));
	random_array(a, SIZE);
	for ( int i = 0; i < SIZE; i++) {
		poker[i].rank = rank[a[i] % 13];
		poker[i].suit = suit[a[i] / 13];
		printf("%c%c ", poker[i].rank, poker[i].suit);
		if((i + 1) % 13 == 0) puts("");
	}
}
