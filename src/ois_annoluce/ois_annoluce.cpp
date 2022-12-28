#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long ll;

int main()
{
	int N;
	fin >> N;
	vector < ll > V(N);
	for (int i = 0; i < N; i++)
	{
		ll X, Y, Z;
		fin >> X >> Y >> Z;
		V[i] = X*X + Y*Y + Z*Z;
	}
	sort(V.begin(), V.end());
	int Q;
	fin >> Q;
	 
	while(Q--)
	{
		ll D;
		fin >> D;
		D *= D;
		int a = 0, b = N;
		while(a != b-1)
		{
			int m = (a+b)/2;
			if (V[m] > D)
			{
				b = m;
			}
			else
			{
				a = m;
			}
		}
		fout << (a+1) << "\n";
	}
}
