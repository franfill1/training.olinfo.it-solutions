#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	vector < int > A(N); //ad ogni computer la sua posizione
	for (int i = 0; i < N; i++)
	{
		A[i] = i;
	}
	
	//A[4] è la posizione del PC4
	//A[6] è la posizione del PC6
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		fin >> a >> b;
		int temp = A[a];
		A[a] = A[b];
		A[b] = temp;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (A[i] == 0)
		{
			fout << i;
		}
	}
}
