#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef pair < int , int > ii;

int main()
{
	int N, M, V;
	fin >> N >> M >> V;
	int deltaH = (V * V) / (2 * 10);
	
	vector < int > H(N);
	vector < int > pot(N);
	for (int i = 0; i < N; i++)
	{
		fin >> H[i];
		pot[i] = H[i] + deltaH;
	}
	
	priority_queue < ii , vector < ii > , greater < ii > > pQ; 
	vector < int > ans(N);
	for (int i = 0; i < N; i++)
	{
		while(!pQ.empty() && pQ.top().first < H[i])
		{
			ans[pQ.top().second] = i-1;
			pQ.pop();
		}
		pQ.push(make_pair(pot[i], i));
	}
	while(!pQ.empty())
	{
		ans[pQ.top().second] = N-1;
		pQ.pop();
	}
	for (int i = 0; i < N; i++)
	{
		fout << ans[i] << " ";
	}
}
