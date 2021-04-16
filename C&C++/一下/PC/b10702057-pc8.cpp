#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ( void ) {
	
	srand(time(0));
	int number = rand() % 10 + 1;
	int guess;
	
	cout << "Guess a number (1 - 10):";
	do{
		cin >> guess;
		if ( guess > number) cout << "Too large! ";
		else if ( guess < number) cout << "Too small !";
		else cout << "Correct";
	} while (guess != number);
}
