// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex3.cpp
// Compiler�GDev C++
// Date�G2018/10/01

#include<stdio.h>
#include<stdlib.h> 

int main ( void ){
	int  a, b, c, d;                 // �ŧi IN
	int  out_x, out_y, out_ans;      // �ŧi OUT 
	printf("Enter two points: \n");   
	scanf("%d %d %d %d", &a, &b, &c, &d);   // �ɤJ��Ӽ� 
	if ( b - d == 0 && c - a == 0)          // �ư��L�k�ܦ��u���I 
	{
		printf("The line cannot be formed.\n");
	}
	else
	{
		out_x = b - d;                      // �p��u��{�� 
		out_y = c - a;
		out_ans = a * (b - d) + b * (c - a);
		for ( int o = 2; o <= out_x; o++)
		{
			if ( ( out_x % o ) == 0 && (  out_y % o ) == 0 && ( out_ans % o ) == 0)        // ���� 
			{
				if ( ( out_x / o ) != 0 && ( out_y / o ) != 0 && ( out_ans / o ) != 0)
				{
					out_x = out_x / o;
					out_y = out_y / o;
					out_ans = out_ans / o;					
				}
			}
		} 
		printf("The line is �G %dx + %dy = %d\n", out_x, out_y, out_ans);               // ��X���� 
	}
}
