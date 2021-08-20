#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector < vector < int > > g;
vector < bool > vis;
vector < int > so;
vector < int > H;
vector < int > temp;

void topoSort(int n)
{
	temp[n] = H[n];
	for (int ne : g[n])
	{
		if (!vis[ne])
		{
			vis[ne] = true;
			topoSort(ne);
		}
		temp[n] = max(temp[n], temp[ne] + H[n]);
	}
	so.push_back(n);
}

main(){
	int N;
	fin >> N;
	
	g.resize(N); vis.resize(N, false); so.resize(0); H.resize(N); temp.resize(N);
	
	vector < vector < int > > t(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> H[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		int k;
		fin >> k;
		for (int j = 0; j < k; j++)
		{
			int el;
			fin >> el;
			g[i].push_back(el);
			t[el].push_back(i);
		}
	}
		
	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			topoSort(i);
		}
	}
	
	int T = 0;
	for (auto t : temp)
	{
		T = max(T, t);
	}
		
	vector < int > ans(N);
	for (int i = so.size() - 1; i >= 0; i--)
	{
		int n = so[i];
		int a = T - H[n];
		for (auto ne : t[n])
		{
			a = min(a, ans[ne] - H[n]);
		}
		ans[n] = a;
	}
	
	for (int i = 0; i < N; i++)
	{
		fout << ans[i] << " ";
	}
}

