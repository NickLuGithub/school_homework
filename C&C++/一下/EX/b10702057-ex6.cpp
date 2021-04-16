// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex6.cpp
// Compiler�GDev C++
// Date�G2019/04/11
#include<iostream>
using namespace std;

typedef struct {  //�غc���c 
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


void fa(Fraction a, Fraction b){   // �P�_�O�_�۵� 
	if (a.n * b.d - b.n * a.d == 0){
		printf("%.2lf / %.2lf == %.2lf / %.2lf\n", a.n, a.d, b.n, b.d);
	}else {
		printf("%.2lf / %.2lf != %.2lf / %.2lf\n", a.n, a.d, b.n, b.d);
	}
}

Fraction fb(Fraction a){           // ���� 
	int k = gcd(a);
	a.n /= k;
	a.d /= k;
	return a;
}

Fraction fc(Fraction a, Fraction b){   // �ۥ[ 
	Fraction k;
	k.n = a.n * b.d + b.n * a.d;
	k.d = a.d * b.d;
	return fb(k);
}

Fraction fd(Fraction a, Fraction b){   // �ۦ� 
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
