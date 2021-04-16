// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc3.cpp
// Compiler¡GDev C++
// Date¡G2018/09/27

#include<stdio.h>

int main(){
	int n;
	printf("Enter n¡G ");
	scanf("%d",&n);
	int i = 1;
	double f = 1;
	while ( i <= n){
		f = f * i;
		i++;
	}
	printf("%d! = %.0f", n, f);
}
