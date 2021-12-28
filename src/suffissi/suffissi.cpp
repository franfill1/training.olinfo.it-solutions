#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, Q;
	fin >> N >> Q;
	unordered_set < int > s;
	vector < int > V(N);
	vector < int > suf(N);
	for (int i = 0; i < N; i++)
	{
		fin >> V[i];
	}
	for (int i = N-1; i >= 0; i--)
	{
		s.insert(V[i]);
		suf[i] = s.size();
	}
	while(Q--)
	{
		int q;
		fin >> q;
		q--;
		fout << suf[q] << "\n";
	}
}
