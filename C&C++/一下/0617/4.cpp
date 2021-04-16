// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk4-1.cpp
// Compiler：Dev C++
// Date：2019/04/04
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string> 
#include <algorithm>
#define LEN 1000
using namespace std;

typedef struct {
	double x;
	int n;        // x == x, a == 次方 
} Element;

class Polynomial {
	private:
		Element *line;
	public:
		Polynomial (int n) {
			line = new Element[n + 1];
		}
		void setPolynomial (Element _line[], int n){
            line = new Element[n];
            for ( int i = 0; i < n; i++) {
                line[i] = _line[i];
            }
		}
		
		void print_e(int n){
			for ( int i = 0; i < n ; i++){
				if ( i != n - 1) {
					cout << line[i].x << "^" << line[i].n << " + ";
			}
				else {
					cout << line[i].x << "^" << line[i].n;
				}
			}
		cout << endl;
		}
};

void print_ep(Element a[], int n){
	for ( int i = 0; i < n ; i++){
		if ( i != n - 1) {
			cout << a[i].x << "^" << a[i].n << " + ";
		}
		else {
			cout << a[i].x << "^" << a[i].n;
		}
	}
	cout << endl;
}

Polynomial add(Element a[], Element b[], int n1, int n2, int k){
	Element *c;
	c = new Element[k];
	for (int p = 0; p < k; p++){
		if (n1 > n2){
			for ( int i = n1 - 1, j = n2 - 1; i >= 0 ; i--){
				if ( a[i].n == b[j].n){
					j--;
					c[p].n = a[i].n;
					c[p].x = a[i].x + b[j].x;
				}
				else if (a[i].n > j + 1){
					c[p].n = a[i].n;
					a[p].x = a[i].x;
				}
				else if ( i + 1 > b[j].n){
					break;
				}
				else if ( i + 1 == b[j].n){
					j--;
					c[p].n = b[j].n;
					c[p].x = b[j].x;
				}
			}
		}
		else {
			for ( int i = n1 - 1, j = n2 - 1; j >= 0 ; j--){
				if ( a[i].n == b[i].n){
					i--;
				}
			}
		}
	}
	Polynomial w(k);
	w.setPolynomial(c, k);
	return w;
}

double wqe(Element k[], double x, double y, int size){
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += (k[i].x / (k[i].n + 1)) * pow(y, (k[i].n + 1)) - (k[i].x / (k[i].n + 1)) * pow(x, (k[i].n + 1));
	}
	return sum;
}
int main ( void ) {
    Element *line, *a, *b;
    int n;
    string s;
	
	cout << "是否開始: ";
    while ( cin >> s){
        getchar();
		cout << "Enter the polynomials: ";
		
        //先getline在strleny在strtok
        
       	string input;
       	
       	cout << "\n=> ";
       	getline(cin, input);
       	int line_size_1;
       	line_size_1 = (input.size() + 1) / 4;
       	a = new Element[line_size_1];
       	char *t1, *t2;
       	t1 = strtok((char*)input.c_str(), " ");
       	t2 = strtok(NULL, " ");
       	a[0].x = atof(t1);
       	a[0].n = atoi(t2);
       	for ( int i = 1; i < line_size_1 ; i++){
    		char *sp1, *sp2;
    		sp1 = strtok(NULL, " ");
    		sp2 = strtok(NULL, " ");
    		a[i].x = atof(sp1);
    		a[i].n = atoi(sp2);
		}
		Polynomial ep1(line_size_1);
		ep1.setPolynomial(a, line_size_1);
		ep1.print_e(line_size_1);
		double x, y;
		cout << "Enter a and b for intergration:";
		cin >> x >> y;
		b = new Element[line_size_1];
		cout << "The integral of the polynomial is " << wqe(a, x, y, line_size_1);
    }
}
