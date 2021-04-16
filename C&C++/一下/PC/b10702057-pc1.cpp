#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int read_array(double a[])
{
	char line[SIZE], *st;
	int n = 0;
	
	printf("Enter numbers: ");
	fgets(line, SIZE - 1, stdin);
	st = strtok(line, " ");
	a[0] = atof(st);
	while((st = strtok(NULL, " "))!= NULL){
		a[++n] = atof(st);
	}
	return n + 1;
}

void print_array(double a[], int n) {
	printf("The numbers are: ");
	for ( int i = 0; i < n; i++) printf("%f ", a[i]);
	puts("");
}

double avg_array(double a[], int n){
	double sum = 0;
	for (int i = 0; i < n;i++) sum += a[i];
	return sum / n;
}

int main ( void ){
	double a[SIZE];
	int n = read_array(a);
	
	print_array(a, n);
	printf("The average is %f.\n", avg_array(a, n));
}
