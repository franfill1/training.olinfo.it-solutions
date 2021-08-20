#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef  pair < int , int > ii;
int inf = 1<<30;

int main()
{
	int N, A, B;
	fin >> N >> A >> B;
	
	vector < vector < ii > > g(N);
	for (int i = 0; i < A; i++)
	{
		int a, b;
		fin >> a >> b;
		a--;b--;
		g[a].push_back(make_pair(b, 0));
		g[b].push_back(make_pair(a, 0));		
	}
	
	for (int i = 0; i < B; i++)
	{
		int a, b;
		fin >> a >> b;
		a--;b--;
		g[a].push_back(make_pair(b, 1));
		g[b].push_back(make_pair(a, 1));
	}
	
	vector < int > D(N, inf);
	D[0] = 0;
	
	deque < int > d;
	d.push_front(0);
	
	while(!d.empty())
	{
		int n = d.front();
		d.pop_front();
		
		for (ii nep : g[n])
		{
			int ne = nep.first;
			int nd = D[n] + nep.second;
			if (nd < D[ne])
			{
				D[ne] = nd;
				if (nep.second)
				{
					d.push_back(ne);
				}
				else
				{
					d.push_front(ne);
				}
			}
		}
	}
	fout << D[N-1];
}
