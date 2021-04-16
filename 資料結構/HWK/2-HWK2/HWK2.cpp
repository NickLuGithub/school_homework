/*
		hwk2
	name	LU,YUDA
	number	b10702057
	date	20.05.23(1.0), 20,05,24(1.1) 20.05.24(2.0)
*/

/*
		�j�[�c
	1.�ϥΪ̿�ܱƧǤ覡
		a.	��ܸ�Ƶ��c
	2.�ϥΪ̿�J�ɮצW��
		a.	Ū��
		b.	�g�J�ɮ�
	3.�Ƨ�
		a.	�̷ӨϥΪ̿�J�ƧǪk����
	4.��X�̲׵���
		a.	��X���ɮ�
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
	sort_name �s��n�ϥέ��@�رƧǤ覡
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
		�[�c
		place			>>	�ƧǦ줸��
		output[1000]	>>	��X�Ȧs
		count[max]		>>	max�Q�i��
		
			1.�p��X�C�@�Ӧ줸���h�֭�
				ex: 11 % 10 = 1 ���X��
			2.��count��}�C��l���
			3.�ե���output
			4.�g�J�쥻array

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
		getMax ����̤j��
		countingSort
			�Q�Υثe�줸�Ƨ�
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
		���j��]�p
			�~�j��
				gap ���� ���Ӯt�Z
			���j��
				i �k�� �qgap���Ӧ�l�}�l
				j ���� �q��l��m�}�l
				�p�G����j��k��
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

	cout << "��J�ɦW: ";
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

	cout << "���L��.txt����\n";
}

void read_date(int number_array[])
{
	ifstream InF;
	int n = 0, i = 0;
	char FName[20], ch[10];
	string in_s;

	cout << "��J�ɦW: ";
	cin >> FName;

	InF.open(FName, ios::in);

	if (!InF)
	{
		cout << "�ɮ׵L�k�}��\n";
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
		cout << "��J���~!!" << endl;
		exit(1);
	}

	outF(number_array);
	system("pause");
}
