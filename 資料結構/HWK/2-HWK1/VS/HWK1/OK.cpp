// ����{��: Ctrl + F5 �� [����] > [�Ұʦ�������] �\���
// �����{��: F5 �� [����] > [�Ұʰ���] �\���
// �}�l�ϥΪ�����: 
//   1. �ϥ� [����`��] �����A�s�W/�޲z�ɮ�
//   2. �ϥ� [Team Explorer] �����A�s�u���l�ɱ���
//   3. �ϥ� [��X] �����A�Ѿ\�իؿ�X�P��L�T��
//   4. �ϥ� [���~�M��] �����A�˵����~
//   5. �e�� [�M��] > [�s�W����]�A�إ߷s���{���X�ɮסA�άO�e�� [�M��] > [�s�W�{������]�A�N�{���{���X�ɮ׷s�W�ܱM��
//   6. ����n�A���}�Ҧ��M�׮ɡA�Ыe�� [�ɮ�] > [�}��] > [�M��]�A�M���� .sln �ɮ�

// HWK1.cpp : ���ɮץ]�t 'main' �禡�C�{���|��ӳB�}�l����ε�������C
//�@��:YUDA LU
//���:2020.03.20(1.0), 2020.03.24(1.1), 2020.04.09(1.2), 2020.04.10(2.0)

//�ثe >> back_edge ���~�B�� (low���~)

#include <iostream>
#include <fstream>
#include <windows.h>
#include <dos.h>
#include <conio.h>
#include <typeinfo>
#define SIZE 20 
using namespace std;

class point
{
private:
	//number  >>  ���Ʀr
	//number_line[20]  >>  �Ʀr�s���쪺�Ʀr
	//line_n  >>  �Ʀr�s�����`��

	//�Ѯv���I >> �i�H�b�����I�W�y������� >> �a�J���j��Ʈy�P�_ 

	int number, number_line[SIZE], line_n,
		dfn, back_edge, low, input_number;
	bool bool_number_line[SIZE] = { false },
		bool_number_end = false;

public:
	//�ɤJ�ɮ�
	void in_number(int n);
	void in_number_line(int i, int n);
	void in_line_n(int n);
	void in_bool_number_line(int i, bool op);
	void in_dfn(int i);
	void in_low(int i);
	void in_back_edge(int i);
	void in_bool_number_end(bool i);
	void in_input_number(int i);

	//�ɥX�ɮ�
	int out_number();
	int out_number_line(int i);
	int out_line_n();
	int out_dfn();
	int out_low();
	int out_back_edge();
	int out_bool_total();
	int out_input_number();
	bool out_bool_number_line(int i);
	bool out_bool_number_end();

	//function at class point
	int return_number_i(int n);
	bool cheak_number(int number);
	bool cheak_number_ok(int number);
};

void read_date(string* in_number_date);
void string_to_point_array(string str_number, point point_array[SIZE], int* n);

void print_number_array(int n, point point_array[SIZE]);
void print_numbber_array_line(int n, point point_array[SIZE]);
void print_bool_array(int n, point point_array[SIZE]);
void print_articulation_point_array(int articulation_point[SIZE], int articulation_point_n);
void print_dfs_end(int n, point point_array[SIZE]);

void insert_number_to_point_array(int n, point point_array[SIZE]);
void insert_dfs(int n, point point_array[SIZE], int dfs_array[SIZE]);
void insert_back_edge(int n, point point_array[SIZE], int dfs_array[SIZE]);
void insert_articulation_point(int n, point point_array[SIZE], int dfs_array[SIZE], int articulation_point[SIZE], int* articulation_point_n);

int search_next_number(int search_number, point point_array[SIZE], int dfs_array_n, int dfs_array[SIZE]);
bool ok_number(int next_number, int dfs_array_n, int dfs_array[SIZE]);

