// Student No.¡GB10702057  Name¡G¿c¬R¹F 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define LEN 1000

int main ( void ){
	FILE *fp;
	char input[LEN], line[LEN];
	
	printf("Input file name: ");
	scanf("%s", input);
	if ((fp = fopen(input, "r")) != NULL) {
		while(!feof(fp)) {
			fgets(line, LEN, fp);
			printf("%s ", line);
		}
	}
	else 
	{
		printf("The files cannot be opened.\n");
	}
	fclose(fp);
}
