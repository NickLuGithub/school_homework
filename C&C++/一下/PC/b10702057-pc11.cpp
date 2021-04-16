// Student No.：B10702057  Name：盧昱達 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>
using namespace std;

#define SIZE 100

void random_array(int a[]) {
	for (int i = 0; i < 25; i++) {
		a[i] = rand() % 25 + 1;
		for (int j = 0; j < i; j++){
			if (a[i] == a[j]) {
			--i;
			break;
			}
		}
	}
}
void print_array(int a[], int b[]) {
	for (int i = 0; i < 25; i++){
		if ( (i + 1 )% 5 == 0 && b[i] == 0){
			printf("%2d\n", a[i]);
		}	
		else if ( b[i] == 0){
			printf("%2d ", a[i]);
		}
		else if ( (i + 1 )% 5 == 0 && b[i] != 0){
			printf(" *\n");
		}
		else {
			printf(" * ");
		}
	}
}

void cin_numbers(int a[], int n){
	for ( int i = 0; i < n; i++){
		cin >> a[i];
		for (int j = 0; j < i; j++){
			if (a[i] == a[j] || a[i] < 1 || a[i] > 25) {
				--i;
				break;
			}
		}
	}
}

void crak(int a[], int b[], int k[], int n){
	for ( int i = 0; i < 25; i++){
		for ( int q = 0; q < n; q++){
			if ( a[i] == k[q]){
				b[i] = 1;
			}
		}
	} 
}

int line(int b[]){
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		if ( b[i * 5 + 0] == 1 && b[i * 5 + 1] == 1 && b[i * 5 + 2] == 1 && b[i * 5 + 3] == 1 && b[i * 5 + 4] == 1){
			total++;
		}
		if ( b[i] == 1 && b[i + 5] == 1 && b[i + 10] == 1 && b[i + 15] == 1 && b[i + 20] == 1){
			total++;
		}
	}
	/*  0  1  2  3  4
	 *  5  6  7  8  9
	 *  10 11 12 13 14
	 *  15 16 17 18 19
	 *  20 21 22 23 24 */  
	if ( b[0] == 1 && b[6] == 1 && b[12] == 1 && b[18] == 1 && b[24] == 1) total++;
	if ( b[0] == 4 && b[8] == 1 && b[12] == 1 && b[16] == 1 && b[20] == 1) total++;
	return total;
}

int main ( void ){
	int a[SIZE], b[SIZE] = {0}, k[SIZE], n;
	srand(time(0));
	
	random_array(a);
	print_array(a, b);
	
	cout << "Enter n :";
	cin >> n;
	cout << "Enter " << n << " numbers between 1 and 25: ";
	cin_numbers(k, n);
	crak(a, b, k, n);
	print_array(a, b);
	cout << "有 "<< line(b) <<"幾條連在一起\n";
	
}
