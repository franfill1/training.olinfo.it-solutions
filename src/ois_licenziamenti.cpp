#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair < int , int > ii;

int main()
{
	int N;
	fin >> N;
	
	vector < vector < int > > T(N);
	vector < int > C(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> C[i];
		int el;
		fin >> el;
		if (el != -1)
		{
			T[el].push_back(i);
		}
	}
	
	stack < ii > s;
	s.push(make_pair(0, C[0]));
	int ans = 0;
	while(!s.empty())
	{
		int n = s.top().first;
		int m = s.top().second;
		s.pop();
		if (C[n] > m)
		{
			ans++;
		}
		int nem = min(m, C[n]);
		
		for (int ne : T[n])
		{
			s.push(make_pair(ne, nem));
		}
	}
	fout << ans;
}
