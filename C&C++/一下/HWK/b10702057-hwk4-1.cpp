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

void add(Element a[], Element b[], Element out[], int n1, int n2, int k){
	
	Element *c;
	int t = 0;
	c = new Element[n1 + n2];
	
	for (int i = 0; i < n1; i++){
		c[i].n = a[i].n;
		c[i].x = a[i].x;
	}
	for (int i = n1; i < n2; i++){
		c[i].n = b[i].n;
		c[i].x = b[i].x;
	}
	
	for (int i = 0; i < (n1 + n2); i++){ //eaer
		for (int l = 0; l < (n1 + n2) - i - 1; l++){
			if(c[i].n < c[l].n){
				Element t = c[i];
				c[i] = c[l];
				c[l] = t;
			}
		}
	}
	
	for (int i = 0, q = 0; i < (n1 + n2) - 1; i++, q++){
		if (c[i].n > c[i + 1].n){
			out[q].n = c[i].n;
			out[q].x = c[i].x;
		}
		else if (c[i].n == c[i + 1].n){
			out[q].n = c[i].n;
			out[q].x = c[i].x + c[i + 1].x;
			i++;
		}
		else{
			out[q].n = c[i].n;
			out[q].x = c[i].x;
		}
	}
}

int add_n(Element a[], Element b[], int n1, int n2){
	int k;
	if ( n1 < n2){
		int t = n1;
		n1 = n2;
		n2 = t;
	}
	for ( int i = 0; i < n1 - 1; i++){
		for (int j = 0; j < n2 - 1; j++){
			if (a[i].n == b[j].n){
				k++;
			}
			else if(a[i].n > b[j].n){
				k++;
			}
		}
	}
	return k;	
}

int main ( void ) {
    Element *line, *a, *b, *c, *out;
    int n;
    string s;
	
	cout << "是否開始: ";
    while ( cin >> s){
        getchar();
		cout << "Enter two polynomials: ";
		
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
		
		cout << "=> ";
       	getline(cin, input);
       	int line_size_2;
       	line_size_2 = (input.size() + 1) / 4;
       	b = new Element[line_size_2];
       	t1 = strtok((char*)input.c_str(), " ");
       	t2 = strtok(NULL, " ");
       	b[0].x = atof(t1);
       	b[0].n = atoi(t2);
       	for ( int i = 1; i < line_size_2 ; i++){
    		char *sp1, *sp2;
    		sp1 = strtok(NULL, " ");
    		sp2 = strtok(NULL, " ");
    		b[i].x = atof(sp1);
    		b[i].n = atoi(sp2);
		}
		Polynomial ep2(line_size_2);
		ep2.setPolynomial(b, line_size_2);

		ep1.print_e(line_size_1);
		ep2.print_e(line_size_2);
		int add_size;
		add_size = add_n(a, b, line_size_1, line_size_2);
		Polynomial ep3(add_size);
		out = new Element[add_size];
		add(a, b, out, line_size_1, line_size_2, add_size);
		ep3.setPolynomial(out, add_size);
		ep3.print_e(add_size);
    }
}
