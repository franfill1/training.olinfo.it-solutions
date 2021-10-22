#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
typedef long long ll;

struct segtree
{
	int n;
	vector < int > t;

	segtree(int in) 
	{
		n = 1;
		while(n < in) n *= 2;
		t.resize(n*2, 0);
	}

	void upd(int k, int v)
	{
		for (t[k+=n]+=v; k-1; t[k>>=1] += v);
	}

	int lower_bound(int c)
	{
		int k=1;
		while(k < n)
		{
			if (t[k*2] >= c) k = k*2;
			else 
			{
				c -= t[k*2];
				k = k*2+1;
			}
		}
		return k - n;
	}
};

int visita(int N, vector<int> &A, vector<int> &b, vector<int> &D, vector<int> &C) {
	vector < vector < int > > g(N);
	for (int i = 0; i < N-1; i++)
	{
		g[A[i]].emplace_back(b[i]); 
		g[b[i]].emplace_back(A[i]); 
	}

	vector < int > S = D;
	sort(S.begin(), S.end());

	vector < int > m(N);
	for (int i = 0; i < N; i++)
		m[i] = lower_bound(S.begin(), S.end(), D[i]) - S.begin();
	segtree seg(N);

	function<int(int , int, bool)> dfs; 
	vector < int > I(N, 0), P(N), dp(N, -1);
	vector < bool > B(N, 1);

	stack < int > s;
	s.push(0);
	while(!s.empty())
	{
		int x = s.top();
		int p = P[x];
		if (I[x] == 0) seg.upd(m[x], 1);
		else
		{
			if (dp[x] == -1) dp[x] = dp[g[x][I[x]-1]];
			if (B[x]) dp[x] = max(dp[x], dp[g[x][I[x]-1]]);
			else dp[x] = min(dp[x], dp[g[x][I[x]-1]]);
		}

		if (x != 0 && g[x].size() == 1) dp[x] = S[seg.lower_bound(C[x]+1)];

		if(I[x] < g[x].size() && g[x][I[x]] == P[x]) I[x]++;
		if (I[x] == g[x].size()) 
		{
			seg.upd(m[x], -1);
			s.pop();
		}
		else 
		{
			P[g[x][I[x]]] = x;
			B[g[x][I[x]]] = !B[x];
			s.push(g[x][I[x]++]);
		}
	}

	return dp[0];
}
