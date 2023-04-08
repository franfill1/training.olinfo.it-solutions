#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;
	vector < pair < int , int > > V(N);
	for (auto &[p, d] : V)
	{
		cin >> p >> d;
		if (d == -1) d = L-1;
	}

	set < int > s;
	for (int i = 0; i < L; i++) s.insert(i);
	sort(V.rbegin(), V.rend());

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		auto [p, d] = V[i];
		auto it = s.upper_bound(d);
		if (it != s.begin())
		{
			it = prev(it);
			ans += p;
			s.erase(it);
		}
	}
	cout << ans << "\n";
}
