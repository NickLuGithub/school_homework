#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
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

string dateinput()
{
	string t;
	cout << "請輸入：";
	cin >> t;
	return t;
}

string infix_to_postfix(string infix)
{
	string postfix;
	Stack a;
	for ( int i = 0; i < infix.size(); i++)
	{
		string op;
		op = infix[i];
		switch(infix[i]){
			case '0':case '1':case '2':case '3':case '4':
			case '5':case '6':case '7':case '8':case '9':
				postfix += infix[i];
				break;
			case '+':case '-':
				postfix += " ";
				if(a.is_empty())
				{
					a.push(op);
				}
				else
				{
					postfix += a.pop() + " ";
					if(!a.is_empty())
					{
						postfix += a.pop() + " ";
					}
					a.push(op);
				}
				break;
			case '*':case '/':
				postfix += " ";
				if(!a.is_empty())
				{
					string t;
					t = a.pop();
					if (t == "+" || t == "-")
					{
						a.push(t);
						a.push(op);
					}
					else
					{
						postfix += t + " ";
						a.push(op);
					}
				}
				else
				{
					a.push(op);
				}
				break;
		}
					
	}
	while(!a.is_empty())
	{
		postfix += " " + a.pop();
	}
	return postfix;
}

double run_postfix(string postfix)
{
	double number, x, y;
	string op, op1, op2;
	Stack a;
	for (int i = 0; i < postfix.size(); i++)
	{
		op = postfix[i];
		switch(postfix[i])
		{
			case '0':case '1':case '2':case '3':case '4':
			case '5':case '6':case '7':case '8':case '9':
				number = number * 10 + (postfix[i] - '0');
				break;
			case ' ':
				a.push_d(number);
				number = 0;
				break;
			case '+':
			    x = a.pop_d();
			    y = a.pop_d();
			    a.push_d(y + x);
			    i++;
			    break;
			case '-':
				x = a.pop_d();
			    y = a.pop_d();
			    a.push_d(y - x);
			    i++;
			    break;
			case '*':
				x = a.pop_d();
			    y = a.pop_d();
			    a.push_d(y * x);
			    i++;
			    break;
			case '/':
				x = a.pop_d();
			    y = a.pop_d(); 
			    if ((float)x == 0)
			    {
			    	cout << "不符邏輯運算錯誤" << endl;
			    	system("pause");
			    	exit(1);
				}
				else
				{
					a.push_d((float)y / x);
					i++;
				}
				break;
		}
	}
	return a.pop_d();
}


int main ( void )
{
	//宣告 
	string infix, postfix;
	double out;
	
	//讀黨
	infix = dateinput();
	cout << "Infix = " << infix << endl;
	
	//後制式
	postfix = infix_to_postfix(infix);
	cout << "Postfix = " << postfix << endl;
	
	//最後運算
	out = run_postfix(postfix);
	cout << "運算結果：" << out << endl;
	
	system("pause");
}
