#include <bits/stdc++.h>

using namespace std;

struct segTree
{
	vector < int > value;
	vector < int > mode;
	vector < int > lazy;
		
	int N;
	
	segTree(int NN)
	{
		N = NN;
		value.assign(2*N, 0);
		mode.assign(2*N, 0);
		lazy.assign(2*N, 0);
		
		for (int i = 0; i < N; i++)
		{
			mode[i + N] = i;
		}
		for (int i = N-1; i > 0; i--)
		{
			mode[i] = mode[i*2];
		}
	}
	
	void propagate(int n)
	{
		value[n] += lazy[n];
		if (n*2 < 2*N)
		{
			lazy[n*2] += lazy[n];
			lazy[n*2+1] += lazy[n];
		}
		lazy[n] = 0;
	}
	
	void add(int a, int b, int val, int k = 1, int x = 0, int y = -1)
	{
		if (y == -1) y = N-1;
		
		if (a <= x && y <= b)
		{
			lazy[k] += val;
		}
		
		propagate(k);
		
		if (b < x || a > y) return;
		if (a <= x && y <= b) return;

		int d = (x+y) / 2;
		add(a, b, val, k*2, x, d);
		add(a, b, val, k*2+1, d+1, y);
		
		if (value[k*2] >= value[k*2+1])
		{
			mode[k] = mode[k*2];
			value[k] = value[k*2];
		}
		else
		{
			mode[k] = mode[k*2+1];
			value[k] = value[k*2+1];
		}
	}
	
	int getMode()
	{
		return mode[1];
	}
	int getVal()
	{
		return value[1];
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N;
	cin >> N;
	segTree seg(262144);
	
	vector < int > F(N);
	for (int i = 0; i < N; i++)
	{
		cin >> F[i];
	}
	
	seg.add(F[0], F[0], 1);

	for (int i = 1; i < N; i++)
	{
		if (F[i] > F[i-1])
		{
			seg.add(F[i-1] + 1, F[i], 1);
		}
		else
		{
			seg.add(F[i], F[i-1] - 1, 1);
		}
	}

	int Q;
	cin >> Q;
	while(Q--)
	{
		int i, nv;
		cin >> i >> nv;
		if (i > 0)
		{
			seg.add(min(F[i]+1, F[i-1]), max(F[i]-1, F[i-1]), -1);
		}
		if (i < N-1)
		{
			seg.add(min(F[i]+1, F[i+1]), max(F[i]-1, F[i+1]), -1);
		}
		seg.add(F[i], F[i], -1);
		
		F[i] = nv;

		if (i > 0)
		{
			seg.add(min(F[i]+1, F[i-1]), max(F[i]-1, F[i-1]), 1);
		}
		if (i < N-1)
		{
			seg.add(min(F[i]+1, F[i+1]), max(F[i]-1, F[i+1]), 1);
		}
		seg.add(F[i], F[i], 1);
		cout << seg.getMode() << " " << seg.getVal() << "\n";
	}
}
