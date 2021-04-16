/*
		hwk2
	name	LU,YUDA
	number	b10702057
	date	20.05.23(1.0), 20,05,24(1.1) 20.05.24(2.0)
*/

/*
		大架構
	1.使用者選擇排序方式
		a.	選擇資料結構
	2.使用者輸入檔案名稱
		a.	讀黨
		b.	寫入檔案
	3.排序
		a.	依照使用者輸入排序法執行
	4.輸出最終答案
		a.	輸出成檔案
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#include <dos.h>
#include <conio.h>
using namespace std;

/*
	sort_name 存放要使用哪一種排序方式
*/

int sort_name = -1;

int getMax(int array[], int n) {
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

void countingSort(int array[], int size, int place)
{	
	/*
		架構
		place			>>	排序位元數
		output[1000]	>>	輸出暫存
		count[max]		>>	max十進位
		
			1.計算出每一個位元有多少個
				ex: 11 % 10 = 1 有幾個
			2.讓count跟陣列位子對齊
			3.校正到output
			4.寫入原本array

	*/

	const int max = 10;
	int output[1000];
	int count[max];

	for (int i = 0; i < max; ++i)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		count[(array[i] / place) % 10]++;
	}

	for (int i = 1; i < max; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
}

void Radix(int number_array[])
{
	int size = 1000;
	/*
		getMax 先找最大值
		countingSort
			利用目前位元排序
	*/
	int max = getMax(number_array, size);
	for (int place = 1; max / place > 0; place *= 10)
	{
		countingSort(number_array, size, place);	
	}
}

int Shell(int number_array[])
{
	/*
		雙迴圈設計
			外迴圈
				gap 控制 間個差距
			內迴圈
				i 右手 從gap那個位子開始
				j 左手 從初始位置開始
				如果左手大於右手
				swap(i, j)
	*/

	int size = 1000;
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i += 1)
		{
			int temp = number_array[i];

			int j;
			for (j = i; j >= gap && number_array[j - gap] > temp; j -= gap)
			{
				number_array[j] = number_array[j - gap];
			}
			number_array[j] = temp;
		}
	}
	return 0;
}

void outF(int number_array[])
{
	FILE* pFile;
	char f_name[30];

	cout << "輸入檔名: ";
	cin >> f_name;

	pFile = fopen(f_name, "w");

	if (NULL == pFile)
	{
		printf("open failure");
	}
	else
	{
		for (int i = 0; i < 1000; i++) fprintf(pFile, "%5d\n", number_array[i]);
	}
	fclose(pFile);

	cout << "打印到.txt完畢\n";
}

void read_date(int number_array[])
{
	ifstream InF;
	int n = 0, i = 0;
	char FName[20], ch[10];
	string in_s;

	cout << "輸入檔名: ";
	cin >> FName;

	InF.open(FName, ios::in);

	if (!InF)
	{
		cout << "檔案無法開啟\n";
		exit(1);
	}
	else
	{
		while (InF.getline(ch, 10))
		{
			if (ch[0] != '\n')
			{
				in_s = ch;
				number_array[i++] = atoi(in_s.c_str());
			}
		}
		InF.close();
	}
}

int main(void)
{
	cout << "1.Radix sort 2,Shell sort: ";
	cin >> sort_name;

	int number_array[1010];
	if (sort_name == 1 || sort_name == 2)
	{
		read_date(number_array);
		if (sort_name == 1) Radix(number_array);
		else Shell(number_array);
	}
	else
	{
		cout << "輸入錯誤!!" << endl;
		exit(1);
	}

	outF(number_array);
	system("pause");
}
