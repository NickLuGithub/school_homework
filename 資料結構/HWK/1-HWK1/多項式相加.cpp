#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct{
	double c, x;
}Polynomial;

int toPolynomial(char a[100], Polynomial in[20]){  //strtok and atoi and retun n
	int n = 0;
	char *sp, *deter = " ";
	in[0].c = atof(strtok(a, deter));
	in[0].x = atof(strtok(NULL, deter));
	n++;
	while((sp = strtok(NULL, deter)) != NULL){
		in[n].c = atof(sp);
		sp = strtok(NULL, deter);
		in[n].x = atof(sp);
		n++;
	}
	return n;
}

void PrintPolynomial(Polynomial out[20], int n){
	for ( int i = 0; i < n; i++){
		if(out[i].x != 0 && out[i].x != 1){
			if (out[i+1].c > 0){
				cout << out[i].c << "x^" << out[i].x << "+";
			}else{
				cout << out[i].c << "x^" << out[i].x;
			}
		}
		else{
			if(out[i].x == 1){
				if (out[i+1].c > 0){
					cout << out[i].c << "x+";
				}else{
					cout << out[i].c << "x";
				}
			}
			if(out[i].x == 0){
				if (out[i].c != 0){
					cout << out[i].c;
				}
			}
		}
	}
	cout << endl;
	
/*	for(int i = 0; i < n - 1; i++){
		if(out[i + 1].c > 0 && out[i].c != 0 && out[i+1].x != 0){
			if(out[i].c == 1 && out[i].x != 1){
				cout << "x^" << out[i].x << "+";
			}
			else if (out[i].c != 1 && out[i].x != 1){
				cout << out[i].c << "x^" << out[i].x << "+";
			}
			else {
				cout << out[i].c << "x+";
			}
			
		}else if((out[i + 1].c < 0 || out[i+1].x == 0) && out[i].c != 0 ){
			if(out[i].c == 1 && out[i].x != 1){
				cout << "x^" << out[i].x ;
			}
			else if(out[i].c != 1 && out[i].x != 1){
				cout << out[i].c << "x^" << out[i].x ;
			}
			else{
				cout << out[i].c << "x";
			}
		}
		
	}
	if (out[n-1].c > 0 && out[n-1].c < 0){
		cout << endl;
	}
	else{
		cout << out[n - 1].c << endl;
	}*/
}

void InOpenDate(char CharIn[100], char AB){
	fstream InF;
	int n = 0;                                                                            
	char FName[20], ch;  //FName = 檔名
	cout << "輸入" << AB << "方程式檔名:\n";
	cin >> FName;
	InF.open(FName, ios::in);
	if(!InF){
		cout << "檔案無法開啟\n";
	}else{
		while(InF.get(ch)){
			CharIn[n] = ch;
			n++;
		}
		InF.close();
	}
}

int addPolynomial(Polynomial a[20], Polynomial b[20], Polynomial c[20], int na, int nb){ //no GO
	int nc = 0, an = 0, bn = 0;
	while(an < na && bn < nb){
		if(a[an].x > b[bn].x){
			c[nc].c = a[an].c;
			c[nc].x = a[an].x;
			an++;
		}else if(a[an].x < b[bn].x){
			c[nc].c = b[bn].c;
			c[nc].x = b[bn].x;
			bn++;
		}else if(a[an].x == b[bn].x){
			c[nc].c = a[an].c + b[bn].c;
			c[nc].x = a[an].x;
			an++;
			bn++;
		}
		nc++;
	}
	return nc;
}

int main( void ){
	int na, nb, outn;
	Polynomial inA[20], inB[20], out[20];
	char ca[100], cb[100];
	
	InOpenDate(ca, 'A');
	InOpenDate(cb, 'B');
	na = toPolynomial(ca, inA);
	nb = toPolynomial(cb, inB);
	PrintPolynomial(inA, na);
	PrintPolynomial(inB, nb);
	outn = addPolynomial(inA, inB, out, na, nb);
	PrintPolynomial(out, outn);
	system("pause");
}
