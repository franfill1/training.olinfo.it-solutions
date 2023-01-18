#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll T, N, M;
	cin >> T >> N;
	vector < pair < ll , ll > > A, B;
	for (ll i = 0; i < N; i++)
	{
		ll l, r;
		cin >> l >> r;
		A.emplace_back(l, r+1);
	}
	cin >> M;
	for (ll i = 0; i < M; i++)
	{
		ll l, r;
		cin >> l >> r;
		B.emplace_back(l, r+1);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	ll ans = 0;
	for (ll i=0, j=0; i < N && j < M;)
	{
		if (A[i] < B[j])
		{
			if (A[i].second > B[j].first && B[j].first - A[i].first <= T)
			{
				if (A[i].second < B[j].second)
					ans += A[i].second - B[j].first, B[j].first = A[i].second, i++;
				else
					ans += B[j].second - B[j].first, A[i].first = B[j].second, j++;
			}
			else
				i++;
		}
		else
		{
			if (B[j].second > A[i].first)
			{
				if (B[j].second < A[i].second)
					ans += B[j].second - A[i].first, A[i].first = B[j].second, j++;
				else
					ans += A[i].second - A[i].first, B[j].first = A[i].second, i++;
			}
			else
				j++;
		}
	}
	cout << ans << "\n";
}
