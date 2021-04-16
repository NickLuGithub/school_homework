// Student No.¡GB10702057  Name¡G¿c¬R¹F 
// File Name¡Gb10702057-pc6.cpp
// Compiler¡GDev C++
// Date¡G2019/03/18
#include<stdio.h>
#include<math.h>
#define LEN 40

typedef struct {
	double x, y;
} Point;

typedef struct {
	Point a, b;
} Line;

double dist (Point a, Point b) {
	return sqrt ( pow ( a.x - b.x, 2) + pow ( a.y - b.y , 2) );
}

double line_equation (Line l, FILE *fp) {
	double a = l.a.x, b = l.a.y, c = l.b.x, d = l.b.y;
	printf("%fx + %fy = %f\n", ( b - d), ( c - a), ( b * c - a * d));
	fprintf(fp, "%fx + %fy = %f\n", ( b - d), ( c - a), ( b * c - a * d));
}

int main ( void ) { 
	FILE *infp, *outfp;
	char input[LEN], output[LEN];
	Point a, b;
	Line l;
	printf("Input file name: ");
	scanf("%s", input);
	printf("output file name: ");
	scanf("%s", output);
	if ((infp = fopen(input, "r")) != NULL && (outfp = fopen(output, "w")) != NULL) {
		while(!feof(infp)) {
			fscanf(infp, "%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
			printf("The distance between (%f, %f) and (%f, %f) is %f\n", a.x, a.y, b.x, b.y, dist(a, b));
			fprintf(outfp , "The distance between (%f, %f) and (%f, %f) is %f\n", a.x, a.y, b.x, b.y, dist(a, b));
			l.a = a;
			l.b = b;
			printf("The line passing (%f, %f) and (%f, %f) is ", l.a.x, l.a.y, l.b.x, l.b.y);
			fprintf(outfp, "The line passing (%f, %f) and (%f, %f) is ", l.a.x, l.a.y, l.b.x, l.b.y);
			line_equation(l, outfp);
		}
	}
	else 
	{
		printf("The files cannot be opened.\n");
	}
	fclose(infp);
	fclose(outfp);
}
