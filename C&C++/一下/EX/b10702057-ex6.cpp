// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex6.cpp
// Compiler：Dev C++
// Date：2019/04/11
#include<iostream>
using namespace std;

typedef struct {  //建構結構 
	double n, d;
} Fraction;

int gcd(Fraction a){   //GCD 
	int r = 1;
	while ( r != 0) {
		r = (int)a.n % (int)a.d;
		a.n = a.d;
		a.d = r;
	}
	return a.n;
}


void fa(Fraction a, Fraction b){   // 判斷是否相等 
	if (a.n * b.d - b.n * a.d == 0){
		printf("%.2lf / %.2lf == %.2lf / %.2lf\n", a.n, a.d, b.n, b.d);
	}else {
		printf("%.2lf / %.2lf != %.2lf / %.2lf\n", a.n, a.d, b.n, b.d);
	}
}

Fraction fb(Fraction a){           // 約分 
	int k = gcd(a);
	a.n /= k;
	a.d /= k;
	return a;
}

Fraction fc(Fraction a, Fraction b){   // 相加 
	Fraction k;
	k.n = a.n * b.d + b.n * a.d;
	k.d = a.d * b.d;
	return fb(k);
}

Fraction fd(Fraction a, Fraction b){   // 相成 
	Fraction k;
	k.n = a.n * b.n;
	k.d = a.d * b.d;
	return fb(k);
}
int main ( void ) {
	Fraction a, b, k, o;
	
	cout << "Enter two fraction numbers: ";
	scanf("%lf / %lf %lf / %lf", &a.n, &a.d, &b.n, &b.d);
	
	fa(a, b);
	k = fc(a, b);
	printf("%.2lf / %.2lf + %.2lf / %.2lf = %.2lf / %.2lf\n", a.n, a.d, b.d, b.d, k.n, k.d);
	k = fd(a, b);
	printf("%.2lf / %.2lf * %.2lf / %.2lf = %.2lf / %.2lf\n", a.n, a.d, b.d, b.d, k.n, k.d);
}
