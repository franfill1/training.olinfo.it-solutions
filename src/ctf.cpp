#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long ll;

int main()
{
	int Q;
	fin >> Q;
	while(Q--)
	{
		ll N;
		fin >> N;
		ll p = 1;
		while(p <= N)
		{
			p<<=1;
		}
		p>>=1;
		ll l = N-p;
		fout << 2*l+1 << "\n";
	}
}
