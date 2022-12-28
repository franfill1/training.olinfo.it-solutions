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
	vector < int > P(N);
	vector < int > C(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> V[i];
	}
	for (int i = 0; i < N; i++)
	{
		fin >> P[i];
	}
	for (int i = 0; i < N; i++)
	{
		fin >> C[i];
	}
	
	int ans = 0;
	int mon = 0;
	
	int pri = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (V[i] - P[i] > C[i])
		{
			if (mon >= P[i])
			{
				mon -= P[i];
			}
			else
			{
			 	ans += P[i] - mon;
			 	mon = 0;
			}
			pri += V[i];
		}
		else
		{
			mon += C[i];
		}
	}
	
	fout << mon - ans + pri << " ";
	fout << ans;
	
	return 0;
}

