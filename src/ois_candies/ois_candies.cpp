#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int N;
	cin >> N;
	vector < int > S(N);
	for (auto &s : S)
		cin >> s;
	sort(S.begin(), S.end());
	ll ans = 1;
	int c = 1;
	for (int i = 1; i < N; i++)
	{
		if (S[i] != S[i-1])
			c++;
		ans += c;
	}
	cout << ans << "\n";
}
