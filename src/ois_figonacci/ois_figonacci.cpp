#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	int N, M;
	fin >> N >> M;
	
	vector < int > G(N  +1);
	
	G[0] = -1;
	G[1] = 0;
	
	int sum = -1;
	
	for (int i = 2; i < N + 1; i++)
	{
		G[i] = 0;
		G[i] += ((G[i - 1] * ((i - 1) % M) - sum) % M + M) % M;
		sum += G[i - 1];
		sum = (sum % M + M) % M;
	}
	
	fout << G[N];
	
	return 0;
}

