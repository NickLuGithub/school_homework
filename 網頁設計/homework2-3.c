//姓名:鍾喬如
//學號:b10702042
//檔名:homework2-1
//編譯器:Dev-c++
//日期:108.11.19 


#include <stdio.h>
#include <complex.h> 
#include <math.h>
#include <time.h>

double fact(double n) //副程式 fact 
{
	double f = 1;
	//宣告 f = 1 
	for (int i = 1; i <= n; i++) f *= i;
	// i = 1 i <= n 時，f = f * i，每執行一次 i + 1 直到 i > n 跳出迴圈 
	return f;
	//匯出 f 
} 

double sine(double x, double n) //副程式 sine 
{
	double sum = 0;
	//宣告 sum = 0
	for (int i = 0; i <= n; i++) sum +=  pow( -1, i) * pow( x, (2 * i + 1)) / fact(2 * i + 1);
	// i = 1 i <= n 時，sum = sum +  -1^i * x^(2 * i + 1) / fact(2 * i + 1) => (把 2 * i + 帶到 fact 副程式中計算)，每執行一次 i + 1 直到 i > n 跳出迴圈 
	return sum;
	//匯出 sum 
}

int main(void) 
{
	double x, n;
	// 宣告  x, n
	printf("Enter x, n: ");
	//印出 Enter x, n:
	scanf("%lf%lf", &x, &n);
	//輸入 x, n
	printf("sin(%lf) = %.20lf\n", x, sin(x));
	//印出 sin(x) = 
	printf("sine(%lf) = %.20lf\n", x, sine(x, n));
	//印出 sine(x) = 

}
