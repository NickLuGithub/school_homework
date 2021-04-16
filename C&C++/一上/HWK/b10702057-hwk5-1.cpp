#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

void char_array(char a[], int *n)
{
	printf("Enter n:");
	scanf("%d", &*n);

	for ( int i = 0; i == '\n', i++)
	{
		scanf("%c", a[i]);
	}
	a[i] = '\0';
}

void print_array(char a[])
{
	printf("%s", a);
}

void cage(char a[])
{
	
}
int main ( void )
{
	int n,word;
	char a[SIZE], word;
	
	srand(time(0));
	char_array(a, &n);
	
	word = rand () % n + 1;
	
	 
}
