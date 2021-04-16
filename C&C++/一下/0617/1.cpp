#include <iostream>
using namespace std;

class University {
private:
  string no, name, u_name;
public:
  University(string _no = "", string _name = "", string _u_name = "") {
  	setUniversity(_no, _name, _u_name);
  }
  void setUniversity(string _no, string _name, string _u_name = "") {
    no = _no;
    name = _name;
    u_name = _u_name;
  }
  string getNo() { return no; }
  string getName() { return name; }
  string getU_name() { return u_name; }
  string study() { return name + " 是 " + u_name +  " 大學"; }
  string play() { return name + " 學號是 " + no; }
};

class UnderGraduate : public University {
private:
  string major;
public:
  UnderGraduate(string _no = "", string _name = "", string _u_name = "", string _major = "") {
  	setUnderGraduate(_no, _name, _u_name, _major);
  }
  void setUnderGraduate(string _no = "", string _name = "", string _u_name = "", string _major = "") {
    setUniversity(_no, _name, _u_name);
    major = _major;
  }
  string getMajor() { return major; }
};

int main(void) {
  string name, u_name, no, major; 
  cout << "輸入擬大學名稱 學號 姓名 性別(男/女): ";
  cin >> u_name >> no >> name >> major;
  UnderGraduate in(no, name, u_name, major);
  cout << in.study() << endl << in.play() << endl;
  cout << in.getName() << " 是 "  << in.getMajor() << "生\n"; 
}