//�D�{�� 
int main(void)
{
	/*
		�W��
			articulation_point >> ���`�I
		�ܼ�
			n						�`�@���h�ּƦr
			dfs_array				DFS��쪺����
			in_number_date			Ū�J�Ү׹��g�J�r�ꤤ
			point_array				�Ʀr�}�C
			articulation_point		���`�I�}�C
			articulation_point_n	���`�I�}�Cn
		��Ҹ��u
			1.Ū��
			2.�N�ɮ��ഫ��Point�Φ�
			3.�ϥ�DFS��XDFN�}�C
			4.�ϥ�back_edge��Xlow
			5.�ϥ�low & dfn ��X���`�I
	*/

	int n, articulation_point_n, dfs_array[SIZE], articulation_point[SIZE];
	string in_number_date;
	point point_array[SIZE];

	read_date(&in_number_date);										//Ū��
	string_to_point_array(in_number_date, point_array, &n);			//�ഫ�ɮפ����

	print_number_array(n, point_array);
	print_numbber_array_line(n, point_array);

	insert_number_to_point_array(n, point_array);
	//�ظmpoint_array��number�Ʀr
	insert_dfs(n, point_array, dfs_array);

	print_bool_array(n, point_array);
	print_numbber_array_line(n, point_array);

	//��Xdfs
	insert_back_edge(n, point_array, dfs_array);
	//��back_edge��Xlow
	insert_articulation_point(n, point_array, dfs_array, articulation_point, &articulation_point_n);
	//��low and dfn ��X���`�I

	print_dfs_end(n, point_array);
	print_bool_array(n, point_array);											//�C�Lbool���A
	print_articulation_point_array(articulation_point, articulation_point_n);	//�C�L���`�I

	system("pause");
	return 0;
}

//class point �{���Ϭq �}�l 
void point::in_number(int n)
{
	number = n;
}

void point::in_number_line(int i, int n)
{
	number_line[i] = n;
}

void point::in_line_n(int n)
{
	line_n = n;
}

void point::in_bool_number_line(int i, bool op)
{
	bool_number_line[i] = op;
}

void point::in_dfn(int i)
{
	dfn = i;
}

void point::in_low(int i)
{
	low = i;
}

void point::in_back_edge(int i)
{
	back_edge = i;
}

void point::in_bool_number_end(bool i)
{
	bool_number_end = i;
}

void point::in_input_number(int i)
{
	input_number = i;
}

int point::out_number()
{
	return number;
}

int point::out_number_line(int i)
{
	return number_line[i];
}

int point::out_line_n()
{
	return line_n;
}

int point::out_dfn()
{
	return dfn;
}

int point::out_low()
{
	return low;
}

int point::out_back_edge()
{
	return back_edge;
}

int point::out_bool_total()
{
	int sum = 0;
	for (int i = 0; i < line_n; i++)
	{
		if (bool_number_line[i] == true)
		{
			++sum;
		}
	}
	return sum;
}

int point::out_input_number()
{
	return input_number;
}

bool point::out_bool_number_line(int i)
{
	return bool_number_line[i];
}

bool point::out_bool_number_end()
{
	return bool_number_end;
}

int point::return_number_i(int n)
{
	int out = 0;
	for (int i = 0; i < line_n; i++)
	{
		if (number_line[i] == n)
		{
			out = i;
			break;
		}
	}
	return out;
}

bool point::cheak_number(int number)
{
	bool op = false;
	for (int i = 0; i < line_n; i++)
	{
		if (number_line[i] == number) op = true;
	}
	if (op) return true;
	else return false;
}

bool point::cheak_number_ok(int number)
{
	bool op = false;
	for (int i = 0; i < line_n; i++)
	{
		if (number_line[i] == number && bool_number_line[i] == 0) op = true;
	}
	if (op == true) return true;
	else return false;
}
//class point �{���Ϭq ����

//�}��Ū��
void read_date(string* in_number_date)
{
	fstream InF;
	int n = 0;
	char FName[20], ch;

	cout << "��J��{���ɦW:";
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
			*in_number_date += ch;
		}
		InF.close();
	}
}

//string to point_array

void string_to_point_array(string str_number, point point_array[SIZE], int* n)
{
	int i = 0, number_i = 0, number_n = 0, number_line_n = 0;
	bool get_n = false;
	string t;

	/*
	t >> ���sn�r��
	get_n >> �PŪnŪ���F��?
	number_i >> ����number_i �� i
	number_n >> ����number_i
	number_line_n >> point_number_line ���׬���
	*/

	while (str_number[i])
	{
		if (!get_n)
		{
			//Ū�Jn 

			if (str_number[i] != '\n')
			{
				t += str_number[i];
			}
			else
			{
				*n = atoi(t.c_str());
				get_n = true;
			}
			i++;
		}
		else
		{
			if (str_number[i] != '\n')
			{
				//�p�G��1�~�����ܸ�Ƥ� 

				if (str_number[i] == '1')
				{
					point_array[number_n].in_number_line(number_line_n, number_i);

					number_i++;
					number_line_n++;
				}
				else if (str_number[i] == '0')
				{
					number_i++;
				}
				else if (str_number[i] == ' ');
				else
				{
					exit(1);
				}
			}
			else
			{
				//�������T�����k�s 

				point_array[number_n].in_line_n(number_line_n);
				number_line_n = 0;
				number_i = 0;
				number_n++;
			}
			i++;
		}
	}

	//����r��̫�L����ӵL�����̫�@��T�� 

	if (str_number[i - 1] != '\n')
	{
		point_array[number_n].in_line_n(number_line_n);
	}
}

