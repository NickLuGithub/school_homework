// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-ex11.cpp
// Compiler�GDev C++
// Date�G2019/05/16
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Guess {
private:
	int *a, n;
public:
	Guess(int _n) {
		n = _n;
		a = new int[n]; 
	}
	
	void setGuess(int *_a, int n){   //Ū�}�C  
		for ( int i = 0; i < n; i++){
			a[i] = _a[i];
		}
	}
		
	int compare(int *g) {            //���  
		int k = 0;
		for ( int i = 0; i < n; i++){
			for ( int q = 0; q < n; q++){
				if ( a[i] == g[q]){
					k++;
				}
			}
		}
		return k;
	}
	
	void Print_G(){                 //�C�L�}�C 
		for ( int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
};

void in_array(int a[], int n){      //Ū 
	for ( int i = 0; i < n; i++){
		cin >> a[i];
	}
}

void rand_array(int a[], int n){    //�ü� 
	for ( int i = 0; i < n; i++){
		a[i] = rand() % 100 + 1;
		for ( int k = 0; k < i; k++){
			if ( a[i] == a[k]){
				i--;
				break;
			}
		} 
	}
}

int main ( void ) {
	
	srand(time(0));
	
	int *g, *k, n;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter " << n << " numbers between 1 and 100: ";
	
	g = new int[n];  //���a  
	k = new int[n];  //�q��  
	
	in_array(g, n);
	rand_array(k ,n);
	
	Guess guess(n);
	Guess number(n);
	guess.setGuess(g, n);
	number.setGuess(k, n);
	
	cout << "The numbers are: ";
	number.Print_G();
	cout << "You guessed " << guess.compare(k) << " numbers correctly."<< endl;	

}

