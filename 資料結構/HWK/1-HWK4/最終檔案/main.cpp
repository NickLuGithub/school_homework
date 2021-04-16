#include <iostream>
#include <fstream>
#include <windows.h>
#include <dos.h>
#include <conio.h>
#define x_max 200
#define y_max 200
using namespace std;

typedef struct{
	int type;
}note;

typedef struct{
	int x, y;
}point;

point nextpoint(point now, note a[][y_max]);
void clearline(int n);
void pause(int n);
void gotoxy(int x, int y);
void getxy(int &x, int &y);
void ConsoleFullScreen();
void setColor(int color);
void char_to_notearray(note a[][y_max], char in[], int n, int *x, int *y);
void printSwitch(int a);
void print_map(note a[][y_max], int x, int y);
void foodpoint(point p, note a[][y_max]);
void mouse_stack(note a[][y_max], int x, int y, int gox, int goy);
void print_mouse_point(int x);
void runtime();
bool CheakAll(point p, note a);
bool not1or3(point p, note a[][y_max]);
int InDate(char in[]);

//全域變數 
int mouse_point = 500;
int op = 1;
int op4or8 = 1;
int time = 10;
int timeop = 10; 
point start;

int main ( void )
{
	int t;
	int x = 0, y = 0, n = 0;
	int gox, goy;
	char in[x_max * y_max];
	note a[x_max][y_max];
	
	
	system("mode con cols=165 lines=50");
	system("cls");
	
	//讀入迷宮地圖
	n = InDate(in);
	char_to_notearray(a, in, n, &x, &y);	
	//列印地圖
	print_map(a, x, y);
	
	//輸入老鼠投放位置 
	bool run = true;
	cout << "\n請輸入老鼠要投置位置(x, y):";
	do
	{
		cin >> goy >> gox;
		if(a[gox][goy].type == '1') clearline(x + 3), gotoxy(x + 3, 0), cout << "牆壁無法投放，再輸入一次。";
		else if(gox >= x || goy >= y || (gox >= x && goy >= y)) clearline(x + 3), gotoxy(x + 3, 0), cout << "超出範圍，再輸入一次。";
		else run = false;
	}
	while(run);
	
	cout << "請輸入老鼠要行走的速度(數字越小越快):";
	do
	{
		cin >> time;
		if(time <= 0) clearline(x + 4), gotoxy(x + 4, 0), cout << "時間輸入錯誤";
	}
	while(time <= 0);
	timeop = time;
	
	cout << "請輸入老鼠可行走的方位(4 or 8):";
	do
	{
		cin >> t;
		if (t == 4 || t == 8) op4or8 = t;
		else clearline(x + 5), gotoxy(x + 5, 0), cout << "方位輸入錯誤";
	}
	while(t != 8 && t != 4);
	
	//老鼠投放至起始位置 
	gotoxy(2 + gox, goy * 2);
	printSwitch('@');
	print_mouse_point(x);
	pause(x + 16);
	
	//老鼠開跑囉!!!! 
	mouse_stack(a, x, y, gox, goy);
	
	//結束!!
	pause(x + 16);
}

void clearline(int n)
{
	gotoxy(n, 0);
	cout << "                                                                                   ";
}

void ConsoleFullScreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0);
    keybd_event(VK_RETURN,0x9c,KEYEVENTF_KEYUP,0);
}

void pause(int n)
{
	gotoxy(n, 0);
	system("pause");
	gotoxy(n, 0);
	cout << "                                         ";
}

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
		exit(1);
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

void char_to_notearray(note a[][y_max], char in[], int n, int *x, int *y)
{
	int xx = 0, yy = 0, maxY = 0;
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
			if(yy > maxY) maxY = yy;
		}
	}
	if (in[n - 1] != '\n') xx++;
	*x = xx;
	*y = maxY;
}

void printSwitch(int a)
{
	/*
	## 0 = 未走過的路				-- 1 = 牆壁 
	## 2 = 走過正確的路 			-- 3 = 走過錯誤的路 
	## + = 體力+50的食物 			-- * = 體力+100的食物 
	## $ = 體力+200的食物 			-- # = 出口 
	## + == 43, * == 42, $ == 36
	*/ 
	switch(a)
	{
		case '0':  //未走過的路
		case 8:    //沒能量 
			setColor(15); 
			cout << "　";
			break;
		case '1':  //牆壁 
			setColor(155);
			cout << "■";
			setColor(15);
			break;
		case 9:    //有能量 
			setColor(200);
			cout << "　";
			setColor(15);
			break;
		case '2':  //走過錯誤的路 
			setColor(127);
			cout << "．";
			setColor(15);
			break;
		case '3':  //走過正確的路 
			setColor(14);
			cout << "．";
			setColor(15);
			break;
		case '+':  //體力+50的食物 
			setColor(78);
			cout << "＋";
			setColor(15); 
			break;
		case '*':  //體力+80的食物 
			setColor(78);
			cout << "＊";
			setColor(15); 
			break;
		case '$':  //體力+100的食物 
			setColor(78);
			cout << "＄";
			setColor(15); 
			break;
		case '#':  //出口 
			setColor(117);
			cout << "＃";
			setColor(15); 
			break;
		case '\n': //換行切換 
			setColor(15);
			cout << "　";
			cout << "\n";
			break;
		case '@':  //老鼠 
			setColor(160);
			cout << "＠";
			setColor(15);
			break;		 
	}
}

