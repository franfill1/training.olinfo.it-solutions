#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	
	int a, b;
	fin >> a;
	int ans = 0;
	for (int i = 1; i < N; i++)
	{
		fin >> b;
		ans = max(ans, abs(a - b));
		a = b;
	}
	fout << ans;
}
