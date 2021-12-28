#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef pair < int , int > ii;

const int inf = 1<<30;

int main()
{
	int N;
	fin >> N;
	vector < vector < ii > > g(N);
	
	for (int i = 0; i < N; i++)
	{
		int p;
		fin >> p;
		g[i].push_back(make_pair(p, 0));
		if (i > 0)
		{
			g[i].push_back(make_pair(i-1, 1));
		}
		if (i < N-1)
		{
			g[i].push_back(make_pair(i+1, 1));
		}
	}
	
	vector < int > D(N, inf);
	D[0] = 0;
	
	deque < int > dq;
	dq.push_front(0);
	
	while(!dq.empty())
	{
		int n = dq.front();
		dq.pop_front();
		
		for (ii nep : g[n])
		{
			int ne = nep.first;
			int w = nep.second;
			int nd = D[n] + w;
			
			if (nd < D[ne])
			{
				D[ne] = nd;
				if (w)
				{
					dq.push_back(ne);
				}
				else
				{
					dq.push_front(ne);
				}
			}
		}
	}
	
	fout << D[N-1];
}
