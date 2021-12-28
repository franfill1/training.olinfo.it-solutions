#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main ()
{
	int N;
	fin >> N;
	vector < char > V;
	V.resize(N + 1);
	V[0] = 'n';
	
	for (int i = 1; i < N + 1; i++)
	{
		fin >> V[i];
	}
	
	int ansI = 0;
	for(int i = 1; i < N + 1; i++)
	{
		if ((V[i] == 'i' || V[i] == 'I') && (V[i - 1] == 'n' || V[i - 1] == 'N'))
		{
			ansI++;
		}
	}
	
	int ansB = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if((V[i] == 'N' || V[i] == 'I') && (V[i - 1] == 'n' || V[i - 1] == 'i'))
		{
			ansB++;
		}
	}
	
	fout << ansI + ansB;
}

