// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-pc13.cpp
// Compiler：Dev C++
// Date：2018/11/22
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 6

void generate_question(int question[], int digits)//隨機產生 digits 個不同的數字 int
{   
  	srand(time(0));                 // 宣告隨機數 
  	question[0] = rand() % 9 + 1;   // 第一個數字會是 1-9
  /* 產生其餘數字 */
	for (int i = 1; i < digits; i++)
	{
		question[i] = rand() % 10;    // 其他數字會是 0-9.
		for (int j = 0; j < i; j++) 
	  		if (question[i] == question[j])
			{ // 重複發生
				--i;
				break;
			}
   }
}

void guess_question(int question[], int guess[], int digits)
{   //猜數字，由使用者輸入數字 
	int value, i;    //宣告整數變數 
	scanf("%d", &value);  //輸入數字 
	if (value == 0)
	{   //當數字為 0 時，印出答案 
		for (i = 0; i < digits; i++)
		{
      		printf("%d", question[i]);
      		guess[i] = question[i];
    	}
    	puts("");
	}
	else 
	{    /* 取得數字 */
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
		printf("再輸一次\n");
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
		printf("請輸入要猜幾位數?( 4 ~ 6 ) ");
		scanf("%d", &digits);
	}
	generate_question(question, digits);
	do
	{
		guess_question(question, guess, digits);
		count++;
	}
	while ( compare(question, guess, digits) < 1);
	printf("共猜%d次\n", count);
} 
