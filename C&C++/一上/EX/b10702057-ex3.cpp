// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex3.cpp
// Compiler：Dev C++
// Date：2018/10/01

#include<stdio.h>
#include<stdlib.h> 

int main ( void ){
	int  a, b, c, d;                 // 宣告 IN
	int  out_x, out_y, out_ans;      // 宣告 OUT 
	printf("Enter two points: \n");   
	scanf("%d %d %d %d", &a, &b, &c, &d);   // 導入兩個數 
	if ( b - d == 0 && c - a == 0)          // 排除無法變成線的點 
	{
		printf("The line cannot be formed.\n");
	}
	else
	{
		out_x = b - d;                      // 計算線方程式 
		out_y = c - a;
		out_ans = a * (b - d) + b * (c - a);
		for ( int o = 2; o <= out_x; o++)
		{
			if ( ( out_x % o ) == 0 && (  out_y % o ) == 0 && ( out_ans % o ) == 0)        // 約分 
			{
				if ( ( out_x / o ) != 0 && ( out_y / o ) != 0 && ( out_ans / o ) != 0)
				{
					out_x = out_x / o;
					out_y = out_y / o;
					out_ans = out_ans / o;					
				}
			}
		} 
		printf("The line is ： %dx + %dy = %d\n", out_x, out_y, out_ans);               // 輸出答案 
	}
}
