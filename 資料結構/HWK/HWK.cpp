#include<iostream>
using namespace std;

int main ( void )
{
	int n = 5, a[5] = {3, 9, 8, 7, 1};
	for ( int i = 0; i < n; i++)
	{
		for ( int k = i; k > 0; k--)
		{
			if(a[k] < a[k - 1]) swap(a[k], a[k - 1]);
			else break;
		}
	}
	
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
