#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < int > K;
int N, T;

bool isPossible(int B)
{
	int c = 1;
	int l = K[0];
	for (int i = 1; i < N; i++)
	{
		if (K[i] - l >= B)
		{
			c++;
			l = K[i];
			
			if (c == T)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	fin >> N >> T;
	K.resize(N);
	for (int i = 0; i < N; i++)
	{
		fin >> K[i];
	}
	int a = 0, b = K[N-1] - K[0] + 1;
	while(a != b-1)
	{
		int m = (a + b) / 2;
		if(isPossible(m))
		{
			a = m;
		}
		else
		{
			b = m;
		}
	}
	fout << a << "\n";
}
