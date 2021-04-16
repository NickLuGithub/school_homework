#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime> 

using namespace std;

string select (string words[], int n){
	return words[rand() % n];
}

string scramble(string word) {
	for (int i = 0;i < word.length(); i++) {
		int r = rand() % word.length();
		char t = word[i];
		word[i] = word[r];
		word[r] = t;
	}
	return word;
}

int main ( void ){
	int n;
	
	srand(time(0));
	cout << "Enter the number of words: ";
	cin >> n;
	string *words = new string[n];
	cout << "Enter " << n << " words: ";
	for ( int i = 0; i < n; i++) cin >> words[i];
	string word = select(words, n);
	cout << "The randomly selected word is " << word << " and scrambled as " << scramble(word) << endl;
}
