#include <bits/stdc++.h>

#define maxN 200000

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long int ll;

vector < vector < ll > > ans;


void dfs(vector < vector < ll > > &t, vector < ll > &k, ll n, ll prev)
{	
    if (t[n].size()==1 && n != 0)
    {
        ans[n][0] = k[n];
        ans[n][1] = 0;
        return;
    }
    
	ans[n][1] = -1000000000000000000ll;
	ans[n][0] = k[n];
	
	for(auto x : t[n])
	{
		if (x != prev)
		{
			dfs(t, k, x, n);
			ll None = max(ans[n][0] + ans[x][1] - k[n], ans[n][1] + ans[x][0]);
			ll Nzero = max(ans[n][0] + ans[x][0], ans[n][1] + ans[x][1] + k[n]);
			ans[n][1] = None;
			ans[n][0] = Nzero;
		}
	}
	return;
}

int main()
{
	ll N;
	fin >> N;
	vector < vector < ll > > g(N, vector < ll > (0));
	for (ll i = 0; i < N-1; i++)
	{
		ll a, b;
		fin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector < ll > k(N);
	for (ll i = 0; i < N; i++)
	{
		fin >> k[i];
	}
	
	ans.resize(N, vector < ll > (2, 0));
	dfs(g, k, 0, 0);
	fout << max(ans[0][0], ans[0][1]);
}