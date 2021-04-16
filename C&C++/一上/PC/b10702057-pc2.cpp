// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-pc2.cpp
// Compiler：Dev C++
// Date：2018/09/20


#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main (){
	double a,b,c,s;
	cin >> a >> b >> c;
	if ( a + b > c && b + c > a && a + c > b){
		s = ( a + b + c) / 2;
		cout << "此三角形面積" << sqrt( s * ( s - a) * ( s - b) * ( s - c)) << endl;		
	}
	else {
		cout << "此三邊無法構成三角形" << endl;
	}
	return 0;
}
