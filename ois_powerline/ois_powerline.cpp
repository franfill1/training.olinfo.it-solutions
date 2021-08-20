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
	
	vector < int > T(N);
	for (int i = 0; i < N; i++)
	{
		fin >> T[i];
	}
	
	int ans = 0;
	
	int lastM = N - 1;
	
	for (int i = N - 2; i >= 0; i--)
	{
		if(T[i] >= T[lastM])
		{
			lastM = i;
		}
		else
		{
			ans = max(ans, lastM - i);
		}
	}
	
	fout << ans;
	
	
	return 0;
}

