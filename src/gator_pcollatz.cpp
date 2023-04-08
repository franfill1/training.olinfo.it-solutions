#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int A, B;
	cin >> A >> B;

	int ans = 0;
	for (int i = A; i <= B; i++)
	{
		int a = i, b = i;
		while(a != 1 && b != 1)
		{
			if (a % 2 == 0)
			{
				a /= 2;
			}
			else
			{
				a = a * 3 + 1;
			}
			if (b % 2 == 0)
			{
				b /= 2;
			}
			else
			{
				b = b * 5 + 1;
			}

		}
		if (a != 1) ans++;
	}
	cout << ans << "\n";
}
