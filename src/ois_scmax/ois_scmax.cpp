#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct fenwick
{
	vector < int > V;
	fenwick(int N)
	{
		V.resize(N+1, 0);
	}
	
	int getMax(int k)
	{
		int ans = 0;
		while(k > 0)
		{
			ans = max(ans, V[k]);
			k -= k&-k;
		}
		return ans;
	}
	
	void update(int k, int x)
	{
		while(k < V.size())
		{
			V[k] = max(V[k], x);
			k += k&-k;
		}
	}
};

int main()
{
	int N;
	fin >> N;
	fenwick fen(N);
	
	vector < int > P(N);
	vector < int > C(N+1);
	for (int i = 0; i < N; i++)
	{
		fin >> P[i];
	}
	for (int i = 1; i < N+1; i++)
	{
		fin >> C[i];
	}
	
	vector < int > M(N+1, 0);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int a = max(fen.getMax(P[i]-1), M[P[i]])+1;
		M[C[P[i]]] = max(M[C[P[i]]], a);
		ans = max(ans, a);
		fen.update(P[i], a);
	}
	fout << ans;
}
