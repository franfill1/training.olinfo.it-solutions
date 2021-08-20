#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < vector < int > > t;

vector < int > tree;

vector < int > idToi;
vector < int > s;

vector < int > val;

int dfs(int n, int i)
{
	idToi[n] = i;
	s[idToi[n]] = 0;
	for (int ne : t[n])
	{
		int temp = dfs(ne, i+1);
		i += temp;
		s[idToi[n]] += temp;
	}
	return s[idToi[n]] + 1;
}

int sum(int k)
{
	int ans = 0;
	while(k > 0)
	{
		ans += tree[k];
		k -= k&-k;
	}
	return ans;
}

void add(int k, int x)
{
	while(k < tree.size())
	{
		tree[k] += x;
		k += k&-k;
	}
}

int main()
{
	int N, M;
	fin >> N >> M;
	t.resize(N);
	tree.resize(N+1);
	
	idToi.resize(N);
	s.resize(N+1);
	
	val.resize(N);
	
	fin >> val[0];
	for (int i = 1; i < N; i++)
	{
		int el;
		fin >> val[i] >> el;
		el--;
		t[el].push_back(i);
	}
	
	dfs(0, 1);
	
	for (int id = 0; id < N; id++)
	{
		int i = idToi[id];
		add(i, val[id]);
		add(i+1, -val[id]);
	}
	
	for (int i = 0; i < M; i++)
	{
		char c;
		fin >> c;
		if (c == 'p')
		{
			int id, x;
			fin >> id >> x;
			id--;
			
			int k0 = idToi[id];
			
			int k1 = k0 + s[k0];
			k0++;
			k1++;
			
			add(k0, x);
			add(k1, -x);
		}
		else
		{
			int id;
			fin >> id;
			id--;
						
			fout << sum(idToi[id]) << "\n";
		}
	}
}
