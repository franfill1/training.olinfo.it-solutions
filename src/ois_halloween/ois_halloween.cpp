#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

typedef unsigned long long int ull;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	ull N, M;
	
	fin >> N >> M;
	
	ull bamb[N]; 
	ull sum = 0;
	for (ull i = 0; i < N; i++)
	{
		ull b;
		fin >> b;
	    bamb[i] = b;
	    sum += b;
	} 
	
	M = M % sum;
	
	if (M == 0)
	{
		fout << N - 1;
	}
	
	else
	{
		ull i = 0;
		while (M > 0)
		{
			if (bamb[i] >= M)
			{
				M = 0;
			}
			else
			{
				M -= bamb[i];
				i++;
			}
		}
		
		fout << i << "\n";
	}
	
	return 0;
}

