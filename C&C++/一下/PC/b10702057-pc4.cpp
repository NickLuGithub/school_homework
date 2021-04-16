#include<stdio.h>
#include<string.h>
#define SIZ 120

int read_array(double a[], FILE *fp) {
	int n = 0;
	while ( fscanf(fp, "%lf", &a[n++]) > 0);
	return n - 1;
}

void print_array(double a[], int n) {
	for (int i = 0; i < n; i++) printf("%f ", a[i]);
	puts("");
}

int main ( void ) {
	FILE *fp;
	char filename[SIZ], str[SIZ];
	int n ;
	double a[SIZ];
	
	printf("Enter the file name: ");
	scanf("%s", filename);
	getchar();
	
	if ((fp = fopen(filename, "w")) != NULL) {
		printf("Enter numbers: ");
		fgets(str, SIZ, stdin);
		puts(str);
		fclose(fp);
	}
	else printf("The %s cannot be opened.\n", filename);
	
	if ((fp = fopen(filename, "r")) != NULL) {
		n = read_array(a, fp);
		fclose(fp);
	}
	else printf("The %s cannot be opened.\n", filename);
	
	print_array(a, n);
}
