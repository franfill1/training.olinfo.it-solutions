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
	
	vector < int > V(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> V[i];
	}
	
	int ans = V[N - 1];
	
	for (int i = 0; i < N; i++)
	{
		int temp = max(V[i] - V[0], V[N - 1] - V[i]);
		if (temp < ans)
		{
			ans = temp;
		}
	}
	
	fout << ans;
	
	return 0;
}