void print_articulation_point_array(int articulation_point[SIZE], int articulation_point_n)
{
	cout << "Articulation Point(���`�I): ";
	for (int i = 0; i < articulation_point_n; i++)
	{
		cout << articulation_point[i] << " ";
	}
	cout << "\n�����B�⵲���o!!\n";
}

void print_dfs_end(int n, point point_array[SIZE])
{
	for (int i = 0; i < n; i++)
	{
		cout << point_array[i].out_bool_number_end() << " ";
	}
	cout << endl;
}

void print_number_array(int n, point point_array[SIZE])
{
	cout << "n = " << n << " �x�}�G" << endl;
	printf("    ");
	for (int i = 0; i < n; i++) printf("%2d ", i);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		printf("%2d > ", i);
		for (int j = 0; j < n; j++)
		{
			if (point_array[i].cheak_number(j)) cout << "1  ";
			else cout << "0  ";
		}
		cout << endl;
	}
	cout << "\n";
}

void print_bool_array(int n, point point_array[SIZE])
{
	cout << "bool �s�����G���p\n";
	for (int i = 0; i < n; i++)
	{
		printf("%2d > ", i);
		for (int j = 0; j < point_array[i].out_line_n(); j++)
		{
			cout << point_array[i].out_bool_number_line(j) << " ";
		}
		cout << " \ttotal >> " << point_array[i].out_bool_total() << endl;
	}
	cout << "\n";
}

void print_numbber_array_line(int n, point point_array[SIZE])
{
	cout << "²��x�}�G\n";
	for (int i = 0; i < n; i++)
	{
		printf("%2d > ", i);
		for (int j = 0; j < n; j++)
		{
			if (point_array[i].cheak_number(j)) cout << j << " ";
		}
		cout << endl;
	}
	cout << "\n";
}

void insert_number_to_point_array(int n, point point_array[SIZE])
{
	for (int i = 0; i < n; i++)
	{
		point_array[i].in_number(i);
	}
}

bool ok_number(int next_number, int dfs_array_n, int dfs_array[SIZE])
{
	bool op = true;
	for (int i = 0; i < dfs_array_n; i++)
	{
		if (dfs_array[i] == next_number)
		{
			op = false;
			break;
		}
	}
	return op;
}

int search_next_number(int search_number, point point_array[SIZE], int dfs_array_n, int dfs_array[SIZE])
{
	int next_number;
	/*
		�M��U�@���I
		�T�{search_number���s�����S���U�@���I
			�p�G������I�Areturn �I
			�p�G�S����I�Areturn NULL
	*/
	for (int i = 0; i < point_array[search_number].out_line_n(); i++)
	{
		next_number = point_array[search_number].out_number_line(i);

		if (point_array[search_number].out_bool_number_line(i) == false && ok_number(next_number, dfs_array_n, dfs_array) == true)
		{
			int get_number = point_array[search_number].out_number_line(i);
			int k = point_array[get_number].return_number_i(search_number);

			point_array[search_number].in_bool_number_line(i, true);
			point_array[get_number].in_bool_number_line(k, true);

			return next_number;
			break;
		}
	}
	return NULL;
}

void insert_dfs(int n, point point_array[SIZE], int dfs_array[SIZE])
{
	//cursor �ثe���M��m

	int search_total = 0, next_number, cursor = 0, dfs_array_n = 0;
	bool op = false, go_break = false;
	while (cursor < n && cursor >= 0)
	{
		//�Q��dfs_array��n�P�_�O�_�����I�w�g���
		if (search_total == n) break;
		if (op == false)
		{
			//�N�_�l�ȿ�Jdfs_array
			point_array[cursor].in_dfn(search_total);
			dfs_array[dfs_array_n++] = point_array[cursor].out_number();
			search_total++, op = true;
		}
		else if (op == true)
		{
			//search_next_number >> �M��U�@�ӼƦr �S���^��NULL
			next_number = search_next_number(cursor, point_array, search_total, dfs_array);
			if (next_number != NULL)
			{
				point_array[cursor].in_dfn(search_total);
				dfs_array[search_total++] = next_number;
				cursor = next_number;
				dfs_array_n = search_total;
				go_break = true;
			}
			else if (next_number == NULL)
			{
				if (go_break == true)
				{
					point_array[cursor].in_bool_number_end(true);
					go_break = false;
				}
				cursor = dfs_array[--dfs_array_n];
			}
			else
			{
				cout << "GG!!" << endl;
				exit(1);
			}
		}
	}

	/*
	cout << "dfs_array[i] >>" << endl;
	for (int i = 0; i < search_total; i++)
	{
		cout << i << "\t>>  " << dfs_array[i] << endl;
	}
	cout << "seaech_total = " << search_total << "\n\n";
	*/
}

