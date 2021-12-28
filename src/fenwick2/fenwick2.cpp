#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < int > tree;

int M = 1000000007;

int sum(int k)
{
	int ans = 0;
	while(k > 0)
	{
		ans += tree[k];
		ans %= M;
		k -= k&-k;
	}
	return ans;
}

void add(int k, int x)
{
	while(k < tree.size())
	{
		tree[k] += x;
		tree[k] %= M;
		k += k&-k;
	}
}

int main()
{
	int N;
	fin >> N;
	
	vector < pair < int , int > > v(N);
	vector < int > memo(N+1, 0);
	tree.resize(N+1, 0);
	for (int i = 0; i < N; i++)
	{
		int el;
		fin >> el;
		v[i] = {el, i+1};
	}
	
	sort(v.begin(), v.end());
	
	vector < vector < int > > q;
	int el = -1;
	for (int i = 0; i < N; i++)
	{
		if (v[i].first != el)
		{
			vector < int > n;
			q.push_back(n);
			el = v[i].first;
		}
		q.back().push_back(v[i].second);
	}
	
	for (int i = 0; i < q.size(); i++)
	{
		for (int j = 0; j < q[i].size(); j++)
		{
			memo[q[i][j]] = sum(q[i][j]) + 1;
			memo[q[i][j]] %= M;
		}
		
		for (int j = 0; j < q[i].size(); j++)
		{
			add(q[i][j], memo[q[i][j]]);
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= N; i++)
	{
		ans += memo[i];
		ans %= M;
	}
	fout << ans;
}
