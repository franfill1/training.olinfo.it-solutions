#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	ios_base::sync_with_stdio(false);
	fin.tie(NULL);
	
	int N, M;
	
	fin >> N >> M;
	
	int pos[N]; 
	for (int i = 0; i < N; i++)
	{
		int K;
		fin >> K;
		K--;
		pos[K] = i;
	}
	
	for (int i = 0; i < M; i++)
	{
		int A, B;
		fin >> A >> B;
		A--;
		B--;
		
		
		int temp = pos[A];
		pos[A] = pos[B];
		pos[B] = temp;
	}
	
	for (int i = 0; i < N; i++)
	{
		if (pos[i] == 0)
		{
			fout << i + 1;
		}
	}
	
	return 0;
}

