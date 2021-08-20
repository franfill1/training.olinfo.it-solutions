#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	ull N;
	fin >> N;
	
	vector < pair < ull , ull > > v(N);
	
	ull ans = 0;
	
	ull num = 0, den = 0;
	
	for (ull i = 0; i < N; i++)
	{
		fin >> v[i].first;
		fin >> v[i].second;
		num += v[i].first;
		den += v[i].second;
	}
	
	for (ull i = 1; i < N; i++)
	{
		if ((num - v[i].first) * (den - v[ans].second) > (num - v[ans].first) * (den - v[i].second))
		{
			ans = i;
		}
	}
	
	fout << ans;
		
	return 0;
}

