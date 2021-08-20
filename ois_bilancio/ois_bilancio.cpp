#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k, c;
	cin >> n >> k;
	vector < int > u;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		while(k && u.size() && u.back() > c)
		{
			u.pop_back(); k--;
		}
		u.push_back(c);
	}

	for (int i = 0; i < u.size() - k; i++) cout << u[i] << " ";
}
