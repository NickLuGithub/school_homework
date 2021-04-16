// Student No.¡GB10702057  Name¡GLu-YuDa
// File Name¡Gb10702057-hwk4-2.cpp
// Compiler¡GDev C++
// Date¡G2019/06/7
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string> 
#include <sstream>
using namespace std;

void random_array(double a[], int range, int n){
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % range + 1) * 2 - 1;
		for (int j = 0; j < i; j++){
			if (a[i] == a[j]) {
			--i;
			break;
			}
		}
	}
}

class Array {
private:
	double **board;
	int n, m;
public:
	Array(int n, int m){
		board = new double*[n+1];
		for ( int i = 0; i <= n; i++){
			board[i] = new double[m];
		}
	}
	void setArray(double _board[], int _n, int _m){
		n = _n;
		m = _m;
		for ( int i = 0, k = 0; i < n; i++){
			for ( int l = 0; l < m; l++){
				board[i][l] = _board[k++];
			}
		}
	}
	
	void print_array(int n, int m){
		for (int i = 0; i < n; i++){
			for ( int l = 0; l < m; l++){
				if (board[i][l] != 0){
					cout << board[i][l] << " ";
				}
				else{
					cout << "* ";
				}
			}
			cout << endl;
		}
	}
};

void play(double a[], int n, int m){
	
	int player = 0, computer = 0;
	int ki, kl, go;
	double **board;
	
	for ( int i = 0; i < n; i++){
		for ( int l = 0; l < m; l++){
			if (board[i][l] != 0){
				go = 1;
			}
		}
	}
	
	if(go == 1){
			while (player != 0){
			ki = rand() % n + 1;
			kl = rand() % m + 1;
			player = board[ki][kl];
			board[ki][kl] = 0;
		}
		while (computer != 0){
			ki = rand() % n + 1;
			kl = rand() % m + 1;
			computer = board[ki][kl];
			board[ki][kl] = 0;
		}
		cout << "Player: " << player <<" Computer: " << computer << endl;
		if ( player > computer){
			cout << "Player wins 0 points. Computer wins " << player + computer <<" points.\n";
			board[n][0] += player + computer;
		}else if (player < computer){
			cout << "Player wins "<< player + computer << " points.Computer wins 0 points.\n";
			board[n][1] += player + computer;
		}else{
			cout << "Player wins "<< player << " points.Computer wins "<< computer << " points.\n";
			board[n][0] += player;
			board[n][1] += computer;
		}
	}
	else{
		cout << "¹CÀ¸¤wµ²§ô\n";
	}	
}

int main( void ){
	double **inArray, *in;
	int n, m, range;
	string s;
	
	srand(time(0));
	cout << "Enter the size of the table and the value range: ";
	cin >> n >> m >> range;
	in = new double[n * m];
	random_array(in, range, n * m);
	Array in1(n, m);
	in1.setArray(in, n, m);
	in1.print_array(n , m);
	
	do{
		cout << "Continue (Y|N)? ";
		cin >> s;
		do{
			in1.play();
			cout << "Continue (Y|N)? ";
			cin >> s;
		} while(s == "y" || s == "Y");
	} while (s == "y" || s == "Y");
}



