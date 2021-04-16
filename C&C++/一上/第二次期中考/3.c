#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100

void in_number(double a[], int n)
{
	printf("Enter %d numbers: ", n);
	for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
}

double sum(double a[], int n)
{
	double q = 0;
	for (int i = 0; i < n; i++) q += a[i] * a[i];
	q /= n;
	return sqrt(q); 
}

void bubble_sort(double a[], int n){
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
  			if (a[j]>a[j+1])
			{
   				double temp=a[j];
   				a[j]=a[j+1];
   				a[j+1]=temp;
  			}
	}
}
void print_array(double a[], int n)
{
	for (int i = 0; i < n; i++) printf("%lf ", a[i]);
	puts("");
}

int main (void)
{
	int n;
	double a[SIZE];
	printf("Enter n:");
	scanf("%d", &n);

	in_number(a,n);
	print_array(a, n);
	printf("The quadratic mean is %lf .\n", sum(a, n));
	printf("Sorting the array:");
	bubble_sort(a,n);
	print_array(a, n);
}
