#include<iostream>
using namespace std;

int fib1(int n){
	if (n <= 1) return n;
	else {
		int i = 2, a = 0, b = 1, c;
		while(i <= n){
			c = a + b;
			a = b;
			b = c;
			i++;
		}
		return c;
	} 
}

int fib2(int n){
	if (n <= 1) return n;
	else return (fib2(n - 1) + fib2(n - 2));
}

int main ( void ){
	int n;
	cin >> n;
	cout << fib2(n);
}
