#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long ll;

int main()
{
	int T;
	fin >> T;
	for (int i = 0; i < T; i++)
	{
		ll a, b;
		fin >> a >> b;
		if (a > 0 && b > 0)
		{
			fout << "+\n";
		}
		else if ((a < 0 && b > 0) || (b < 0 && a > 0) || a == 0 || b == 0)
		{
			fout << "0\n";
		}
		else
		{
			ll range = abs(a - b) + 1;
			if (range % 2 == 1)
			{
				fout << "-\n";
			}
			else
			{
				fout << "+\n";
			}
		}
	}
}
