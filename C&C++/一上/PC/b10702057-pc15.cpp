#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define SIZE 100

void random_array(int a[], int n) {
  for (int i = 0; i < n; i++) {
  	a[i] = rand() % n + 1;
  	for (int j = 0; j < i; j++)
  	  if (a[i] == a[j]) {
  	  	--i;
  	  	break;
	 }
  }
}
void print_array(int a[], int b[],  int n) {
  for (int i = 0; i < n; i++) 
    if (b[i] == 1) printf("%d ", a[i]);
    else printf("* ");
  puts("");
}

int is_over(int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (b[i] == 0) return 0;
	}
	return 1;
}
int main(void) {
  int n;
  srand(time(0));
  printf("Enter n: ");
  scanf("%d", &n);
  int a[SIZE], b[SIZE] = {0}, point = 0, total_point = 0, i;
  
  random_array(a, n);
  do
  {
  	printf("Numbers: ");
  	print_array(a, b, n);
  	do
  	{
  		printf("Pick a number: ");
  		scanf("%d", &i);
  		getchar();
	}
	while(b[i -1] > 0);
	b[i - 1] = 1;
	printf("Even or Odd (E|O)? ");
	char eo = getchar();
	if (toupper(eo) == 'E' && a[i - 1] % 2 == 0)
	{
		point = a[i -1];
		printf("Correct! You win %d points.\n", point);
		total_point += point;
	}
	else if (toupper(eo) == 'O' && a[i - 1] % 2 == 1)
	{
		point = a[i -1];
		printf("Correct! You win %d points.\n", point);
		total_point += point;
	}
  }
  while (!is_over(b, n));
  printf("You win total %d points.\n", total_point);
}
