// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex4.cpp
// Compiler�GDev C++
// Date�G2019/03/26

#include <iostream>
using namespace std;

class Student {
private:
  string car_name, name, car_color; //�إߨp���ܼ� 
public:
  Student(string _car_name = "", string _name = "", string _car_color = "") { //�إߤ��}�ܼƨӧ�p���ܼ� 
  	setStudent(_car_name, _name, _car_color);
  }
  void setStudent(string _car_name, string _name, string _car_color) { //���p���ܼƨ�� 
    car_name = _car_name;
    name = _name;
    car_color = _car_color;
  }
  string getcar_name() { return car_name; }
  string getName() { return name; }
  string getcar_color() { return car_color; }
  string highway() { return name + " on the highway."; } //�ܼƧt�� 
  string newcar() { return name +" the " + car_name + " is new car."; }
  string taxi() { return name + " is taxi."; }
};

int main(void) {
  string car_name, name, car_color;
  cout << "Enter Student's name, car_name, car_color: ";   
  cin >> name >> car_name >> car_color;  //Ū�J�����T�� 
  Student Joe(car_name, name, car_color);
  cout << Joe.getName() << "���@�x" << Joe.getcar_name() << "�O" << Joe.getcar_color() << "\n";
  cout << Joe.highway() << "\n";
  cout << Joe.newcar() << "\n";
  cout << Joe.taxi() << "\n";
}
