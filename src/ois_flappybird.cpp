#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a, b;
	cin >> a >> b;
	while(--N)
	{
		int a1, b1;
		cin >> a1 >> b1;
		if (a1 > b || b1 < a)
		{
			cout << "NO\n";
			return 0;
		}
		a = a1, b = b1;
	}
	cout << "YES\n";
}
