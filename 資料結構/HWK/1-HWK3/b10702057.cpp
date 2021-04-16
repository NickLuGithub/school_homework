#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 50
using namespace std;

class Stack
{
	private:
		string s[MAX_SIZE];
		double d[MAX_SIZE];
		int top;
		int base;
	public:
		Stack();
		void push(string);
		void push_d(double);
		string pop();
		double pop_d(); 
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

void Stack::push_d(double ch)
{
	d[top++] = ch;
}

double Stack::pop_d()
{
	return d[--top];
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

void Stack::printStack()
{
    cout << " Top = " << top << endl;
    for (int i = top - 1; i >= base; i--)
        cout << i << "  -> " << s[i] << endl; 
    cout << endl;
}

int dateinput(char t[], char d[])
{
	int n = 1000, i;
	char ch;
	scanf("%s", t);
	for (i = 0; i < n; i++)
	{
		if (t[i] == '\0') break;
		else d[i] = t[i];
	}
	n = i;
	cout << "n = " << n << endl;
	return n;
}

int fileopen(char text[], char cb[])
{
	fstream InF;
	int n = 0;                                                                            
	char FName[20], ch;  //FName = 檔名
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
			text[n] = ch;
			cb[n] = ch;
			n++;
		}
		InF.close();
	}
	return n;
}

int cutting_number(char in[], int out[], char* deter)
{
	int n = 0;
	char *sp;
	sp = strtok(in, deter);
	out[n] = atoi(sp);
	n++;
	while((sp = strtok(NULL, deter)) != NULL)
	{
		out[n] = atoi(sp);
		n++;
	}
	return n;
}

int cutting_text(char in[], string *out, char *deter)
{
	int n = 0;
	char *sp;
	sp = strtok(in, deter);
	*out += sp;
	n++;
	while((sp = strtok(NULL, deter)) != NULL)
	{
		*out += sp;
		n++;
	}
	return n;
}

string itos(int a)
{
	stringstream ss;
	ss << a;
	string s;
	ss >> s;
	return s;
}

bool text_inout(string b, string a)
{
	if((a == "+" || a == "-") && (b == "*" || b == "/")) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void infix_to_postfix(string *text, int t_n, int number[], int n_n, string *postfix_text)
{
	Stack a;
	int n = 0;
	string t = text[n];
	string k;
	for ( int i = 0, n = 0; i < n_n || n < t_n - 1; i++)
	{
		if (i == 0)
		{
			*postfix_text += itos(number[i]);
			if (!a.is_full())
			{
				string tt;
				tt = t[n];
				a.push(tt);
				n++;
			}
			else
			{
				cout << "系統計算空間超載\n";
			}
		}
		else if(i == n_n - 1)
		{
			*postfix_text += " " + itos(number[i]);
			while(!a.is_empty())
			{
				k = a.pop();
				*postfix_text += " " + k;
			}
		}
		else
		{
			*postfix_text += " " + itos(number[i]);
			string tt;
			tt = t[n];
			if(!a.is_empty())
			{
				k = a.pop();
				if (!text_inout(k, tt))
				{
					a.push(k);
					a.push(tt);
					n++;
				}
				else
				{
					*postfix_text += " " + k;
					if(!a.is_empty())
					{
						k = a.pop();
						*postfix_text += " " + k;
					}
					a.push(tt);
					n++;
				}
			}
			else
			{
				a.push(tt);
				n++;
			}
		}
	}
}

double run_postfix(string *postfix)
{
	//*postfix >> 資料型態 postfix >> 記憶體位置 
	string b;
	b = *postfix;
	int n = b.size();
	char a[n + 1];
	char *sp;
	strcpy(a, b.c_str()); 
	Stack number;
	sp = strtok(a, " "); 
	number.push_d(atof(sp));
	while ((sp = strtok(NULL, " ")) != NULL)
	{	
		string k;
		k = sp[0];
		if(k == "+" || k == "-" || k == "*" || k == "/")
		{
			if(!number.is_empty())
			{
				double x, y;
				x = number.pop_d();
				y = number.pop_d();
				//cout << "x = " << x << ",y = " << y << endl;
				if (k == "+")
				{
					number.push_d(y + x);
				}
				else if (k == "-")
				{
					number.push_d(y - x);
				}
				else if (k == "*")
				{
					number.push_d(y * x);
				}
				else
				{
					if (x == 0)
					{
						cout << "運算除零錯誤" << endl; 
						exit(1);
					}
					else
					{
						number.push_d(y / (int)x);
					}
				}
			}
		}
		else
		{
			number.push_d(atof(sp));
		}
	} 
	return number.pop_d();
}


int main ( void )
{
	//宣告 
	int n, number[1000];
	int number_n, text_n;
	char number_t[1000], text_t[1000];
	string text;
	double out;
	
	//讀黨
	n = dateinput(number_t, text_t);
	
	//列印中置式 
	cout << "infix is : ";
	for ( int i = 0; i < n; i++) cout << number_t[i];
	cout << endl;
	
	//strtok
	char *deter_1 = " +-*/";
	number_n = cutting_number(number_t, number, &*deter_1);
	char *deter_2 = " 0123456789";
	text_n = cutting_text(text_t, &text, &*deter_2);
	
	//後制式
	string postfix_text;
	infix_to_postfix(&text, text_n, number, number_n, &postfix_text);
	
	//列印後置式 
	cout << "postfix is : " << postfix_text << endl;
	
	//最後運算
	out = run_postfix(&postfix_text);
	cout << "運算結果：" << out << endl;
	
	system("pause");
}
