#include <bits/stdc++.h>

const int inf = 1<<30;

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef pair < int , int > ii;
typedef pair < int , ii > iii;

int main()
{
	int N, M, C;
	fin >> N >> M >> C;
	
	vector < int > P(N);
	vector < vector < ii > > g(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> P[i];
	}
	
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		fin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
	}

	priority_queue < iii, vector < iii > , greater < iii > > pQ;
	
	vector < vector < int > > D(N, vector < int > (101, inf));
	for (int u = 0; u <= C; u++)
	{
		pQ.push(make_pair(P[0] / (1<<u), make_pair(0, C - u)));
		D[0][C - u] = P[0] / (1<<u);
	}
	int ans = 0;;
	while(!pQ.empty())
	{
		int d = pQ.top().first;
		int n = pQ.top().second.first;
		int c = pQ.top().second.second;

		pQ.pop();
		if (n == N-1)
		{
			ans = d;
			break;
		}
		else
		{
			for (ii nep : g[n])
			{
				int ne = nep.first;
				int nc = c + nep.second;
				for (int u = 0; u <= nc; u++)
				{
					int nd = max(d, P[ne] / (1<<u));
					if (nd < D[ne][nc - u])
					{
						D[ne][nc - u] = nd;
						pQ.push(make_pair(D[ne][nc - u], make_pair(ne, nc - u)));
					}
				}
			}
		}
	}
	fout << ans;
}
