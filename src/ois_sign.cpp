#include<iostream>
using namespace std;

int main()
{
 	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		long long int A, B;
		cin >> A >> B;
		if (A < 0 && B < 0)
		{
			long long int d = B - A + 1;
			if (d % 2 == 0)
			{
				cout << "+\n";
			}
			else
			{
				cout << "-\n";
			}
		}
		else if (A > 0 && B > 0)
		{
			cout << "+\n";
		}
		else if (A <= 0 && B >= 0)
		{
			cout << "0\n";
		}
	}
}
