#include <iostream>
#include <sstream>
using namespace std;

class Set{
private:
	int *s, n;
public:
	Set(int _n){
		n = _n;
		s = new int[n];
	}
	void setSet(int *_s, int n){
		for ( int i = 0; i < n; i++) s[i] = _s[i];
	}
	
	int getS(int i) {
		return s[i];
	}
	int getN() {return n;}
	
	string str(){
		ostringstream out;
		out << "{";
		for ( int i = 0; i < n; i++){
			for ( int k = i; k < n; k++){
				if (s[i] == s[k] && i != n - 2){
					out << s[i] <<", ";
					i++;
				}else if(i == n - 1 && s[i - 1] != s[i - 2]){
					out << s[i] << "}";
				}			
				else if (s[i] == s[k] && i == n - 2){
					out << s[i] <<"}";
					i++;
					break;
				}else{
					out << s[i] << ", ";
				}
			} 
		}
		return out.str();
	}
};

void bubble_sort(int *s, int n){
	for ( int i = 0; i < n; i++){
		for ( int l = 0; l < i; l++){
			if ( s[i] < s[l]){
				int t = s[i];
				s[i] = s[l];
				s[l] = t;
			}
		}
	}
}

int count(string s) {
	int n = 0, pos;
	while ((pos = s.find(" ")) != -1) {
		string token = s.substr(0, pos);
		s.erase(0, pos + 1);
		n++;
	}
	return ++n;
}

/*
class SetS : public Set{
public:
	SetS(Point *a, Point *b, Point *c){
		
	}
};
*/
Set operator + (Set a, Set b){
	int *c, n1 = a.getN(), n2 = b.getN(), n;
	
	n = n1 + n2;
	c = new int[n];
	for ( int i = 0; i < n; i++){
		if (i < n1){
			c[i] = a.getS(i);
		}
		else{
			c[i] = b.getS(i - n1);
		}
	}
	bubble_sort(c, n);
	Set out(n);
	out.setSet(c, n);
	return out;
}

int main ( void ) {
	string line;
	cout << "Enter the first set:";
	getline(cin, line);
	int n1 = count(line);
	Set *s1 = new Set[n1];
	Set a(n1);
	cout << "Enter the second set:";
	getline(cin, line);
	int n2 = count(line);
	Set *s2 = new Set[n2];
	Set b(n2);
	Set c = a + b;
	
	cout << a.Set() << endl;
	cout << b.Set() << endl;
	cout << c.Set() << endl;
}
