#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#define x_max 100
#define y_max 100
using namespace std;

void gotoxy(int x, int y);
void setColor(int color);
int InDate(char in[]);

class Stack
{
	private:
		string s[MAX_SIZE];
		int top;
		int base;
	public:
		Stack();
		void push(string);
		string pop();
		bool is_empty(); 
		bool is_full();
		void printStack();
};

Stack::Stack()
{
	top = 0;
	base = 0;
}

void Stack::push(string ch)
{
	s[top++] = ch;
}

string Stack::pop()
{
	return s[--top];
}

bool Stack::is_empty()
{
	if (top <= base) return true;
	else return false;
}

bool Stack::is_full()
{
	if (top >= MAX_SIZE) return true;
	else return false;
}

typedef struct{
	string type;
}note;

void char_to_notearray(note a[][y_max], char in[], int n, int *x, int *y)
{
	int xx = 0, yy = 0;
	for ( int i = 0; i < n; i++)
	{
		if (in[i] == '\n')
		{
			xx += 1;
			yy = 0;
		}
		else
		{
			a[xx][yy++].type = in[i];
		}
	}
	yy--;
	*x = xx;
	*y = yy;
}

/*
// �ѹ����M����  = �F > �n > �� > �_
// �ѹ����P�_�O�_���U�@�B��  bool can_go_road
// �p�G�U�@�B�O�����ɤJ  int food_road return food_point
*/

class mouse
{
	private:
		int mouse_life_point;
		note mouse_map[x_max][y_max];
	public:
		bool can_go_road();
		int food_road();
}

mouse::mouse()
{
	mouse_life_point = 500;
}

void mouse_now_print()
{
	
}

void mouse_gonow()
{
	
}

/*
## 0 = �����L����				-- 1 = ��� 
## 2 = ���L���T���� 			-- 3 = ���L���~���� 
## + = ��O+50������ 			-- * = ��O+100������ 
## $ = ��O+200������ 			-- # = �X�f 
## + == 43, * == 42, $ == 36
*/ 

void printmap(note a[][y_max], int x, int y)	 
{												 
	system("cls");								
	string out;									  
	for(int i = 0; i <= x; i++)					
	{
		out += "\r";
		for(int l = 0; l <= y; l++)
		{
			out += a[i][l].type;
		}
		out += "\n";
	}
	cout << out;
}

int main ( void )
{
	int x = 0, y = 0, n = 0;
	char in[x_max * y_max];
	note a[x_max][y_max];
	//Ū�J�g�c�a��
	n = InDate(in);
	char_to_notearray(a, in, n, &x, &y);	
	//�C�L�a��

	//�ѹ��X�o
}

// x >> �� 
// y >> �� 

void gotoxy(int x, int y)
{
	static HANDLE o = GetStdHandle (STD_OUTPUT_HANDLE);
	COORD c = {y, x};
	SetConsoleCursorPosition (o, c);
}

void setColor(int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

//setColor(12);
//setColor(15);

int InDate(char in[])
{
	fstream InF;
	int n = 0;                                                                            
	char FName[20], ch;
	cout << "��J��{���ɦW:";
	cin >> FName;
	InF.open(FName, ios::in);
	if(!InF)
	{
		cout << "�ɮ׵L�k�}��\n";
	}
	else
	{
		while(InF.get(ch))
		{
			in[n] = ch;
			n++;
		}
		InF.close();
	}
	return n;
}
