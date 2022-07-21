#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	int N, H[N+2], ans=0;
	cin >> N;
	H[0] = H[N+1] = 1<<30;
	for (int i = 1; i <= N; i++)
		cin >> H[i];
	stack < pair < int , int > > s;
	s.emplace(0, 0);
	for (int i = 1; i <= N+1; i++)
	{
		while(H[s.top().first] < H[i]) 
		{
			auto [l, r] = s.top();
			s.pop();
			if (l == r) continue;
			int ll = s.top().second, rr = i;
			int ls = min(l - ll, rr - l - 1);
			int rs = min(rr - r, r - ll - 1);
			ans = max(ans, r - l - 1 + ls + rs);
		}
		if (H[s.top().first] == H[i])
			s.top().second = i;
		else
			s.emplace(i, i);
	}
	cout << ans << "\n";
}
