#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define SIZE 6
#define LEN 100

void new_lottery(int lottery[], int n){
	srand(time(0));
	for (int i = 0; i < n;i++) {
		lottery[i] = rand() % 49 + 1;
		for ( int j = 0; j < i; j++) {
			if (lottery[i] == lottery[j]){
				--i;
				break;
			}
		}
	}
	printf("The lottery winning number are: ");
	for ( int i = 0; i < n; i++) printf("%d ", lottery[i]);
	puts("");
}

int count_star(int lottery[], int guess[], int n) {
	int star = 0;
	for ( int i = 0; i < n; i++){
		for ( int j = 0; j < n; j++) star += guess[i] == lottery[j] ? 1 : 0;
	}
	return star;
}

void read_guess(int a[], int n, char *line) {
	char *st;
	st = strtok(line, " ");
	a[0] = atoi(st);
	for (int i = 1; i < n; i++) {
		st = strtok(NULL, " ");
		a[i] = atoi(st);
	} 
}

int main ( void ){
	char *filename = "lottery.txt", line[LEN], *sp;
	int lottery[SIZE], guess[SIZE];
	FILE *fp;
	
	new_lottery(lottery, SIZE);
	if ((fp = fopen(filename, "r")) != NULL) {
		while (fgets(line, LEN, fp) != NULL) {
			if (isalpha(line[0])) printf("%s ", line);
			else {
				read_guess(guess, SIZE, line);
				for (int i = 0; i < SIZE; i++) printf("%d ", guess[i]);
				printf("%d stars\n", count_star(lottery, guess, SIZE));
			}
		}
		fclose(fp);
	}
	else printf("The %s cannot be open.", filename);
}
