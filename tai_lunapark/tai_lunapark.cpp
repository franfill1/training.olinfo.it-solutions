#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int a, b;
	int w;
	edge(int aa, int bb, int ww)
	{
		a = aa; b = bb; w = ww;
	}
};

bool operator < (edge e1, edge e2)
{
	return e1.w < e2.w;
}

void sort(vector < edge > &V)
{
	vector < vector < edge > > O(1001);
	for (edge e : V)
	{
		O[e.w].push_back(e);
	}
	int c = 0;
	for (int i = 1000; i >= 0; i--)
	{
		for (edge e : O[i])
		{
			V[c] = e;
			c++;
		}
	}
}

vector < int > p;

int find(int x)
{
	if (x == p[x])
	{
		return x;
	}
	else
	{
		return x = find(p[x]);
	}
}

int progetta(int N, int M, int K, vector<int> &A, vector<int> &B, vector<int> &W)
{
	p.resize(N);
	vector < int > size(N, 1);
	for (int i = 0; i < N; i++)
	{ 
		p[i] = i;
	}
	
	vector < edge > V;
	for (int i = 0; i < M; i++)
	{
		V.push_back({A[i], B[i], W[i]});
	}
	sort(V);
	
	int ans = 0;
	int C = 0;
	for (int i = 0; C < N-K; i++)
	{
		int a = find(V[i].a);
		int b = find(V[i].b);
		if (a != b)
		{
			C++;
			ans += V[i].w;
			if (size[a] > size[b])
			{
				size[a] += size[b];
				p[b] = a;
			}
			else
			{
				size[b] += size[a];
				p[a] = b;
			}
		}
	}
	return ans;
}