#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef unsigned long long int ull;

int main()
{
	vector < int > values {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
	
	ull sum = 0;
	for (int i = 0; i < 15; i++)
	{
		ull el;
		fin >> el;
		sum += el * values[i];
	}
	
	vector < ull > ans;
	ans.resize(15);
	for (int i = 14; i >= 0; i--)
	{
		ans[i] = sum / values[i];
		sum = sum % values[i];
	}
	
	for (int i = 0; i < 15; i++)
	{
		fout << ans[i] << " ";
	}
}
