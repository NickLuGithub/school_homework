// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-hwk1-1.cpp
// Compiler¡GDev C++
// Date¡G2019/03/14

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

typedef struct {
	double n, d;  // n / d
} fraction;

int gcd ( int a, int b) {
	int r;
	
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

fraction aec(fraction a) {
	int t = gcd(a.n, a.d);
	a.n /= t;
	a.d /= t;
	return a;
}

fraction total_a(fraction a, fraction b, char f) {
	fraction c;
	switch (f) {
		case '+': {
			c.n = ( a.n * b.d ) + ( b.n * a.d );
			c.d = a.d * b.d;
			c = aec(c);
			printf("%lf/%lf %c %lf/%lf = %lf/%lf", a.n, a.d, f, b.n, b.d, c.n, c.d);
			break;
		}
		case '-': {
			c.n = ( a.n * b.d ) - ( b.n * a.d );
			c.d = a.d * b.d;
			c = aec(c);
			printf("%lf/%lf %c %lf/%lf = %lf/%lf", a.n, a.d, f, b.n, b.d, c.n, c.d);
			break;
		}
		case '*': {
			c.n = a.n * b.n;
			c.d = a.d * b.d;
			c = aec(c);
			printf("%lf/%lf %c %lf/%lf = %lf/%lf", a.n, a.d, f, b.n, b.d, c.n, c.d);
			break;
		}
		case '/': {
			if ( b.n != 0)
			{
				c.n = a.n * b.d;
				c.d = a.d * b.n;
				c = aec(c);
				printf("%lf/%lf %c %lf/%lf = %lf/%lf", a.n, a.d, f, b.n, b.d, c.n, c.d);
			}
			else
			{
				printf("%lf/%lf %c %lf/%lf is undefined.", a.n, a.d, f, b.n, b.d);
			}
			break;
		}
	}
}

int main ( void ) {
	
	fraction a, b, c;
	char f;
	
	printf("Enter the fraction expression: ");
	scanf("%lf/%lf %c %lf/%lf", &a.n, &a.d, &f, &b.n, &b.d);
	total_a(a, b, f);
}
