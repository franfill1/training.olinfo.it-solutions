#include <bits/stdc++.h>

using namespace std;

struct node
{
	bool val;
	bool set;
	bool toSet;
};

struct segTree
{
	int N;
	vector < node > V;
	
	segTree(int NN)
	{
		N = NN;
		V.resize(N*2, {0, 0, 0});
	}
	
	void propagate(int n)
	{
		if(V[n].set)
		{
			V[n].val = V[n].toSet;
			
			if (n < N)
			{
				V[n*2].set = true;
				V[n*2].toSet = V[n].toSet;
				
				V[n*2+1].set = true;
				V[n*2+1].toSet = V[n].toSet;
			}
			V[n].set = false;
		}
	}
	
	void setRange(int a, int b, bool val, int k = 1, int x = 0, int y = -1)
	{
		if (y == -1) y = N-1;
		
		if (a <= x && y <= b)
		{
			V[k].set = true;
			V[k].toSet = val;
		}
		
		propagate(k);
		
		if (a > y || b < x) return;
		if (a <= x && y <= b) return;
		
		int d = (x+y)/2;
		setRange(a, b, val, k*2, x, d);
		setRange(a, b, val, k*2+1, d+1, y);
	}
	
	int get(int n, int k = 1, int x = 0, int y = -1)
	{
		if (y == -1) y = N-1;
		
		propagate(k);
		
		if (n == x && n == y)
		{
			return V[k].val;
		}
				
		if (n < x || n > y)
		{
			return -1;
		}
		
		int d = (x+y)/2;
		int c1 = get(n, k*2, x, d);
		int c2 = get(n, k*2+1, d+1, y);
				
		if (c1 != -1) return c1;
		else return c2;
	}
};

vector < int > idToI;
vector < int > siz;
vector < vector < int > > g;

int dfs(int n, int &i)
{
	idToI[n] = i;
	i++;
	siz[idToI[n]] = 1;
	for (int ne : g[n])
	{
		siz[idToI[n]] += dfs(ne, i);
	}
	return siz[idToI[n]];
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
	int D, P, Q;
	cin >> D >> P >> Q;
	g.resize(D + P);
	int el;
	cin >> el;
	for (int i = 1; i < D + P; i++)
	{
		cin >> el;
		g[el].push_back(i);
	}
	idToI.resize(D+P);
	siz.resize(D + P);
	int aa = 0;
	dfs(0, aa);
	
	segTree seg(1<<20);
	
	while(Q--)
	{
		int T, n;
		cin >> T >> n;
		if (T == 2)
		{
			cout << seg.get(idToI[n]) << "\n";
		}
		else
		{
			seg.setRange(idToI[n], idToI[n] + siz[idToI[n]]-1, T);
		}
	}
}
