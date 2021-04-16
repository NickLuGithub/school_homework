// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex2.c
// Compiler：Dev C++
// Date：2018/09/17

#include<stdio.h>
#include<stdlib.h>

int main () {
	double a,b,c,x;
	printf("Enter A B C");
	scanf("%lf %lf %lf",&a,&b,&c);
	if ( a == 0 && b == 0){        //判斷是否為有效方程式 
		printf("此方程式無意義");
	}
	else if ( c == 0 || a == 0 || b == 0){     //判斷是否可構成面積 
		printf("此方程式與原點無法構成面積");
	}
	else{
		x = ( c/a ) * ( c/b ) * 2;  //算面積 
		if ( x < 0){     //讓負數轉正數 
			x *= -1;
		}
		printf("此方程式與原點所交面積為:%lf",x);
	}
}
