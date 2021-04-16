/*
	��Ƶ��cHWK3�r��
		�غc�r��

	�[�c
		1.�ظm��Ʈw
		2.�ؼЪ����j�M

*/
#include <iostream>
#include <fstream>

#define word_n 57

using namespace std;

struct words
{
	string english_word, chinese_word;
};

struct word_table
{
	int word_total = 0;
	words word[200];
};

void read_date(word_table table_date[])
{
	int id, ch_t = 0;
	string in_english, in_chinese;
	ifstream InF;
	char FName[20], ch;

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
		while (InF.get(ch))
		{
			if (ch_t++ < 20) in_english += ch;
			else if (ch_t++ >= 20 && ch != '\n') in_chinese += ch;
			else if (ch == '\n')
			{
				ch_t = 0;

				id = in_english[0] * in_english[1] % word_n;
				table_date[id].word[table_date[id].word_total].english_word = in_english;
				table_date[id].word[table_date[id].word_total++].chinese_word = in_chinese;

				//cout << in_english << " " << in_chinese << " id = " << id << endl;

				in_english = "";
				in_chinese = "";
			}
		}
		InF.close();
	}
}

void print_all(word_table table_date[])
{
	for (int i = 0; i < word_n; i++)
	{
		cout << "i = " << i << endl;
		for (int j = 0; j < table_date[i].word_total; j++)
		{
			cout << table_date[i].word[j].english_word;
			cout << table_date[i].word[j].chinese_word << endl;
		}
		cout << endl;
	}
}

void search(word_table table_date[], string search_word)
{
	bool op = false;
	int	id = search_word[0] * search_word[1] % word_n;
	for (int i = search_word.size(); i < 20; i++)
	{
		search_word += ' ';
	}
	for (int j = 0; j < table_date[id].word_total; j++)
	{
		if (table_date[id].word[j].english_word == search_word)
		{
			op = true;
			cout << table_date[id].word[j].chinese_word << endl;
			cout << "�@�j�M" << j << "��" << endl;
		}
	}
	if (op == true) cout << "�j�M����" << endl;
	else cout << "�d�L���" << endl;
}

int main(void)
{
	string search_word;
	word_table table_date[word_n];

	read_date(table_date);
	//print_all(table_date);

	bool op = true;
	while (op != false)
	{
		cout << "�п�J�n�j�M�r��:" << endl;
		cin >> search_word;
		search(table_date, search_word);
		cout << "�O�_�A���ϥ�(y/n)" << endl;
		string next = "";
		cin >> next;
		if (next[0] == 'y' || next[0] == 'Y') op = true;
		else op = false;
	}
}