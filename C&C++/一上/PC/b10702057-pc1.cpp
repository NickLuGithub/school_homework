#include<stdio.h>

int main(void){
	double a, b, c,qq = 0;
	printf("Enter a,b,c");
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("a = %f b = %f c = %f",a,b,c);\
	qq = (a+b+c)/3;
	printf("average = %f\n",qq);
}