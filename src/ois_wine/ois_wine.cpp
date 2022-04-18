#include<bits/stdc++.h>
#pragma gcc Optimize("O3")
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; ll K;
	cin >> N >> K;
	vector < ll > V(N);

	ll a=0, b=0;
	for (int i = 0; i < N; i++) 
	{
		cin >> V[i];
		b += V[i];
	}

	auto calc = [V, N](ll val)
	{
		ll sum = 0, ans = 0;	
		int r = 0;
		for (int l = 0; l < N; sum -= V[l++])
		{
			while(r < N && sum <= val) sum += V[r++];
			ans += r-l - (sum > val);
		}
		return ans;
	};
	
	while(a < b-1)
	{
		ll m = (a+b)/2;
		ll v = calc(m);
		if (v < K) a = m;
		else b = m;
	}

	int r = 0;
	ll sum = 0;
	K -= calc(a);
	for (int l = 0; l < N; sum -= V[l++])
	{
		while (r < N && sum < b) sum += V[r++];
		if (sum == b) K--;
		if (K == 0)
		{
			cout << l << " " << r-1 << "\n";
			return 0;
		}
	}
}
