#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void random_array(int a[], int n)
{
	for (int i = 0; i < n * n * 2; i++)
	{
		a[i] = rand() % (2*n*n) + 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				--i;
				break;
			}
		}			
	}
}

void odd_random_array(int a[], int n) {
  random_array(a, n);
  for (int i = 0; i < n * n * 2; i++) a[i] = a[i] * 2 - 1;
}

void array_2d(int a[], int  b[][SIZE],int  n)
{
	for (int i = 0, k = 0; i < n; i ++){
		for ( int j = 0 ; j < 2 * n; j++)
		{
			b[i][j] = a[k++];
		}
	}
}

void print_2darray(int b[][SIZE], int s[][SIZE], int n) {
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < 2 * n; j++)
  	  if (s[i][j] == 1) printf("%4d ", b[i][j]);
  	  else printf("%5s", "*");
    puts("");
  }
}

int print_number(int a)
{		
	int k;
	if ( k <= 1)
	{
		printf("Guess sum of 2 numbers:");
		scanf("%d ", &k);
		print_number(k);
	}
	else return k;
	
}

int main (void)
{
	int w;
	int n, a[SIZE*SIZE], k;
	int b[SIZE][SIZE],s[SIZE][SIZE];
	int ci,cj,pi,pj;
	int total = 0;
	char q;

	srand(time(0));
	printf("Enter n:");
	scanf("%d ", &n);
	
	k = 2 * n * n - 2;
	random_array(a, n);
	odd_random_array(a, n);
	array_2d(a, b, n);
	do
	{
		printf("Guess sum of 2 numbers:");
		scanf("%d ", &w);
		print_2darray(b, s, n);
		//w = print_number(w);
		do{
			ci = rand () % n;
			cj = rand () % (2 * n);
		}while ( s[ci][cj] != 1);
		s[ci][cj] = 1;
		do{
			pi = rand () % n;
			pj = rand () % (2 * n);
		}while ( s[pi][pj] != 0);
		s[pi][pj] = 1;
		k -= 2;
		if ( (b[ci][cj] + b[pi][pj]) % 2 == w){
			total += b[ci][cj] + b[pi][pj];
			printf("get %d print", b[ci][cj] + b[pi][pj]);
/*			printf("Contiune to play(Y|N)");
			scanf("%s ", &q);
			if ( q == 'N' || q == 'n')
			{
				k = 0;
			}
			else if ( q == 'Y' || q == 'y')
			{
				k -= 2;
			}
	*/	}
		
		else 
		{
			printf("²q¿ù¤F\n");
		/*	printf("Contiune to play(Y|N)");
			scanf("%s", &q);
			if ( q == 'N' || q == 'n')
			{
				k = 0;
			}
			else if ( q == 'Y' || q == 'y')
			{
				k -= 2;
			}*/
		}
	}while ( k >= 0);
	printf("Total point %d", total);
}
