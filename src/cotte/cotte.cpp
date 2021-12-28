#include<bits/stdc++.h>
using namespace std;

struct fenwick
{
	int n;
	vector < int > t;

	fenwick(int _n) : n(_n +1)
	{
		t.resize(n, 0);
	}

	void set(int k, int v)
	{
	    k++;
	    while(k < n)
	    {
	        t[k] = max(t[k], v);
	        k += (k&-k);
	    }
	}

	int get(int k)
	{
		int ans = 0;
		k++;
		while(k != 0)
		{
		    ans = max(ans, t[k]);
		    k -= k&-k;
		}
		return ans;
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int M, F;
	cin >> M >> F;
	int C;
	cin >> C;
	vector < vector < int > > g(M);
	for (int i = 0; i < C; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
	}

	fenwick fen(F);

	for (int i = 0; i < M; i++)
	{
	    sort(g[i].rbegin(), g[i].rend());
		for (int f : g[i])
		{
			fen.set(f, fen.get(f-1)+1);
		}
	}
	cout << fen.get(F-1)*2 << "\n";
}
