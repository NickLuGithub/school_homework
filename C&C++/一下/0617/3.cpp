#include<iostream>
#include<sstream>
#include<ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void random_array(char *a, int n){
	for (int i = 0; i < n; i++){
		a[i] = 'A' + rand() % 24;
	}
}

void oooo(int a[], int n){
	for ( int i = 0; i < n; i++) a[i] == 0;
}

void print(char a[], int n){
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}cout << endl;
}

void print_array(char a[], int b[], int n, int m){
	for ( int i = 0; i < (m * n) ; i++) {
		if ( (i+1) % n == 0 && b[i] == 0) {
			cout << " * " << endl;
		}else if ((i+1) % n == 0 && b[i] == 1){
			cout << " " << a[i] << " "<< endl;
		}else if (b[i] == 0) {
			cout << " * ";
		}else{
			cout << " " << a[i] << " ";
		}
	}
}

int lala(int a,int b,int m){
	return (a - 1) * m + (b - 1);
}

int qqqq(int b[], int n){
	for ( int i = 0; i < n; i++){
		if ( b[i] == 0) return 0;
	}return 1;
}
int main(void) {
	srand(time(0));
	int n, m, ptotal = 0, ctotal = 0;
	char *a;
	int *b;
	cout << "Enter m, n:";
	cin >> m >> n;
	a = new char[n * m];
	for ( int i = 0; i < n * m; i++){
		a[i] = 0;
	}	
	b = new int[n * m];
	for ( int i = 0; i < (n* m); i++){
		b[i] = 0;
	}
	oooo(b, n* m);
	random_array(a, n * m);
	int pn, pm, p2n, p2m, c1, c2;
	do{
		print_array(a, b, n, m);
		int out = 0, k = 0;
		do{
			do{
			cout << "Enter your pick: ";
			cin >> pm >> pn;
			}while (pn < 0 || pm < 0 || b[lala(pm, pn, n)] == 1 || k == 1);
			b[lala(pm, pn, n)] = 1;
			print_array(a, b, n, m);
			do{
				cout << "Enter your pick: ";
				cin >> p2m >> p2n;
			}while (p2n < 0 || p2m < 0 || b[lala(p2m, p2n, n)] == 1);
			b[lala(p2m, p2n, n)] = 1;
			print_array(a, b, n, m);
			if (a[lala(pm, pn, n)] > a[lala(p2m, p2n, n)]){
				out = 0;
				ptotal += a[lala(pm, pn, n)];
			}
			else{
				ptotal += a[lala(pm, pn, n)] + a[lala(p2m, p2n, n)];
				out = 1;
			}
		}while (out == 0);
		int put = 0;
		do{
			do{
			c1 = rand () % (n * m) + 1; 
			}while (b[c1] == 1);
			b[c1] = 1;
			print_array(a, b, n, m);
			do{
				c2 = rand() % (n * m) + 1;
			}while (b[c2] == 1);
			b[c2] = 1;
			print_array(a, b, n, m);
			if (a[c1] > a[c2]){
				put = 0;
				ctotal += a[c1];
			}else{
				put = 1;
				ctotal += a[c1] + a[c2];
			}
		}while (put == 0);
	}while (qqqq(b, n * m) == 0);
	
	if ( ptotal > ctotal){
		cout << "你贏了共獲得: " << ptotal << endl;
		cout << "電腦獲得: " << ctotal << endl; 
	}else{
		cout << "電腦螢了獲得: " << ctotal << endl;
		cout << "你獲得: " << ptotal << endl; 
	}
}
