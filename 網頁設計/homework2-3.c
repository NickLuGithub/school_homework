//�m�W:���p
//�Ǹ�:b10702042
//�ɦW:homework2-1
//�sĶ��:Dev-c++
//���:108.11.19 


#include <stdio.h>
#include <complex.h> 
#include <math.h>
#include <time.h>

double fact(double n) //�Ƶ{�� fact 
{
	double f = 1;
	//�ŧi f = 1 
	for (int i = 1; i <= n; i++) f *= i;
	// i = 1 i <= n �ɡAf = f * i�A�C����@�� i + 1 ���� i > n ���X�j�� 
	return f;
	//�ץX f 
} 

double sine(double x, double n) //�Ƶ{�� sine 
{
	double sum = 0;
	//�ŧi sum = 0
	for (int i = 0; i <= n; i++) sum +=  pow( -1, i) * pow( x, (2 * i + 1)) / fact(2 * i + 1);
	// i = 1 i <= n �ɡAsum = sum +  -1^i * x^(2 * i + 1) / fact(2 * i + 1) => (�� 2 * i + �a�� fact �Ƶ{�����p��)�A�C����@�� i + 1 ���� i > n ���X�j�� 
	return sum;
	//�ץX sum 
}

int main(void) 
{
	double x, n;
	// �ŧi  x, n
	printf("Enter x, n: ");
	//�L�X Enter x, n:
	scanf("%lf%lf", &x, &n);
	//��J x, n
	printf("sin(%lf) = %.20lf\n", x, sin(x));
	//�L�X sin(x) = 
	printf("sine(%lf) = %.20lf\n", x, sine(x, n));
	//�L�X sine(x) = 

}
