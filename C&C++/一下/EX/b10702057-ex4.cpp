// Student No.B10702057  Name縞琑笷 
// File Nameb10702057-ex4.cpp
// CompilerDev C++
// Date2019/03/26

#include <iostream>
using namespace std;

class Student {
private:
  string car_name, name, car_color; //ミ╬Τ跑计 
public:
  Student(string _car_name = "", string _name = "", string _car_color = "") { //ミそ秨跑计ㄓэ╬Τ跑计 
  	setStudent(_car_name, _name, _car_color);
  }
  void setStudent(string _car_name, string _name, string _car_color) { //蛤э╬Τ跑计ㄧ计 
    car_name = _car_name;
    name = _name;
    car_color = _car_color;
  }
  string getcar_name() { return car_name; }
  string getName() { return name; }
  string getcar_color() { return car_color; }
  string highway() { return name + " on the highway."; } //跑计计 
  string newcar() { return name +" the " + car_name + " is new car."; }
  string taxi() { return name + " is taxi."; }
};

int main(void) {
  string car_name, name, car_color;
  cout << "Enter Student's name, car_name, car_color: ";   
  cin >> name >> car_name >> car_color;  //弄ó癟 
  Student Joe(car_name, name, car_color);
  cout << Joe.getName() << "Τ" << Joe.getcar_name() << "琌" << Joe.getcar_color() << "\n";
  cout << Joe.highway() << "\n";
  cout << Joe.newcar() << "\n";
  cout << Joe.taxi() << "\n";
}
