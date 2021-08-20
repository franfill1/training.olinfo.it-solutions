#include <bits/stdc++.h>
#define MAXN 500

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

bool C[2*MAXN +2][2*MAXN+2];
int pa[2*MAXN+2];
int N;

bool findPath()
{
	fill(pa, pa + N*2+2, -1);
	stack < int > q;
	q.push(0);
	while(!q.empty())
	{
		int n = q.top();
		q.pop();
		for (int ne = 0; ne < 2*N+2; ne++)
		{
			if (pa[ne] == -1 && C[n][ne])
			{
				pa[ne] = n;
				q.push(ne);
				if (ne == 2*N+1)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int maxFlow()
{
	int flow = 0;
	while(findPath())
	{
		int n = 2*N+1;
		while(n != 0)
		{
			C[pa[n]][n] = 0;
			C[n][pa[n]] = 1;
			n = pa[n];
		}
		flow++;
	}
	return flow;
}

int main()
{
	fin >> N;
	
	int D[N];
	for (int i = 0; i < N; i++)
	{
		fin >> D[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		C[0][i+1] = 1;
		C[i+N+1][2*N+1] = 1;
		for (int j = 0; j < N; j++)
		{
			int el;
			fin >> el;
			if (i != j && D[j] - D[i] >= el)
			{
				C[i+1][j+N+1] = 1;
			}
		}
	}
	
	fout << N - maxFlow() << "\n";
	
}