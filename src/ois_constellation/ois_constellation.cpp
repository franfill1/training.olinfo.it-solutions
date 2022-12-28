#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;
const ll X = 200001, Y = 200001;

int main()
{
	int N;
	cin >> N;
	vector < ll > count(Y, 0);
	vector < pll > V(N);
	
	for (int i = 0; i < N; i++)
	{
		ll x, y;
		cin >> x >> y;
		V[i] = {x, y};
		count[y]++;
	}
	
	vector < ll > si(N);
	for (int i = 0; i < N; i++) si[i] = i;
	vector < ll > dp(X, 0);
	ll ans = 0;
		
	sort(si.rbegin(), si.rend(), [&] (int i, int j) {
		return V[i].second < V[j].second;
	});

	for (int i = 0; i < N; i++)
	{
		int j = si[i];
		ll x = V[j].first, y = V[j].second;
		ans += dp[x];
		dp[x] += count[y]-1;
	}
	
	sort(si.begin(), si.end(), [&] (int i, int j) {
		return V[i].second < V[j].second;
	});
	
	dp.assign(X, 0);
	for (int i = 0; i < N; i++)
	{
		int j = si[i];
		ll x = V[j].first, y = V[j].second;
		ans += dp[x];
		dp[x] += count[y]-1;
	}
	
	cout << ans << "\n";
}


