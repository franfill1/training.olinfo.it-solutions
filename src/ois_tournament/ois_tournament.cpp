#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, ma, mi, ans = 0, v;
	cin >> N;
	cin >> ma;
	mi = ma;
	for (int i = 1; i < N; i++)
	{
		cin >> v;
		ans = max(ans, max(v + i - mi, -v + i + ma));
		mi = min(mi, v + i);
		ma = max(ma, v - i);
	}
	cout << ans << "\n";
}
