#include <iostream>
using namespace std;

#define MAX_SIZE 50

class Stack
{
    private:
        string s[MAX_SIZE];
        int base;
        int top;
    public:
    	Stack();
        void push(string);
        string pop();
        void printStack(); 
        bool is_empty(); 
        bool is_full();    
};

Stack::Stack()
{
    base = 0;
    top = 0;    
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

void Stack::printStack()
{
    cout << " Stack Content ...." << endl;
    cout << " Top = " << top << endl;
    for (int i = top - 1; i >= base; i--)
        cout << i << "  -> " << s[i] << endl; 
    cout << endl;
}

int main(void)
{
    Stack s;
    int choose;
    string data;
    cout << "System Started ....." << endl;
    while(1)
    {
       cout << "0.Quit  1.Push  2. Pop  3.Print  ==> " ;
       cin >> choose;
       if(choose == 0) break;
       else if(choose == 1)
       {
          if(!s.is_full())
          {
             cout << "Input a value = " ;
             cin >> data;
             s.push(data);
             cout << "Data pushed ...." << endl;
          }
          else
             cout << "Stack Overflow ...." << endl;
       }
       else if(choose == 2)
       {
          if(!s.is_empty()) cout << "Popped out value = " << s.pop() << endl;
          else
            cout << "Stack Empty ...." << endl;
       }
       else if(choose == 3)
       {
          s.printStack();
       }
    }
    cout << "System Finished ....." << endl;
    system("pause");
    return 0;
}