//back_edge >> �ثe low ���~�B��
void insert_back_edge(int n, point point_array[SIZE], int dfs_array[SIZE])
{
	/*
		hold_number �ثe�̤p�����|
		find_number ��쪺�̵u���|
		next_op		����S�����s��(find_number)�̵u���i
	*/

	int hold_number = n - 1, find_number = n - 1;
	bool next_op = false;

	// i >> dfn  
	for (int i = n - 1; i >= 0; i--)
	{
		for (int k = 0; k < i; k++)
		{
			//�Q��dfs_array�̫�@�ӧ�^��
			if (point_array[dfs_array[i]].cheak_number_ok(dfs_array[k]) == true)
			{
				cout << "hi >> " << k << endl;
				int a_line_i = 0, b_line_i = 0;												// a b �N���s���ܼ� a��b
																							//���bool
				a_line_i = point_array[dfs_array[i]].return_number_i(dfs_array[k]);
				b_line_i = point_array[dfs_array[k]].return_number_i(dfs_array[i]);

				point_array[dfs_array[i]].in_bool_number_line(a_line_i, true);
				point_array[dfs_array[k]].in_bool_number_line(b_line_i, true);

				find_number = k;
				next_op = true;
				break;
			}
			next_op = false;
			//find_number = -1;
		}

		point_array[0].in_low(0);

		if (find_number < hold_number && next_op == true)				//�����L�̵u���| ��W�@�Ӥp�N��s�æs�J
		{
			hold_number = find_number;
			point_array[dfs_array[i]].in_low(hold_number);
			next_op = false;
		}
		else if (find_number >= hold_number && next_op == true)			//��쪺���|�ӨS����W�@�u����s					
		{
			point_array[dfs_array[i]].in_low(hold_number);
			next_op = false;
		}
		else if (i <= n - 2 && point_array[dfs_array[i + 1]].out_low() < i && next_op == false)										//�S�����|��������
		{
			find_number = i;
			point_array[dfs_array[i]].in_low(point_array[dfs_array[i + 1]].out_low());
		}
		else if (next_op == false)
		{
			find_number = i;
			point_array[dfs_array[i]].in_low(i);
		}
		else
		{
			point_array[dfs_array[i]].in_low(i);
		}

		cout << "i = " << i << " find_number >> " << find_number << endl;


		//��^���� hold_number ��ۦ^��̤j��
		if (point_array[dfs_array[i]].out_number() == 0 || find_number == 0 && i != 0)
		{
			hold_number = n - 1, find_number = n - 1;
		}
	}

	//�j��������ܦ�0
	point_array[0].in_low(0);

	//���low�̲׹B�⵲�G 
	cout << "number, dfs_number , low  >> " << endl;
	for (int i = 0; i < n; i++)
	{
		printf("%2d  >>  %2d  >>  %2d\n", i, dfs_array[i], point_array[dfs_array[i]].out_low());
	}
	cout << endl;
}

//articulation_point >> ���`�I
void insert_articulation_point(int n, point point_array[SIZE], int dfs_array[SIZE], int articulation_point[SIZE], int* articulation_point_n)
{
	int out_n = 0;

	for (int dfn = n - 2; dfn >= 0; dfn--)
	{
		if (dfn == 0)
		{
			if (point_array[dfs_array[dfn]].out_bool_total() > 2)							//�P�_���
			{
				articulation_point[out_n++] = point_array[dfs_array[dfn]].out_number();
			}
		}
		else
		{
			if (dfn <= point_array[dfs_array[dfn + 1]].out_low()) // && point_array[dfs_array[dfn]].out_bool_number_end() == false
			{
				articulation_point[out_n++] = point_array[dfs_array[dfn]].out_number();		//�Q�Τ�����X���`�I
			}
		}
	}
	*articulation_point_n = out_n;
}