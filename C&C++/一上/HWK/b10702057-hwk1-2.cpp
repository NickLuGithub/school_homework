// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk1-2.cpp
// Compiler�GDev C++
// Date�G2018/10/05

#include <stdio.h>

int main ( void )
{
	char in;
	int money = 0,h,in_1,money_1 = 0;
	do{
		printf("�w��Ө��|�r�c���\n�ڭ̪��ӫ~���G\n");
		printf("01 - ���� $100 02 - ���� $100 03 - �t�t $100 04 - ���� $100 05 - �p�p $100\n06 - ���� $200 07 - ��� $200 08 - �u�u $200 09 - ���� $200 10 - ���� $200\n");
		printf("�аݬO�_�ݭn�ʪ�(Y/N)\n");
		scanf("%s",&in);
		if ( in == 'Y' || in == 'y' || in == 'N' || in == 'n')
		{
			while ( in != 'N' && in != 'n')
			{
				printf("�Ч��\n");
				scanf("%d",&money_1);
				money += money_1;
				if ( money < 100 )
				{
				}
				else if ( money < 200 )
				{
					printf("�i�ʶR�G01 - ���� $100 02 - ���� $100 03 - �t�t $100 04 - ���� $100 05 - �p�p $100\n");
					printf("�A����Х���J 0 \n���}�п�J11\n");
					scanf("%d",&h);
					switch ( h )
					{
						case 0: {
							break;
						}
						case 1: {
							money -= 100;
							printf("��o ���� �G�r\n��s�G %d \n",money);
							break;
						}
						case 2: {
							money -= 100;
							printf("��o ���� �G�r\n��s�G %d \n",money);						
							break;
						}
						case 3: {
							money -= 100;
							printf("��o �t�t �G�r\n��s�G %d \n",money);						
							break;
						}
						case 4: {
							money -= 100;
							printf("��o ���� �G�r\n��s�G %d \n",money);
							break;
						}
						case 5: {
							money -= 100;
							printf("��o �p�p �G�r\n��s�G %d \n",money);
							break;
						}
						case 11: {
							in = 'N';
							printf("��s�G %d \n",money);
							break;
						}
					}
				}
				else if ( money >= 200)
				{
					printf("�i�ʶR�G01 - ���� $100 02 - ���� $100 03 - �t�t $100 04 - ���� $100 05 - �p�p $100\n        06 - ���� $200 07 - ��� $200 08 - �u�u $200 09 - ���� $200 10 - ���� $200\n");
					printf("�A����Х���J 0 \n���}�п�J11\n");
					scanf("%d",&h);
					switch ( h )
					{
						case 0: {
							break;
						}
						case 1: {
							money -= 100;
							printf("��o ���� �G�r\n��s�G %d \n",money);
							break;
						}
						case 2: {
							money -= 100;
							printf("��o ���� �G�r\n��s�G %d \n",money);						
							break;
						}
						case 3: {
							money -= 100;
							printf("��o �t�t �G�r\n��s�G %d \n",money);						
							break;
						}
						case 4: {
							money -= 100;
							printf("��o ���� �G�r\n��s�G %d \n",money);
							break;
						}
						case 5: {
							money -= 100;
							printf("��o �p�p �G�r\n��s�G %d \n",money);
							break;
						}
						case 6: {
							money -= 200;
							printf("��o ���� �G�r\n��s�G %d \n",money);
							break;
						}
						case 7: {
							money -= 200;
							printf("��o ��� �G�r\n��s�G %d \n",money);
							break;
						}
						case 8: {
							money -= 200;
							printf("��o �u�u �G�r\n��s�G %d \n",money);
							break;
						}
						case 9: {
							money -= 200;
							printf("��o ���� �G�r\n��s�G %d \n",money);
							break;
						}
						case 10: {
							money -= 200;
							printf("��o ���� �G�r\n��s�G %d \n",money);
							break;
						}
						case 11: {
							in = 'N';
							printf("��s�G %d \n",money);
							break;
						}
					}
				}
			}			
		}
		else
		{
			break;
		}
	}while( in != 'N' && in != 'n');
}
