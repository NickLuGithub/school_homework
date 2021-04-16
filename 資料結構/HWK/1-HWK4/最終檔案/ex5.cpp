#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<windows.h>
#define size 500
using namespace std;

char t[10], ch, map[size][size], s[] = "Ｏ  ＋＊＄＠。＃", stack[size] = {0};
int x = 0, y = 0, mp_x, mp_y, ms_x, ms_y, base = 0, top = 0, mslf = 500;
void gotoxy(int row, int column)
{
	static HANDLE o = GetStdHandle (STD_OUTPUT_HANDLE);
	COORD c = {row, column};
	SetConsoleCursorPosition (o, c);
}
void setcolor(int color)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void push(int x1, int y1)
{
	stack[top++] = x1;
	stack[top++] = y1;
}
int pop()
{
	return stack[--top];
}
void print()
{
	for(int i = 0; i <= y; i++)
		{
			for(int j = 0; j < x; j++)
				cout << map[i][j];
			cout << endl;
		}
}
void input_map()
{
	fstream file;
	cout << "Input file name:";
	cin >> t;
	file.open(t, ios::in);
	if(!file)
	{
		cout << "open error" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		while(file.get(ch))
		{
			if(ch == '1')
			{
				map[y][x++] = s[0 * 2];
				map[y][x++] = s[0 * 2 + 1];
			}
			else if(ch == '0')
			{
				
				map[y][x++] = s[1 * 2];
				map[y][x++] = s[1 * 2 + 1];
			}
			else if(ch == '+')
			{
				map[y][x++] = s[2 * 2];
				map[y][x++] = s[2 * 2 + 1];
			}
			else if(ch == '*')
			{
				map[y][x++] = s[3 * 2];
				map[y][x++] = s[3 * 2 + 1];
			}
			else if(ch == '$')
			{
				map[y][x++] = s[4 * 2];
				map[y][x++] = s[4 * 2 + 1];
			}
			else if(ch == '#')
			{
				map[y][x++] = s[7 * 2];
				map[y][x++] = s[7 * 2 + 1];
			}
			else if(ch == '\n')
			{
				 map[y++][x] = '\n';
				 x = 0;
			}
		}
		ms_x = x / 2;
		ms_y = y + 1;
		cout << "size : " << ms_x << " Ｘ " << ms_y << endl;
		print();
		file.close();
	}
}
void xy()
{
	int xx, yy;
	xx = mp_x;
	yy = mp_y;
	printf("老鼠座標 : (%3d,%3d)        \n", xx, yy);
}
void get_point(int p)
{
	if(p == 1)	mslf--;
	else mslf += p;
	printf("生命值 : %3d\n", mslf);
	if(mslf == 0)
	{
		cout << "You Lose!!" << endl;
		exit(1);
	}
}
void point()
{
	if(map[mp_y][mp_x * 2] != s[2] && map[mp_y][mp_x * 2] != s[0])
	{
		if(map[mp_y][mp_x * 2] == s[4])
			get_point(50);
		else if(map[mp_y][mp_x * 2] == s[6])
			get_point(80);
		else if(map[mp_y][mp_x * 2] == s[8])
			get_point(100);
		else if(map[mp_y][mp_x * 2] == s[12])
			cout << "You Win~~" << endl;
	}
	else get_point(1);
}
bool check_move(int num)
{
	if(num = 0)//right 
	{
		mp_x++;
		if(map[mp_y][mp_x * 2] != s[0])
		{
			mp_x--;
			return true;
		}
		return false;
	}
	else if(num = 1)//left
	{
		mp_x--;
		if(map[mp_y][mp_x * 2] != s[0])
		{
			mp_x++;
			return true;
		}
		return false;
	}
	else if(num = 2)//up
	{
		mp_y--;
		if(map[mp_y][mp_x * 2] != s[0])
		{
			mp_y++;
			return true;
		}
		return false;
	}
	else if(num = 3)//down
	{
		mp_y++;
		if(map[mp_y][mp_x * 2] != s[0])
		{
			mp_y--;
			return true;
		}
		return false;
	}
}
void mouse_prep()
{
	map[mp_y][mp_x * 2] = s[6 * 2];
	map[mp_y][mp_x * 2 + 1] = s[6 * 2 + 1];
}
void mouse_now()
{
	map[mp_y][mp_x * 2] = s[5 * 2];
	map[mp_y][mp_x * 2 + 1] = s[5 * 2 + 1];
}
void mouse_move()
{
	while(map[mp_y][mp_x * 2] != s[12])
	{
		if(check_move(0))
		{
			push(mp_x, mp_y);
			mouse_prep();
			mp_x++;
			mouse_now();
			gotoxy(0, 2);
			print();
			xy();
			point();
		}
		else if(check_move(1))
		{
			push(mp_x, mp_y);
			mouse_prep();
			mp_x--;
			mouse_now();
			gotoxy(0, 2);
			print();
			xy();
			point();
		}
		else if(check_move(2))
		{
			push(mp_x, mp_y);
			mouse_prep();
			mp_y--;
			mouse_now();
			gotoxy(0, 2);
			print();
			xy();
			point();
		}
		else if(check_move(3))
		{
			push(mp_x, mp_y);
			mouse_prep();
			mp_y++;
			mouse_now();
			gotoxy(0, 2);
			print();
			xy();
			point();
		}
	}
}
void first_mouse()
{
	while(map[mp_y][mp_x * 2] == s[0] && map[mp_y][mp_x * 2 + 1] == s[1])
	{
		gotoxy(0, y + 3);
		cout << "~~~~~~位置輸入錯誤!!~~~~~~" << endl << "->";
		cin >> mp_x >> mp_y;
		gotoxy(0, 2);
	}
	map[mp_y][mp_x * 2] = s[5 * 2];
	map[mp_y][mp_x * 2 + 1] = s[5 * 2 + 1];
	print();
	xy();
	get_point(0);
	system("pause");
}
int main()
{
	system("cls");
	system("mode con cols=165 lines=36");
	input_map();
	cout << "老鼠初始位置(x, y) = ";
	cin >> mp_x >> mp_y;
	gotoxy(0, 2);
	first_mouse();
	mouse_move();
	system("pause");
	return 0;
}
