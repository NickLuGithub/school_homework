#include <cstdio>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#define MAX_SIZE 1000 

void setColor(int color);
void gotoxy(int x,int y);
void Delay(int time);

class Stack
{
	private:
		int top;
		int base;
		int stack[MAX_SIZE];
	public:
		Stack();
		void Push(int);
		int Pop();
};

Stack::Stack()
{
	top = 0;
	base = 0;
}

void Stack::Push(int i)
{
	stack[top++] = i;
}

int Stack::Pop()
{
	return stack[--top];
}

class Maze
{
	private:
		int x;
		int y;
		char maze[MAX_SIZE][MAX_SIZE];
		Stack s;
		char mouse[MAX_SIZE][MAX_SIZE];
	public:
		Maze();
		void read_Maze();
		void print_Maze();
		void start();
		void go_East(int,int);
		void go_West(int,int);
		void go_South(int,int);
		void go_North(int,int);
		void go_front(int,int);
		int go_back();
};

Maze::Maze()
{
	x = 0;
	y = 0;
	for(int i = 0;i < MAX_SIZE;i++)
	{
		for(int j = 0;j < MAX_SIZE;j++)
		{
			maze[i][j] = '\0';
			mouse[i][j] = '\0';
		}
	}
}

void Maze::read_Maze()
{
	FILE *fp;
	char filename[20];
	int i,j,ch,m,n;
	
	printf("請輸入檔案名稱：");
	scanf("%s",&filename);
	
	fp = fopen(filename,"r");
	if(fp == NULL)
	{
		printf("檔案開啟失敗！");
	}
	else
	{
		i = j = 0;
		while(!feof(fp))
		{
			ch = fgetc(fp);
			if(ch == '\n')
			{
				i = 0;
				j++;
			}
			else
			{
				maze[i][j] = ch;
				i++;
			}
		}
		x = i;
		y = j+1;
	}
	printf("\n");
	print_Maze();
}

void Maze::print_Maze()
{
	for(int j = 0;j < y;j++)
	{
		for(int i = 0;i < x;i++)
		{
			if(maze[i][j] == '0')
			{
				if((i == 0) && (j == 1))
				{
					setColor(61);
					printf("●");
					setColor(7);
				}
				else
				{
					setColor(15);
					printf("　");
					setColor(7);
				}	
			}
			if(maze[i][j] == '1')
			{
				setColor(45);
				printf("■");
				setColor(7);
			}
			if(maze[i][j] == '+')
			{
				setColor(61);
				printf("＋");
				setColor(7); 
			}
			if(maze[i][j] == '*')
			{
				setColor(61);
				printf("＊");
				setColor(7);
			}
			if(maze[i][j] == '#')
			{
				setColor(61);
				printf("＃");
				setColor(7);
			}
			if(maze[i][j] == '$')
			{
				setColor(61);
				printf("＄");
				setColor(7);
			 } 
		}
	printf("\n");
	}
}

void Maze::go_East(int i,int j)
{
	gotoxy(i,j+1);
	printf("▲");
	j = j + 1;
}

void Maze::go_West(int i,int j)
{
	gotoxy(i,j-1);
	printf("▲");
	j = j - 1;
}

void Maze::go_South(int i,int j)
{
	gotoxy(i+1,j);
	printf("▲");
	i = i + 1;
}

void Maze::go_North(int i,int j)
{
	gotoxy(i-1,j);
	printf("▲");
	i = i - 1;
}

void Maze::go_front(int i,int j)
{
	if(maze[i][j+1] != '1')
	{
		go_East(i,j);
		Delay(0.1*1000);
	}
	else if(maze[i+1][j] != '1')
		 {
		 	go_South(i,j);
		 	Delay(0.1*1000);
		 }
	else if(maze[i][j-1] != '1')
		 {
		 	go_West(i,j);
		 	Delay(0.1*1000);
		 }
	else if(maze[i-1][j] != '1') 
		 {
		 	go_North(i,j);
		 	Delay(0.1*1000);
		 } 
}

void Maze::start()
{
	int energy = 500;
	int i,j;
	i = 1;
	j = 0;
	read_Maze();
	system("pause");
	
	
	printf("--------------------\n");
}

int main(void)
{
	Maze m;
	system("mode con cols=165 lines=36");
	m.start();
	system("pause");
	
	return 0;
}

void gotoxy(int x,int y)
{
	static HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {y,x};
	SetConsoleCursorPosition(o,c);
}

void setColor(int color)
{
  	HANDLE hConsole;
  	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	SetConsoleTextAttribute(hConsole,color);     
}

void Delay(int time)
{ 
	clock_t now = clock(); 

	while(clock() - now < time); 
}
