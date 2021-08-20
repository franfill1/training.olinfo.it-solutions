#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#define MAXN 10000

using namespace std;

#ifdef _WIN32
inline int getchar_unlocked() { return _getchar_nolock(); }
inline void putchar_unlocked(char c) { _putchar_nolock(c); }
#endif
inline __attribute__((always_inline)) int fast_read_int()
{
    int c, n = 0;
    do
    {
        c = getchar_unlocked();
    } while (c < '0' || c > '9');
    do
    {
        n = (n << 3) + (n << 1) + (c - '0');
        c = getchar_unlocked();
    } while (c >= '0' && c <= '9');
    return n;
}

inline __attribute__((always_inline)) bool fast_read_bool()
{
    int c;
    do
    {
        c = getchar_unlocked();
    } while (c != '0' && c != '1');
    return c == '1';
}

struct edge
{
	int b, id;
};

bool C[MAXN*3];
bool vis[MAXN*2+2];
edge pa[MAXN*2+2];

int N;
vector < vector < edge > > g;

bool findPath()
{
	fill(vis, vis + g.size(), false);
	
	stack < int > q;
	q.push(0);
	while(!q.empty())
	{
		int n = q.top();
		q.pop();
		for (edge ed : g[n])
		{
			int ne = ed.b;
			int c = C[ed.id]^(ne < n);
			assert(c >= 0);
			if (!vis[ne] && c)
			{
				pa[ne] = {n, ed.id};
				
				if (ne == g.size()-1)
				{
					return true;
				}
				vis[ne] = true;
				q.push(ne);
			}
		}
	}
	return 0;
}

int maxFlow()
{
	int flow = 0;
	while(findPath())
	{
		flow++;
		int n = g.size()-1;
		while(n != 0)
		{
			C[pa[n].id] = !C[pa[n].id];
			n = pa[n].b;
		}
	}
	return flow;
}

int main()
{
	N = fast_read_int();
	
	vector < pair < int , int > > input;
	vector < int > rs(N, -1), cs(N, -1);
	int cr = 0, cc = 0;
	for (int i = 0; i < N; i++)
	{
		int r = fast_read_int(), c = fast_read_int();
		r--; c--;
		input.push_back({r, c});
		if (rs[r] == -1)
		{
			rs[r] = cr;
			cr++;
		}
		if (cs[c] == -1)
		{
			cs[c] = cc;
			cc++;
		}
	}
	
	int id = 0;
	g.resize(cr + cc + 2);
	fill(C, C + cr + cc + N, true);
	for (int i = 0; i < N; i++)
	{			
		int r = rs[input[i].first], c = cs[input[i].second];
		g[r+1].push_back({cr+c+1, id});
		g[cr+c+1].push_back({r+1, id});
		id++;
	}
	
	for (int i = 0; i < cr; i++)
	{
		g[0].push_back({i+1, id});
		g[i+1].push_back({0, id});
		id++;
	}
	
	for (int i = 0; i < cc; i++)
	{
		g[cr+i+1].push_back({cr+cc+1, id});
		g[cr+cc+1].push_back({cr+i+1, id});
		id++;
	}
	
	cout << maxFlow();
}