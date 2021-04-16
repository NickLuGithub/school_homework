// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex2.cpp
// Compiler：Dev C++
// Date：2019/03/12

#include<stdio.h>
#include<stdlib.h>
#define LEN 30
#define SIZE 50

typedef struct {
	char name[LEN];
	char course[LEN];
	unsigned short score;
} Record;

Record max(Record r[], int n) {
	int t = 0;
	for ( int i = 0; i < n; i++) {
		if ( t < r[i].score) {
			t = r[i].score;
		}
	}
	for ( int l = 0; l < n; l++) {
		if ( t == r[l].score) {
			printf("%s %s %hu 為最高分成績\n", r[l].name, r[l].course, r[l].score);
		}
	}
}
 
int main(void) {
 
	Record r[SIZE];
	int len, n;
	
	printf("Enter the number of student: ");
	scanf("%d", &n);
	
	for ( int i = 0; i < n; i++) {
		printf("Enter the name: ");
		getchar();
		fgets(r[i].name, 30, stdin);
		len = strlen(r[i].name);
		r[i].name[len - 1] = '\0';
		printf("Enter the course: ");
		fgets(r[i].course, LEN, stdin);
		len = strlen(r[i].course);	
		r[i].course[len - 1] = '\0';
		printf("Enter the score: ");
		scanf("%hu", &r[i].score);	
	}
	
	printf("成績表單\n");
	for ( int k = 0; k < n; k++) {
		printf("%s %s %hu\n", r[k].name, r[k].course, r[k].score);
	}
	
	max(r, n);
}
