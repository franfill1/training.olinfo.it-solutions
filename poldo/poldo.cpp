#include<bits/stdc++.h>
using namespace std;

struct fenwick
{
	int N;
	vector < int > V;
	
	fenwick(int Ni) : N (Ni+1)
	{
		V.resize(N, 0);
	}

	int get(int k)
	{
		k++;
		int ans = 0;
		while(k)
		{
			ans = max(ans, V[k]);
			k -= k&-k;
		}
		return ans;
	}

	void set(int k, int x)
	{
		k++;
		while(k < N)
		{
			V[k] = max(V[k], x);
			k += k&-k;
		}
	}
};

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	fin >> N;

	vector < int > V(N);
	priority_queue < int > pq;
	unordered_map < int , int > enc;
	for (int i = 0; i < N; i++)
	{
		fin >> V[i];
		pq.push(V[i]);
	}

	while(!pq.empty())
	{
		int n = pq.top();
		while(!pq.empty() && pq.top() == n)
		{
			pq.pop();
		}
		enc[n] = enc.size();
	}
	
	int ans = 0;
	fenwick fen(N);
	for (int i = 0; i < N; i++)
	{
		int v = fen.get(enc[V[i]] - 1) + 1;
		ans = max(ans, v);
		fen.set(enc[V[i]], v);
	}
	fout << ans << "\n";
}
