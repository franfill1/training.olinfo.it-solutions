#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	int ans = 1;
	for(int m = 2; m*m <= n; m++)
	{
		int t = m*m;
		while(t*m <= n) t *= m;
		if (t <= n) ans = max(ans, t);
	}
	cout << ans;
}
