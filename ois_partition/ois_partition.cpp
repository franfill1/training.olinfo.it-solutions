#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int sum(vector < int > &tree, int k)
{
	int ans = 0;
	while(k > 0)
	{
		ans += tree[k];
		k -= k&-k;
	}
	return ans;
}

void add(vector < int > &tree, int k, int x)
{
	while(k < tree.size())
	{
		tree[k] += x;
		k += k&-k;
	}
}

int main()
{
	int N;
	fin >> N;
	
	vector < int > v(N+1);
	for (int i = 1; i <= N; i++)
	{
		fin >> v[i];
	}
	
	vector < int > ans(N+1, 0);
	
	vector < int > tree1(N+1, 0);
	for (int i = 1; i <= N; i++)
	{
		ans[i] += sum(tree1, N) - sum(tree1, v[i]);
		add(tree1, v[i], 1);
	}
	
	vector < int > tree2(N+1, 0);
	for (int i = N; i >= 1; i--)
	{
		ans[i] += sum(tree2, v[i] - 1);
		add(tree2, v[i], 1);
	}
	
	for (int i = 1; i <= N; i++)
	{
		fout << ans[i] << " ";
	}
	
}
