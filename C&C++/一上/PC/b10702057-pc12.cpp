// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc12.cpp
// Compiler¡GDev C++
// Date¡G2018/11/19
#include <stdio.h>
#define SIZE 100

void read_array(int a[], int n)
{
	for (int i=0;i<n;i++) scanf("%d", &a[i]);
}
void print_array(int a[], int n)
{
	for (int i=0;i<n;i++) printf("%d ", a[i]);
	puts("");
}
void selection_sort(int a[], int n){
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
  		if(a[i]>a[j])
		{
   			int temp=a[i];
   			a[i]=a[j];
   			a[j]=temp;
		}
	}
}
void bubble_sort(int a[], int n){
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
  			if (a[j]>a[j+1])
			{
   				int temp=a[j];
   				a[j]=a[j+1];
   				a[j+1]=temp;
  			}
	}
}
int main(void)
{
	int a[SIZE], n;
 
	printf("Enter n: ");
	scanf("%d", &n);
 
	printf("Enter %d numbers: ", n);
	read_array(a, n);
	selection_sort(a, n);
	print_array(a, n);
 
	printf("Enter %d numbers: ", n);
	read_array(a, n);
	bubble_sort(a, n);
	print_array(a, n);
}