void print_map(note a[][y_max], int x, int y)
{
	cout << "迷宮大小 x = " << y << ", y = " << x << endl;
	for (int i = 0; i < x; i++)
	{
		for (int l = 0; l < y; l++)
		{
			printSwitch(a[i][l].type);
		}
		setColor(15);
		printSwitch('\n');
	}
}

void print_mouse_point(int x)
{
	gotoxy(7 + x, 0);
	if (mouse_point > 0)
	{
		printf("老鼠目前能量 = %4d ", mouse_point);
		int hundreds, tens, n_total;
		hundreds = mouse_point / 100;
		tens = mouse_point % 100;
		if (tens > 50) n_total = hundreds * 2 + 1;
		else n_total = hundreds * 2;
		for (int i = 0; i < n_total; i++)  printSwitch(9);
		for (int i = 0; i < 11 - n_total; i++) printSwitch(8);
	} 
	else
	{
		cout << "                                              ";
		cout << "老鼠能量用盡死亡!!!"; 	
	 }  
}

bool not1or3(point p, note a[][y_max])
{	
	int k = a[p.x][p.y].type;
	if(k == '0' || k == '+' || k == '*' || k == '$' || k == '#') return true;
	else return false;
}

void foodpoint(point p, note a[][y_max])
{
	switch(a[p.x][p.y].type)
	{
		case '+':
			mouse_point += 50;
			a[p.x][p.y].type = '3';
			break;
		case '*':
			mouse_point += 80;
			a[p.x][p.y].type = '3';
			break;
		case '$':
			mouse_point += 100;
			a[p.x][p.y].type = '3';
			break;
		case '#':
			op = 0;
			break;
		default:
			a[p.x][p.y].type = '3';
	}
}

point nextpoint(point now, note a[][y_max])
{
/*
// 老鼠收尋順序  = 東 > 南 > 西 > 北
// 老鼠先判斷是否有下一步路  bool can_go_road
// 如果下一步是食物導入  int food_road return food_point
// 如果往下個方向不能前進，給定 out(-1, -1) 
*/	
	point out, p;
	
	if(not1or3(p = {now.x, now.y + 1}, a) == true)
	{
		out.x = now.x;
		out.y = now.y + 1;
		foodpoint(out, a);
	}
	else if (not1or3(p = {now.x + 1, now.y + 1}, a) == true && op4or8 == 8)
	{
		out.x = now.x + 1;
		out.y = now.y + 1;
		foodpoint(out, a);
	}
	else if (not1or3(p = {now.x + 1, now.y}, a) == true)
	{
		out.x = now.x + 1;
		out.y = now.y;
		foodpoint(out, a);
	}
	else if (not1or3(p = {now.x + 1, now.y - 1}, a) == true && op4or8 == 8)
	{
		out.x = now.x + 1;
		out.y = now.y - 1;
		foodpoint(out, a);
	}
	else if (not1or3(p = {now.x, now.y - 1}, a) == true)
	{
		out.x = now.x;
		out.y = now.y - 1;
		foodpoint(out, a);
	}
	else if (not1or3(p = {now.x - 1, now.y - 1}, a) == true && op4or8 == 8)
	{
		out.x = now.x - 1;
		out.y = now.y - 1;
		foodpoint(out, a);
	}
	else if (not1or3(p = {now.x - 1, now.y}, a) == true)
	{
		out.x = now.x - 1;
		out.y = now.y;
		foodpoint(out, a);
	}
	else if (not1or3(p = {now.x - 1, now.y + 1}, a) == true && op4or8 == 8)
	{
		out.x = now.x - 1;
		out.y = now.y + 1;
		foodpoint(out, a);
	}
	else
	{
		out.x = -1;
		out.y = -1;
	}
	return out;
}

void runtime()
{
	switch(mouse_point)
	{
		case 1 ... 200:
			time = timeop * 0.5;
			break;
		case 201 ... 300:
			time = timeop * 0.75;
			break;
		case 301 ... 400:
			time = timeop * 0.8;
			break;
		case 401 ... 500:
			time = timeop;
			break;
		case 501 ... 1000:
			time = timeop * 1.5;
			break;
		default:
			time = timeop * 0.3;	
	}
}

