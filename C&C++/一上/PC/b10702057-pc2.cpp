// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-pc2.cpp
// Compiler�GDev C++
// Date�G2018/09/20


#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main (){
	double a,b,c,s;
	cin >> a >> b >> c;
	if ( a + b > c && b + c > a && a + c > b){
		s = ( a + b + c) / 2;
		cout << "���T���έ��n" << sqrt( s * ( s - a) * ( s - b) * ( s - c)) << endl;		
	}
	else {
		cout << "���T��L�k�c���T����" << endl;
	}
	return 0;
}
