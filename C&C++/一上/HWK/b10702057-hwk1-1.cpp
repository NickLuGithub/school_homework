// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk1-1.cpp
// Compiler�GDev C++
// Date�G2018/10/04

#include<stdio.h>

int main ( void )
{
	char in;
	int in_mid;
	do
	{
		printf("    �M������a\n");
		printf("�аݬO�_�i��C��(Y/N)\n");
		in_mid = getchar();	
		while( in != 'N' && in != 'n')
		{
			printf("�п�ܤ@����(1/2/3)\n");
			scanf("%d",&in_mid);
			if ( in_mid == 1)
			{
				printf("���´f�U\n");
				break;
			}
			else if ( in_mid == 2)
			{
				printf("�ЦA��ܤ@����(1/2/3)\n");
				scanf("%d",&in_mid);
				if ( in_mid == 1)
				{
					printf("������o�ӫa\n");
					break;
				}
				else if ( in_mid == 3)
				{
					printf("�ЦA��ܤ@����(1/2/3)\n");
					scanf("%d",&in_mid);
					if ( in_mid == 1)
					{
						printf("���´f�U\n");
						break;
					}
					else if ( in_mid == 2)
					{
						printf("������o�ӫa\n");
						break;
					}
					else if ( in_mid == 3)
					{
						printf("�ЦA��ܤ@����(1/2)\n");
						scanf("%d",&in_mid);
						if ( in_mid == 1)
						{
							printf("���´f�U\n");
							break;
						}
						else if ( in_mid == 2)
						{
							printf("������o���ӫa\n");
							break;
						}
						else
						{
							printf("��J���~\n");
							break;
						}
					}
					else
					{
						printf("��J���~\n");
						break;
					}
				}
				else if ( in_mid == 2)
				{
					printf("������o�ӫa\n");
					break;
				}
				else
				{
					printf("��J���~\n");
					break;
				}
			}
			else if ( in_mid == 3)
			{
				printf("������o�ӫa\n");
				break;
			}
			else
			{
				printf("��J���~\n");
				break;
			}
		}		
	}while( in != 'N' && in != 'n');
}
