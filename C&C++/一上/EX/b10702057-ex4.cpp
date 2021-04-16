#include <stdio.h>
 
int main(void) {
 
  int i = 0, n, sum = 0;
  printf("Input n : ");
  scanf("%d", &n);
 
  printf("number square sum(1..n)\n");
  while (++i <= n) {
  	sum += i; 
  	printf("%5d %6d %7d %5d\n", i, i * i,i * i * i,sum);
  }
}

