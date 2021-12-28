#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	fin >> N;
	vector < int > V(2 * N);
	for (int i = 0; i < 2 * N; i++)
	{
		fin >> V[i];
	}
	sort(V.begin(), V.end());
	
	for (int i = 0; i < N; i++)
	{
		fout << V[i] << " ";
	}
	fout << "\n";
	for (int i = N; i < 2*N; i++)
	{
		fout << V[i] << " ";
	}
}
