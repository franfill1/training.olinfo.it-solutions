#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef pair < int , int > ii;

int getCost(ii a, ii b)
{
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	int cost = dx * dx + dy * dy;
	return cost;
}

int main()
{
	int N;
	fin >> N;
	
	vector < ii > T;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			fin >> c;
			if (c == 'T')
			{
				T.push_back({i, j});
			}
		}
	}
	N = T.size();
	
	vector < int > D(N, 1<<30);
	D[0] = 0;
	
	vector < bool > vis(N, false);
	
	int ans = 0;
	int temp = N;
	for (int i = 0; i < N; i++)
	{
		int nmin = -1;
		for (int n = 0; n < N; n++)
		{
			if (!vis[n] && (nmin == -1 || D[n] < D[nmin]))
			{
				nmin = n;
			}
		}
		int n = nmin;
		ans += D[n];
		
		for(int ne = 0; ne < N; ne++)
		{
			int w = getCost(T[n], T[ne]);
			if(w < D[ne])
			{
				D[ne] = w;
			}
		}
		vis[n] = true;
	}
	fout << ans;
	
}
