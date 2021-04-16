// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex3.cpp
// Compiler�GDev C++
// Date�G2019/03/19
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define LEN 100


typedef struct {
	char op;
	double a, b;
} exp_line;

double aser(exp_line a) {
	double k;
	switch (a.op) {
		case '+' :{
			k = a.a + a.b; 
			break;
		}
		case '-' :{
			k = a.a - a.b;
			break;
		}
		case '*' :{
			k = a.a * a.b;
			break;
		}
		case '/' :{
			k = a.a / a.b;
			break;
		}
		case '%' :{
			k = (int)a.a % (int)a.b;
			break;
		}
	}
	return k;
}

int main ( void ) {
	
	FILE *infp, *outfp;                   //�ɮצ�l 
	char input[LEN], output[LEN];
	exp_line a;
	
	printf("Input file name: ");          //�X�J�ɮ��ɦW 
	scanf("%s", input);
	printf("output file name: ");         //��X�ɮ��ɦW 
	scanf("%s", output);
	
	if ((infp = fopen(input, "r")) != NULL && (outfp = fopen(output, "w")) != NULL) {  //Ū�g�ɮ� 
		while(!feof(infp)) {
			fscanf(infp, "%lf %c %lf", &a.a, &a.op, &a.b);
			fprintf(outfp, "%.2lf %c %.2lf = %.2lf\n", a.a, a.op, a.b, aser(a));
			printf("%.2lf %c %.2lf = %.2lf\n", a.a, a.op, a.b, aser(a));
		}
	}
	else 
	{
		printf("The files cannot be opened.\n");
	}
	
	fclose(infp);
	fclose(outfp);
}
