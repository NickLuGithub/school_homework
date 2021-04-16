#include <iostream>
using namespace std;

int main()
{
	int t, a, b, x, y;
	
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b >> x >> y;
		x++;
		y++;
		
		int maxY, maxX;
		maxY = max(b-y, y - 1);
		maxX = max(a-x, x - 1);
		
		//cout << maxX << " " << maxY << endl;
		int area1 = maxX * b;
		int area2 = maxY * a;
		
		if(area1 > area2) cout << area1 << endl;
		else  cout << area2 << endl;
	
	}
	
	return 0;
}
