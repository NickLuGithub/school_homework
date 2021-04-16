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
   cout << "*** ���J���� *** " << endl;   
}

void LinkedList::insert_at_rear(Node* p)
{
   last->link = p;
   last = p;
   cout << "*** ���J���� *** " << endl;   
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
     cout << "*** ���J���� *** " << endl;   
   }
   else
     cout << "�䤣����, �L�k���J....." << endl; 
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
     cout << "*** ��C���e *** " << endl;   
     i = 0;
     ptr = first;
     while (ptr)
     {
        i++;
        cout << ptr->data << " ";
        ptr = ptr->link;
     }
     cout << endl;
     cout << " �@�p " << i << "�����... " << endl;   
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
      cout << "����Ʀb�� " << i << " �Ӹ`�I..." << endl;
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
   if(!is_found) cout << "�L�����..." << endl; 
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
      cout << "�R����Ƨ���..." << endl;
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
    cout << "��J��� : ";
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
     cout << "�п�� : 1.�e�ݴ��J, 2.��ݴ��J, 3.�`�I���J, 4.�j�M, 5.�R��, 6.�C�X, 0.���� -> ";
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
        if(list.no_of_node() == 0) cout << "�L���, �ާ@���~....." << endl; 
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
        if(list.no_of_node() == 0) cout << "�L���, �ާ@���~....." << endl; 
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
        if(found) cout << "���F....." << endl;
        else cout << "�L�����....." << endl; 
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
       cout << "���~�ﶵ!!";
     system("pause");
  }
  return 0;
}
