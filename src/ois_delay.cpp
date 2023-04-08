#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	fin >> N;
	
	vector < int > O;
	O.resize(N);
	for (int i = 0; i < N; i++)
	{
		fin >> O[i];
	}
	
	vector < int > D;
	D.resize(N);
	for (int i = 0; i < N; i++)
	{
		fin >> D[i];
	}
	
	int mi = 0;
	for (int i = 0; i < N; i++)
	{
		if (i - D[i] < mi)
		{
			fout << O[mi] << " ";
		}
		else
		{
			fout << O[i - D[i]] << " ";
			mi = i - D[i];
		}
	}
}