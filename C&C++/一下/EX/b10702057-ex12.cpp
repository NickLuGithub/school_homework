// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex12.cpp
// Compiler�GDev C++
// Date�G2019/05/30
#include <iostream>
using namespace std;

class Dance {
private:
  string name, song;
  int day;
public:  //�n�h�n�hCLASS 
  Dance(string _song = "", string _name = "", int _day = 0) {
  	setDance(_song, _name, _day);
  }
  void setDance(string _song, string _name, int _day) {
    song = _song;
    name = _name;
    day = _day;
  }
  string getSong() { return song; }
  string getName() { return name; }
  int getDay() { return day; }
  string ss() { return name + "�O" + song; }
};

class uudace : public Dance {   //��hCLASS�ﶵ�FYA 
private:
  int time;
public:
   uudace (string _song = "", string _name = "", int _day = 0, int _time = 0) {
   	  setuudace(_song, _name, _day, _time);
   }	
   void setuudace(string _song, string _name, int _day, int _time) {
   	  setDance(_song, _name, _day);
   	  time = _time;
   }
   int getTime() { return time; }
};

int main(void) {    //�D�{����!!!!!!!! 
  string song, name;
  int day, time;
  cout << "��J�q�����O: ";
  cin >> song;
  cin.get();
  cout << "��J�q���W��: ";
  getline(cin, name);
  cout << "��J���R���: ";
  cin >> day;
  cin.get(); 
  cout << "��J�q���ɶ�: ";
  cin >> time;
  uudace Joe(song, name, day, time);
  cout << Joe.ss() << endl;
  cout << Joe.getDay() << "�o�ѭn��" << Joe.getTime() << "���o��" << Joe.getName()  << endl; 
}
