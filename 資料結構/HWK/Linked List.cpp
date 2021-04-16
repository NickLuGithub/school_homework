#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Node
{
   friend class LinkedList;
   private:
     int data;
     Node* link;
   public:
     Node(int x = 0, Node* next = 0)
     {
        data = x;
        link = next;
     }
};

class LinkedList
{
  private:
    Node* first;
    Node* last;
  
  public:
    LinkedList();
    void insert_at_front(Node*);
    void insert_at_rear(Node*);
    void insert_after_a_node(Node*, int);
    Node* search_a_node(int);
    void delete_a_node(int);
    Node* get_a_node(int);
    void listing();
    void print_a_node(Node*);
    int no_of_node();

};

LinkedList::LinkedList()
{
   first = 0;
   last = 0;
}
void LinkedList::insert_at_front(Node* p)
{
   if(!first && !last)
   {
      first = p;
      last = p;
   }
   else
   {
      p->link = first;
      first = p;
   }
   cout << "*** 插入完成 *** " << endl;   
}

void LinkedList::insert_at_rear(Node* p)
{
   last->link = p;
   last = p;
   cout << "*** 插入完成 *** " << endl;   
}

void LinkedList::insert_after_a_node(Node* p, int x)
{
   Node* q;
   
   q = search_a_node(x);
   if(q)
   {
     if(q == last) last = p;
     p->link = q->link;
     q->link = p;  
     cout << "*** 插入完成 *** " << endl;   
   }
   else
     cout << "找不到資料, 無法插入....." << endl; 
}
int LinkedList::no_of_node()
{
     Node* ptr;
     int i;
     
     i = 0;
     ptr = first;
     while (ptr)
     {
        i++;
        ptr = ptr->link;
     }
     return i;
}
void LinkedList::listing()
{
     Node* ptr;
     int i;
     
     cout << endl;
     cout << "First = " << first << endl;
     cout << "Last = " << last << endl;
     cout << "*** 串列內容 *** " << endl;   
     i = 0;
     ptr = first;
     while (ptr)
     {
        i++;
        cout << ptr->data << " ";
        ptr = ptr->link;
     }
     cout << endl;
     cout << " 共計 " << i << "項資料... " << endl;   
}

Node* LinkedList::search_a_node(int x)
{
   int i;
   Node* ptr;
   bool is_found;
   
   ptr = first;
   is_found = false;

   cout << endl;
   i = 0;
   while(ptr)
   {
      i++;
      if (ptr->data == x) 
      {
         is_found = true;
         break;
      } 
      ptr = ptr->link;
   }
   if (is_found)
   {
      cout << "此資料在第 " << i << " 個節點..." << endl;
      return ptr;
   }
   else
      return 0;
}

void LinkedList::delete_a_node(int x)
{
   int i;
   Node* p;
   Node* q;
   bool is_found;
   
   is_found = false;
   q = first;
   p = first;
   i = 0;
   while(q)
   {
      i++;
      if (q->data == x)
      {
         is_found = true;
         break; 
      }
      p = q;
      q = q->link;
   }
   if(!is_found) cout << "無此資料..." << endl; 
   else
   {
      if(p == q) 
      {
         first = q->link;
         if(last == q) last = q->link;
      }
      else
      {
         if (last == q) last = p;
         p->link = q->link;
         
      }
      cout << "刪除資料完成..." << endl;
   }
}

Node* LinkedList::get_a_node(int x)
{   
   Node* p = new Node(x, 0);      
   return p;
}

int input_value()
{
    int x;
 
    cout << endl;
    cout << "輸入資料 : ";
    cin >> x;
    
    return x;
}

int main(void)
{

  LinkedList list;
  Node* p;
  int choice;
  int x, y;
  bool found;
  
  system("mode con cols=140 lines=36");
  while(1)
  {
     system("cls");
     cout << "請選擇 : 1.前端插入, 2.後端插入, 3.節點插入, 4.搜尋, 5.刪除, 6.列出, 0.結束 -> ";
     cin >> choice;
     if (choice == 0) exit(0);
     else if (choice == 1) 
     {
        x = input_value();
        p = list.get_a_node(x);
        list.insert_at_front(p);  
        list.listing();
     }
     else if (choice == 2) 
     {
        if(list.no_of_node() == 0) cout << "無資料, 操作錯誤....." << endl; 
        else
        {
          x = input_value();
          p = list.get_a_node(x);
          list.insert_at_rear(p);  
          list.listing();
        }
     }
     else if (choice == 3) 
     {
        if(list.no_of_node() == 0) cout << "無資料, 操作錯誤....." << endl; 
        else
        {
          x = input_value();
          p = list.get_a_node(x);
          y = input_value();
          list.insert_after_a_node(p, y);  
          list.listing();
        }
     }
     else if (choice == 4) 
     {
        x = input_value();
        found = list.search_a_node(x);  
        if(found) cout << "找到了....." << endl;
        else cout << "無此資料....." << endl; 
     }
     else if (choice == 5) 
     {
        x = input_value();
        list.delete_a_node(x);  
        list.listing();
     }
     else if (choice == 6) 
     {
        list.listing();
     }
     else
       cout << "錯誤選項!!";
     system("pause");
  }
  return 0;
}
