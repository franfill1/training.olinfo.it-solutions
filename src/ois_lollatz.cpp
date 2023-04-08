#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	
	vector < bool > vis(10, false);
	bool ok = true;
	while(int c = N % 10)
	{
		N *= c-1;
		N /= 2;
		
		
		if (vis[c])
		{
			ok = false;
			break;
		}
		vis[c] = true;
	}
	if(ok) fout << N;
	else fout << -1;
}
