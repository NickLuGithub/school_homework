#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, x, y, X_max, Y_max;
		cin >> a >> b >> x >> y;
		a--, b--;
		
		if (a - x > x)
		{
			X_max = a - x;
		}
		else
		{
			X_max = x;
		}
		
		if (b - y > y)
		{
			Y_max = b - y;
		}
		else
		{
			Y_max = y;
		}
		
		if (X_max > Y_max)
		{
			cout << X_max * ++b << endl;
		}
		else
		{
			cout << Y_max * ++a << endl;
		}
	}	
	return 0;
}
