// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-ex12.cpp
// Compiler：Dev C++
// Date：2019/05/30
#include <iostream>
using namespace std;

class Dance {
private:
  string name, song;
  int day;
public:  //好多好多CLASS 
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
  string ss() { return name + "是" + song; }
};

class uudace : public Dance {   //更多CLASS選項了YA 
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

int main(void) {    //主程式喔!!!!!!!! 
  string song, name;
  int day, time;
  cout << "輸入歌的類別: ";
  cin >> song;
  cin.get();
  cout << "輸入歌的名稱: ";
  getline(cin, name);
  cout << "輸入跳舞日期: ";
  cin >> day;
  cin.get(); 
  cout << "輸入歌曲時間: ";
  cin >> time;
  uudace Joe(song, name, day, time);
  cout << Joe.ss() << endl;
  cout << Joe.getDay() << "這天要花" << Joe.getTime() << "跳這首" << Joe.getName()  << endl; 
}
