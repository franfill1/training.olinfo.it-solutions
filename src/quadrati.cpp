#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef unsigned long long int ull;

int main()
{
	ull a, b;
	fin >> a >> b;
	
	int sB = sqrt(b);
	int sA = sqrt(a);
	int ans = sB - sA;
	
	if(sqrt(a) == (int)sqrt(a))
	{
		ans++;
	}
	fout << ans;
}