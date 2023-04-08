#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long ll;

struct frag
{
	string s;
	ll j;
	ll k;
};

bool operator < (frag a, frag b)
{
	return a.j < b.j;
}

bool com (string a, string b, ll s)
{
	for (ll i = s; i < a.length() && (i - s) < b.length(); i++)
	{
		if (a[i] != '?' && b[i - s] != '?' && a[i] != b[i - s])
		{
			return false;
		}
	}
	return true;
}

bool solve(ll M)
{
	vector < frag > DNA;
	for (ll i = 0; i < M; i++)
	{
		ll j; ll k; string s;
		fin >> j >> k >> s;
		DNA.push_back({s, j, k});
	}
	sort(DNA.begin(), DNA.end());
	
	vector < vector < ll > > g(M);
	
	for (ll i = 0; i < M; i++)
	{
		for (ll z = i+1; z < M && DNA[z].j < DNA[i].j + DNA[i].k; z++)
		{
			if (!com(DNA[i].s, DNA[z].s, DNA[z].j - DNA[i].j))
			{
				g[i].push_back(z);
				g[z].push_back(i);
			}
		}
	}
	
	vector < ll > col(M, -1);
	for (ll i = 0; i < M; i++)
	{
		if (col[i] == -1)
		{
			queue < ll > q;
			q.push(i);
			col[i] = 0;
			while(!q.empty())
			{
				ll n = q.front();
				q.pop();
				for (ll ne : g[n])
				{
					if (col[ne] == -1)
					{
						col[ne] = 1 - col[n];
						q.push(ne);
					}
					else if (col[ne] == col[n])
					{
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

int main()
{
	ll N;
	fin >> N;
	vector < ll > M(N);
	for (ll i = 0; i < N; i++)
	{
		fin >> M[i];
	}
	for (ll i = 0; i < N; i++)
	{
		fout << solve(M[i]) << "\n";
	}
}
