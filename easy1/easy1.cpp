#include <bits/stdc++.h>

using namespace std;

int main ()
{
	ifstream fin;
	fin.open("input.txt");
	ofstream fout;
	fout.open("output.txt");
	
	
	int N;
	fin >> N;
	
	int ans = -1000;
	for (int i = 0; i < N; i++)
	{
		int el;
		fin >> el;
		if(el > ans)
		{
			ans = el;
		}
	}
	
	fout << ans;
	
	return 0;
}

