#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	
	queue < int > q;
	unordered_map < int , int > dist;
	q.push(N);
	dist[N] = 0;
	
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		if (n == 0)
		{
			
			break;
		}
		
		int nxt = n + 1;
		if (dist.count(nxt) == 0)
		{
			dist[nxt] = dist[n]+1;
			q.push(nxt);
		}
		nxt = n - 1;
		if (dist.count(nxt) == 0)
		{
			dist[nxt] = dist[n]+1;
			q.push(nxt);
		}
		nxt = n*2;
		if (dist.count(nxt) == 0)
		{
			dist[nxt] = dist[n]+1;
			q.push(nxt);
		}
		
		int p = 3;
		while(n % p == 0)
		{
			nxt = n/p;
			if (dist.count(nxt) == 0)
			{
				dist[nxt] = dist[n]+1;
				q.push(nxt);
			}
			p *= 3;
		}
	}
	fout << dist[0];
}
