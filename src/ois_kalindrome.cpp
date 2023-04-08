#include<bits/stdc++.h>
using namespace std;

string s;
bool check(int l)
{
	if (s.size() % l) return false;

	int i = 0, j = s.size()-l;
	while(i < j)
	{
		if (s.substr(i, l) != s.substr(j, l)) return false;
		i += l;
		j -= l;
	}
	return true;
}

int main()
{
	int N;
	cin >> N >> s;

	int ans = N;
	for (int d = 1; d*d <= N; d++)
	{
		if (N % d == 0)
		{
			if (check(d))
			{
				ans = d;
				break;
			}
			if (check(N/d))
			{
				ans = N/d;
			}
		}
	}
	cout << ans << "\n";
}
