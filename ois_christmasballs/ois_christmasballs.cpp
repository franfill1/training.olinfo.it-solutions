#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > g;
vector < int > C;
vector < map < int , int > > subtree;
vector < int > most, cnt;

int calc(int x)
{
	subtree[x][C[x]] = 1;
	most[x] = 1;
	cnt[x] = 1;
	int ans = 1;
	for (int y : g[x])
	{
		ans = max(ans, calc(y));
		if (subtree[y].size() > subtree[x].size())
		{
			swap(subtree[y], subtree[x]);
			most[x] = most[y];
			cnt[x] = cnt[y];
		}
	}

	for (int y : g[x])
	{
		for (auto [col, occ] : subtree[y])
		{
			subtree[x][col] += occ;
			if (subtree[x][col] > most[x]) 
			{
				cnt[x] = 0;
				most[x] = subtree[x][col];
			}
			if (subtree[x][col] == most[x]) 
			{
				cnt[x]++;
			}
		}
	}
	return ans = max(ans, cnt[x]);
}

int main()
{
	int N;
	cin >> N;
	g.resize(N);
	C.resize(N);
	subtree.resize(N);
	most.resize(N);
	cnt.resize(N);
	for (int &c : C) cin >> c;
	for (int i = 1; i < N; i++)
	{
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	cout << calc(0) << "\n";
}

