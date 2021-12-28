#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N, L, U;
	
	fin >> N >> L >> U;
	
	int minGroup = ceil( (double) N / (double) U );
	int maxGroup = N/L;
	
	if (maxGroup >= minGroup)
	{
		fout << minGroup;
	}
	else
	{
		fout << -1;
	}
}
