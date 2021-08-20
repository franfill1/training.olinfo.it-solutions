#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	int N;
	fin >> N;
	
	int dis[N];
	int prec = 0;
	for (int i = 0; i < N; i++)
	{
		int he;
		fin >> he;
		dis[i] = he - prec;
		prec = he;
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dis[i]);
	}
	
	fout << ans;
	
	return 0;
}

