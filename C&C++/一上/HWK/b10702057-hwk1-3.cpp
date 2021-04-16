// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-hwk1-3.cpp
// Compiler¡GDev C++
// Date¡G2018/10/05

#include <stdio.h>

int main(void)
{
	double a, b, c, d;
	char op;
	
	printf("Enter the complex number expression: ");
  	scanf("(%lf + %lfi) %c  (%lf + %lfi)", &a, &b, &op, &c, &d);
  	
	if ( op == '-')
	{
		printf("(%lf + %lfi) %c (%lf + %lfi) = %lf + %lfi\n", a, b, op, c, d, a - c, b - d);
	}
	else if ( op == '+')
	{
		printf("(%lf + %lfi) %c (%lf + %lfi) = %lf + %lfi\n", a, b, op, c, d, a + c, b + d);
	}
	else if ( op == '*')
	{
		printf("(%lf + %lfi) %c (%lf + %lfi) = %lf + %lfi\n", a, b, op, c, d, a*c - b*d, b*c + a*d);
	}
	else if ( op == '/')
	{
		if ( c*c + d*d == 0)
		{
			printf("(%lf + %lfi) %c (%lf + %lfi) is undefined.", a, b, op, c, d);
		}
		else
		{
			printf("(%lf + %lfi) %c (%lf + %lfi) = %lf + %lfi\n", a, b, op, c, d, (a*c + b*d)/(c*c + d*d), (b*c - a*d)/(c*c + d*d));
		}
	}
}

