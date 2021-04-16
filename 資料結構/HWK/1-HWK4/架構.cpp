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
// 老鼠收尋順序  = 東 > 南 > 西 > 北
// 老鼠先判斷是否有下一步路  bool can_go_road
// 如果下一步是食物導入  int food_road return food_point
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
## 0 = 未走過的路				-- 1 = 牆壁 
## 2 = 走過正確的路 			-- 3 = 走過錯誤的路 
## + = 體力+50的食物 			-- * = 體力+100的食物 
## $ = 體力+200的食物 			-- # = 出口 
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
	//讀入迷宮地圖
	n = InDate(in);
	char_to_notearray(a, in, n, &x, &y);	
	//列印地圖

	//老鼠出發
}

// x >> 直 
// y >> 橫 

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
	cout << "輸入方程式檔名:";
	cin >> FName;
	InF.open(FName, ios::in);
	if(!InF)
	{
		cout << "檔案無法開啟\n";
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