bool CheakAll(point p, note a[][y_max])
{
	int t;
	t = a[p.x][p.y].type;
	if (t == '0' || t == '+' || t == '*' || t == '$') return true;
	else return false;
}

void mouse_stack(note a[][y_max], int x, int y, int gox, int goy)
{
	point next, stack_p[1000];
	int top = 0, Exit = 0;
	stack_p[top] = {gox, goy};
	a[stack_p[top].x][stack_p[top].y].type = '3';
	while (Exit == 0 && mouse_point > 0)
	{
		do
		{
			print_mouse_point(x);
			next = nextpoint(stack_p[top], a);	
			//先讓上一步路重新顯示
			gotoxy(2 + stack_p[top].x, stack_p[top].y * 2);
			printSwitch(a[stack_p[top].x][stack_p[top].y].type);
			
			gotoxy(8 + x, 0);
			printf("老鼠目前位置 x, y = (%2d, %2d)", stack_p[top].x, stack_p[top].y);
			
			if (next.x != -1 && next.y != -1)
			{
				//老鼠成功找到下一步，再前往下一步。 
				
				if (a[stack_p[top].x][stack_p[top].y].type == '2' && op4or8 == 4) 
				{
					a[stack_p[top].x][stack_p[top].y].type = '3';
					gotoxy(2 + stack_p[top].x, stack_p[top].y * 2);
					printSwitch(a[stack_p[top].x][stack_p[top].y].type);
				}
				
				if (op4or8 == 8)
				{
					a[stack_p[top].x][stack_p[top].y].type = '3';
					gotoxy(2 + stack_p[top].x, stack_p[top].y * 2);
					printSwitch(a[stack_p[top].x][stack_p[top].y].type);
				}
				
				top++;
				stack_p[top] = next;
				
				gotoxy(2 + stack_p[top].x, stack_p[top].y * 2);
				printSwitch('@');
				
				if (op == 0)
				{
					mouse_point--;
					Exit = 1;
					break;
				}
			} 
			else if(next.x == -1 && next.y == -1 && top >= 0)
			{
				//老鼠找不到下一步路，退到上一步路，並讓目前這部重新顯示錯誤的路 。 
				a[stack_p[top].x][stack_p[top].y].type = '2';
				gotoxy(2 + stack_p[top].x, stack_p[top].y * 2);
				printSwitch(a[stack_p[top].x][stack_p[top].y].type);			
				
				top--;
				
				a[stack_p[top].x][stack_p[top].y].type = '2';
				gotoxy(2 + stack_p[top].x, stack_p[top].y * 2);
				printSwitch('@');
			}
			else
			{
				mouse_point--;
				Exit = 1;
				break;
			}
			runtime();
			gotoxy(9 + x, 0);
			printf("老鼠目前速度 %4d(ms)", time);
			_sleep(time);
			mouse_point--;
		} while(mouse_point > 0 && top > 0); //判斷老鼠能量  
		
		point q;
		int k = 0;
		if (top == 0)
		{	
			if (CheakAll(q = {stack_p[top].x    , stack_p[top].y + 1}, a)) k = 1;
			if (CheakAll(q = {stack_p[top].x + 1, stack_p[top].y    }, a)) k = 1;
			if (CheakAll(q = {stack_p[top].x    , stack_p[top].y - 1}, a)) k = 1;
			if (CheakAll(q = {stack_p[top].x - 1, stack_p[top].y    }, a)) k = 1;
		} 
		if (top == 0 && op == 8)
		{
			if (CheakAll(q = {stack_p[top].x + 1, stack_p[top].y + 1}, a)) k = 1;
			if (CheakAll(q = {stack_p[top].x + 1, stack_p[top].y - 1}, a)) k = 1;
			if (CheakAll(q = {stack_p[top].x - 1, stack_p[top].y - 1}, a)) k = 1;
			if (CheakAll(q = {stack_p[top].x - 1, stack_p[top].y + 1}, a)) k = 1;
		}
		if (top == 0 && k == 0) Exit = 1;
	}	 
	
	//最後結算顯示 
	if (op == 0 && mouse_point != 0)
	{
		print_mouse_point(x);
		gotoxy(2 + stack_p[top-1].x, stack_p[top-1].y * 2);
		printSwitch(a[stack_p[top-1].x][stack_p[top-1].y].type);
		gotoxy(8 + x, 0);
		printf("老鼠目前位置 x, y = (%2d, %2d)\n", stack_p[top].x, stack_p[top].y);
		gotoxy(10 + x, 0);
		cout << "The mouse successfully escaped the maze!!!"; 
	}
	if (mouse_point == 0)
	{
		print_mouse_point(x);
	}
	if (top <= 0)
	{
		gotoxy(10 + x, 0);
		cout << "No exit from the maze."; 
	}
}
