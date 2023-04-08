#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;

	int c = 0;
	while(a != 1 || b != 1)
	{
		if (c > 1000000) 
		{
			c = -1;
			break;
		}

		if (a % 2 == 0 && b % 2 == 0)
		{
			a /= 2;
			b /= 2;
		}
		else if (a % 2 == 1 && b % 2 == 1)
		{
			a = a * 3 + 1;
			b = b * 3 + 1;
		}
		else if (a % 2 == 1)
		{
			a += 3;
		}
		else
		{
			b += 3;
		}
		c++;
	}
	cout << c << "\n";
}
