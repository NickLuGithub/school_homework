#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100
#define LEN 400

typedef struct {
	double x, y;
} Point;

int read_point (Point p[]) {
	char str[LEN], *sp;
	int n = 0;
	printf("Enter points: ");
	fgets(str, LEN, stdin);
	char *deter = " ";
	p[0].x = atof(strtok(str, deter));
	p[0].y = atof(strtok(NULL, deter));
	n++;
	while((sp = strtok(NULL, deter)) != NULL) {
		p[n].x = atof(sp);
		sp = strtok(NULL, deter);
		p[n].y = atof(sp);
		n++;
	}
	return n;
}

void sort_point(Point p[], int n) {
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			if (pow(p[i].x, 2) + pow(p[i].y, 2) > pow(p[j].x, 2) + pow(p[j].y, 2)) {
				Point temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void print_point(Point p[], int n) {
	for (int i = 0; i < n; i++) printf("(%lf, %lf) ", p[i].x, p[i].y);
	puts("");
}

int main(void) {
	int n;
	
	Point p[SIZE];
	n = read_point(p);
	print_point(p, n);
	sort_point(p, n);
	print_point(p, n);
}
