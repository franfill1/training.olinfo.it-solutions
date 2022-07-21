#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector < vector < int > > g(N);
	vector < int > C(N);
	for (auto &c : C) cin >> c;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 1<<30;
	vector < bool > V(N);
	vector < int > T(N, -1), D(N);
	for (int i = 0; i < N; i++) if (!V[i])
	{
		queue < int > q, nq;
		V[i] = true;
		q.emplace(i);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for (auto y : g[x]) 
			{
				if (!V[y] && C[y] == C[x])
				{
					q.emplace(y);
					V[y] = true;
				}
				else if (C[y] != C[x])
				{
					if (T[x] != -1 && T[x] != C[y])
					{
						cout << "2\n";
						return 0;
					}
					T[x] = C[y];
					D[x] = 1;
				}
			}
			if (T[x] != -1) 
				nq.emplace(x);
		}
		bool brk = false;
		while(!nq.empty())
		{
			int x = nq.front();
			nq.pop();
			for (auto y : g[x]) if (C[y] == C[x] && T[y] != T[x])
			{
				if (T[y] != -1)
				{
					ans = min(ans, D[x]+D[y]+1);
					brk = true;
					break;
				}
				else
				{
					T[y] = T[x];
					D[y] = D[x]+1;
					nq.emplace(y);
				}
			}
			if (brk) 
				break;
		}
	}
	cout << (ans == 1<<30 ? -1 : ans) << "\n";
}
