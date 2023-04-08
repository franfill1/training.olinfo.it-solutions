#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n, k;
	cin >> n >> k;
	vector < ll > C(n), U(n, 0);
	for (auto &c : C) cin >> c;

	ll ans = 0;
	while(k--)
	{
		int t;
		ll q;
		cin >> t >> q;
		ans -= q;
		if (q + U[t] > C[t])
			ans += C[t], U[t] = 0;
		U[t] += q;
	}
	for (int t = 0; t < n; t++)
		if (U[t])
			ans += C[t];
	cout << ans << "\n";
}
