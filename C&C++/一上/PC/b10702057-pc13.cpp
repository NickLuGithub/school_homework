// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-pc13.cpp
// Compiler�GDev C++
// Date�G2018/11/22
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 6

void generate_question(int question[], int digits)//�H������ digits �Ӥ��P���Ʀr int
{   
  	srand(time(0));                 // �ŧi�H���� 
  	question[0] = rand() % 9 + 1;   // �Ĥ@�ӼƦr�|�O 1-9
  /* ���ͨ�l�Ʀr */
	for (int i = 1; i < digits; i++)
	{
		question[i] = rand() % 10;    // ��L�Ʀr�|�O 0-9.
		for (int j = 0; j < i; j++) 
	  		if (question[i] == question[j])
			{ // ���Ƶo��
				--i;
				break;
			}
   }
}

void guess_question(int question[], int guess[], int digits)
{   //�q�Ʀr�A�ѨϥΪ̿�J�Ʀr 
	int value, i;    //�ŧi����ܼ� 
	scanf("%d", &value);  //��J�Ʀr 
	if (value == 0)
	{   //��Ʀr�� 0 �ɡA�L�X���� 
		for (i = 0; i < digits; i++)
		{
      		printf("%d", question[i]);
      		guess[i] = question[i];
    	}
    	puts("");
	}
	else 
	{    /* ���o�Ʀr */
    	// digits = 4, value = 1234
    	for (i = digits - 1; i >= 0; i--)
		{
			guess[i] = value % 10;            // guess[3] = 4, guess[2] = 3, guess[1] = 2, guess[0] = 1
			value = value / 10;
    	}
	} 
}

int compare(int question[], int guess[], int digits)
{
	int a_count = 0, b_count = 0;
	
	for (int i = 0; i < digits; i++)
	{
		if (guess[i] == question[i]) a_count++;
		else
		{
			for (int j = 0; j < digits; j++)
			{
				if (guess[i] == question[j] && j!= i)
				{
					b_count++;
					break;
				}
			}
		}
		
	}
	
	printf("%dA %dB\n", a_count, b_count);
	if ( a_count == digits) return 1;
	else
	{
		printf("�A��@��\n");
		return 0; 
	}
}

int main ( void )
{
	int digits = 0;
	int question[SIZE], guess[SIZE];
	int is_correct = 0;
	int count = 0;
	
	while ( digits < 4 || digits > 6)
	{
		printf("�п�J�n�q�X���?( 4 ~ 6 ) ");
		scanf("%d", &digits);
	}
	generate_question(question, digits);
	do
	{
		guess_question(question, guess, digits);
		count++;
	}
	while ( compare(question, guess, digits) < 1);
	printf("�@�q%d��\n", count);
} 
