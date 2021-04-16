//學號:B10702057  姓名:盧昱達
//檔名:b10702057-ex1.c
//編譯器:Dev C++
//日期:2019/02/25
#include <stdio.h>

typedef struct {
	double x, y, z; 
} Vector;

Vector sum(Vector a, Vector b) {
	Vector v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return v;
}

void chark(Vector a, Vector b) {
	if ( ( a.x == 0 && a.y == 0 && a.z == 0) || ( b.x == 0 && b.y == 0 && b.z == 0))
	{
		printf("是否相同向量 : No.\n");
	}
	else if ( a.x / b.x == a.y / b.y && a.y / b.y == a.z / b.z && a.y / b.y == a.z / b.z)
	{
		printf("是否相同向量 : Yes.\n");
	}
	else
	{
		printf("是否相同向量 : No.\n");
	}
}

double IP(Vector a, Vector b)
{
	double sum;
	sum = a.x * b.x + a.y * b.y + a.z * b.z;
	return sum;
}
int main(void) {
	Vector a, b, v;
	
	printf("Enter a vector: ");
	scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);
	v = sum (a, b);
	printf("a + b = (%f, %f, %f)\n", v.x, v.y, v.z);
	printf("a . b = %lf\n", IP(a, b));
	chark (a, b);
}
