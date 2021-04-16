#include<stdlib.h>
#include<stdio.h>

int opfile(char input[]);
void printstr(char output[], int n);

int main ( void )
{
	int n;
	char str[2000];
	n = opfile(str);
	printstr(str, n);
}

int opfile(char input[])
{
	FILE *fp;
	char filename[20], c;
	printf("輸入你的檔案名稱: ");
	scanf("%s", filename);
	getchar();
	int n = 0;
	if ((fp = fopen(filename, "r")) != NULL)
	{
		fscanf(fp ,"%c", c);
		while(c != '\0')
		{
			input[n] = c;
			printf("%c", c);
			n++;
			fscanf(fp, "%c", c);
		}		
		fclose(fp);
	}
	else printf("%s 此文件無法打開\n", filename);
}

void printstr(char output[], int n)
{
	for ( int i = 0; i < n; i ++) printf("%s", output[i]);
}
