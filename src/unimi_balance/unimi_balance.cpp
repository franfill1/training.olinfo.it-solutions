#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < ll , ll > ii;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < vector < ii > > T;
ll ans = 0;

ll dfs(ll n)
{
	ll s = 0;
	ll ma = 0;
	ll t = T[n].size();
	
	for (ii ne : T[n])
	{
		ll temp = ne.second + dfs(ne.first);
		ma = max(ma, temp);
		s += temp;
	}
	
	ans += t * ma - s;
	return t * ma;
}

int main()
{
	ll N;
	fin >> N;
	T.resize(N);
	for (ll i = 1; i < N; i++)
	{
		ll el, w;
		fin >> el >> w;
		T[el].push_back(make_pair(i, w));
	}
	dfs(0);
	fout << ans;
}
