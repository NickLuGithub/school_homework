// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk2-1.cpp
// Compiler�GDev C++
// Date�G2019/03/28
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LEN 100

typedef struct {
	char name[LEN];
	unsigned int score[3]; //�е��c 
} date;

double avge(date a) {
	return ((double)a.score[0] + (double)a.score[1] + (double)a.score[2]) / 3; //��H�T��Ҹե��� 
}

int main ( void ) {
	date a[LEN];
	FILE *fp;
	char infp[LEN], line[LEN], *sp;
	int i = 0;
	
	printf("Enter FILE name:");//��J�ҦW 
	scanf("%s", infp);
	if ((fp = fopen(infp, "r")) != NULL) { //strtok���άO�r�J�ɮ� 
		while(!feof(fp)) {
			fgets(line, LEN, fp);
			strcpy(a[i].name, strtok(line, ":"));
			for ( int p = 0; p < 3; p ++) {
				sp = strtok(NULL, " ");
				a[i].score[p] = atoi(sp);
			}
			i++;
		}
		printf("Student Name      English Calculus C++ Programming Average\n"); //��X�j�Φ��Z&���� 
		for ( int k = 0, f = i; k < f; k++) {
			printf("%17s   %3d     %3d     %3d             %3.2lf\n", a[k].name, a[k].score[0], a[k].score[1], a[k].score[2], avge(a[k]));
		}
		printf("-----------------------------------------------------------------\n");
		printf("Average             ");
		for ( int c = 0; c < 3; c++ ) { //�������� 
			int sum = 0;
			for ( int k = 0, f = i; k < f; k++){
				sum += a[k].score[c];
			}
			printf("%.2lf   ", ((double)sum) / i);
		}
		puts("");
		printf("Maximum              ");
		for ( int c = 0; c < 3; c++ ) { //�p����̰��� 
			int max = 0;
			for (int k = 0, f = i; k < f; k++) {
				if ( max < a[k].score[c]) {
					max = a[k].score[c];
				}
			}
			printf("%d      ", max);
		}
		puts("");
		printf("Minimum              ");
		for ( int c = 0; c < 3; c++ ) {//�p����̧C�� 
			int min = 100;
			for (int k = 0, f = i; k < f; k++) {
				if ( min > a[k].score[c]) {
					min = a[k].score[c];
				}
			}
			printf("%d      ", min);
		}
	}
	else{
		printf("The FILE cannot be opened.\n");
	}
}
