#include <bits/stdc++.h>

#define MAXB 32
#define MAXM 110

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct edge
{
	int b, id;
	bool rev;
};

vector < bool > C;
vector < vector < edge > > g;
vector < edge > pa;

struct hasher
{
	int operator()(vector<int> const vec) const 
	{
		int seed = 0;
		int m = 1000000007;
		int b = 1000009;
		int p = 1;
		for(auto& i : vec) 
		{
			seed += (i * p) % m;
			seed %= m;
			p *= b;
			p %= m;
		}
		return seed;
	}
};

bool findPath()
{
	vector < bool > vis(g.size(), false);
	stack < int > q;
	q.push(g.size()-2);
	while(!q.empty())
	{
		int n = q.top();
		q.pop();
		for (edge ed : g[n])
		{
			int ne = ed.b;
			int c = C[ed.id] ^ ed.rev;
			if (!vis[ne] && c)
			{
				pa[ne] = {n, ed.id, !ed.rev};
				vis[ne] = true;
				if (ne == g.size() -1)
				{
					return true;
				}
				q.push(ne);
			}
		}
	}
	return false;
}

int maxFlow()
{
	pa.resize(g.size());
	int flow = 0;
	while(findPath())
	{
		flow++;
		int n = g.size()-1;
		while(n!=g.size()-2)
		{
			C[pa[n].id] = !C[pa[n].id];
			n = pa[n].b;
		}
	}
	return flow;
}

int main()
{
	int N, M, B;
	fin >> N >> M >> B;
	unordered_map < vector<int> , int , hasher > m;
	int eid = 0;
	g.resize(N+2);
	for (int i = 0; i < N; i++)
	{
		vector<int> C(M);
		int s = 0;
		for (int j = 0; j < M; j++)
		{
			fin >> C[j];
			s += C[j];
		}
		if (!m.count(C))
		{
			int id = m.size();
			m[C] = id;
		}
		int id = m[C];
		
		if (s % 2)
		{
			g[N].push_back({id, eid, false});
			g[id].push_back({N, eid, true});
			eid++;
		}
		else
		{
			g[N+1].push_back({id, eid, true});
			g[id].push_back({N+1, eid, false});
			eid++;
		}
		for (int j = 0; j < M; j++)
		{
			C[j]++;
			if (m.count(C))
			{
				int idb = m[C];
				if (s % 2)
				{
					g[id].push_back({idb, eid, false});
					g[idb].push_back({id, eid, true});
				}
				else
				{
					g[id].push_back({idb, eid, true});
					g[idb].push_back({id, eid, false});
				}
				eid++;
			}
			C[j]--;
			if (C[j] > 0)
			{
				C[j]--;
				if (m.count(C))
				{
					int idb = m[C];
					if (s % 2)
					{
						g[id].push_back({idb, eid, false});
						g[idb].push_back({id, eid, true});
					}
					else
					{
						g[id].push_back({idb, eid, true});
						g[idb].push_back({id, eid, false});
					}
					eid++;
				}
				C[j]++;
			}
		}
	}
	C.resize(eid, 1);
	
	fout << maxFlow();
}
