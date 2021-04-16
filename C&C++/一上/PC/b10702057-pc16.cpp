#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 30
#define COL 30

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
void even_random_array(int a[], int n) {
  random_array(a, n);
  for (int i = 0; i < n; i++) a[i] *= 2;
}
void odd_random_array(int a[], int n) {
  random_array(a, n);
  for (int i = 0; i < n; i++) a[i] = a[i] * 2 - 1;
}

void convert_to_2darray(int a[], int b[][COL], int m, int n) {
  for (int i = 0, k = 0; i < m; i++) 
  	for (int j = 0; j < n; j++) b[i][j] = a[k++];  
}

void random_2darray(int a[], int b[][COL], int m, int n) {
  random_array(a, m * n);
  for (int i = 0, k = 0; i < m; i++) 
  	for (int j = 0; j < n; j++) b[i][j] = a[k++];
}

void print_array(int a[], int n) {
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  puts("");
}

void print_2darray(int b[][COL], int s[][COL], int m, int n) {
  for (int i = 0; i < m; i++) {
  	for (int j = 0; j < n; j++)
  	  if (s[i][j] == 1) printf("%5d ", b[i][j]);
  	  else printf("%5s", "*");
    puts("");
  }
}

int is_flipped_add(int s[][COL], int m, int n) {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (s[i][j] == 0) return 0;
  return 1;
}
int main(void) {
  int a[ROW * COL], b[ROW][COL], s[ROW][COL] = {0}, m, n, pi, pj, ci, cj, player = 0, computer = 0;
  
  srand(time(0));
  printf("Enter m, n: ");
  scanf("%d%d", &m, &n);
    
  random_2darray(a, b, m , n);
  do {
  	print_2darray(b, s, m, n);
  	do {
  	  printf("Pick 1 number: ");
  	  scanf("%d%d", &pi, &pj);
	} while (pi < 0 || pi >= m || pj < 0 || pj >= n || s[pi][pj] == 1);
	s[pi][pj] = 1;
  do {
	ci = rand() % m;
	cj = rand() % n;
  } while (s[ci][cj] == 1);
  s[ci][cj] = 1;
  if (b[pi][pj] > b[ci][cj]) player += b[pi][pj] + b[ci][cj];
  else computer += b[pi][pj] + b[ci][cj];
  } while ( is_flipped_add (s, m, n) == 0);  
  if (player > computer) printf("The player wins the game.\n");
  else if (player < computer) printf("The computer wins the game. \n");
  else printf("They draw the game.\n");
}
