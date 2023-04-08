#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, c;
	cin >> n >> c;
	vector < int > C(n);
	for (int &v : C)
		cin >> v;
	vector < int > cnt(c, 0);
	int fn = 0, r = 0, ans = n;
	for (int l = 0; l < n; l++)
	{
		while(r < n && fn < c)
		{
			if (cnt[C[r]] == 0)
				fn++;
			cnt[C[r++]]++;
		}
		if (fn == c)
			ans = min(ans, r-l);
		if (cnt[C[l]] == 1)
			fn--;
		cnt[C[l]]--;
	}
	cout << ans << "\n";
}
