// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex2.c
// Compiler�GDev C++
// Date�G2018/09/17

#include<stdio.h>
#include<stdlib.h>

int main () {
	double a,b,c,x;
	printf("Enter A B C");
	scanf("%lf %lf %lf",&a,&b,&c);
	if ( a == 0 && b == 0){        //�P�_�O�_�����Ĥ�{�� 
		printf("����{���L�N�q");
	}
	else if ( c == 0 || a == 0 || b == 0){     //�P�_�O�_�i�c�����n 
		printf("����{���P���I�L�k�c�����n");
	}
	else{
		x = ( c/a ) * ( c/b ) * 2;  //�⭱�n 
		if ( x < 0){     //���t���ॿ�� 
			x *= -1;
		}
		printf("����{���P���I�ҥ歱�n��:%lf",x);
	}
}
