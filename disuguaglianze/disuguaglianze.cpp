#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	fin >> N;
	vector < int > V;
	V.resize(N);
	int lowest = 1;
	int highest = N;
	
	for (int i = 0; i < N - 1; i++)
	{
		char sign;
		fin >> sign;
		if(sign == '<')
		{
			V[i] = lowest;
			lowest++;
		}
		else //if (sign == '>')
		{
			V[i] = highest;
			highest--;
		}
	}
	V[N - 1] = lowest;
	
	for (int i = 0; i < N; i++)
	{
		fout << V[i] << " ";
	}
}