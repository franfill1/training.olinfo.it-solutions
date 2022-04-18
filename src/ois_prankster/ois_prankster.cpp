#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int prv = 0, v;
	int a = 0, b = 0;
	while(N--)
	{
		cin >> v;
		if ((v - prv + 3) % 3 == 1) a++;
		if ((v - prv + 3) % 3 == 2) b++;
		prv = v;
	}
	if (b > a) swap(a, b);
	a -= b;
	cout << b + (a / 3 * 2) + (a % 3) << "\n";
}
